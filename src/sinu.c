/* mpfr_sinu -- sinu(x) = sin(2*pi*x/u)

Copyright 2020 Free Software Foundation, Inc.
Contributed by the AriC and Caramba projects, INRIA.

This file is part of the GNU MPFR Library.

The GNU MPFR Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or (at your
option) any later version.

The GNU MPFR Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the GNU MPFR Library; see the file COPYING.LESSER.  If not, see
https://www.gnu.org/licenses/ or write to the Free Software Foundation, Inc.,
51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA. */

#define MPFR_NEED_LONGLONG_H
#include "mpfr-impl.h"

/* FIXME[VL]: Implement the range reduction in this function.
   That's the whole point of sinu compared to sin. */

/* put in y the corrected-rounded value of sin(2*pi*x/u) */
int
mpfr_sinu (mpfr_ptr y, mpfr_srcptr x, unsigned long u, mpfr_rnd_t rnd_mode)
{
  mpfr_prec_t precy, prec;
  mpfr_exp_t expx, expt, err;
  mpfr_t t;
  int inexact = 0, nloops = 0, underflow = 0;
  MPFR_ZIV_DECL (loop);
  MPFR_SAVE_EXPO_DECL (expo);

  if (u == 0 || MPFR_UNLIKELY (MPFR_IS_SINGULAR (x)))
    {
      /* for u=0, return NaN */
      if (u == 0 || MPFR_IS_NAN (x) || MPFR_IS_INF (x))
        {
          MPFR_SET_NAN (y);
          MPFR_RET_NAN;
        }
      else /* x is zero */
        {
          MPFR_ASSERTD (MPFR_IS_ZERO (x));
          MPFR_SET_ZERO (y);
          MPFR_SET_SAME_SIGN (y, x);
          MPFR_RET (0);
        }
    }

  MPFR_SAVE_EXPO_MARK (expo);

  precy = MPFR_PREC (y);
  expx = MPFR_GET_EXP (x);
  /* for x large, since argument reduction is expensive, we want to avoid
     any failure in Ziv's strategy, thus we take into account expx too */
  prec = precy + MPFR_INT_CEIL_LOG2 (MAX(precy,expx)) + 8;
  MPFR_ASSERTD(prec >= 2);
  mpfr_init2 (t, prec);
  MPFR_ZIV_INIT (loop, prec);
  for (;;)
    {
      nloops ++;
      /* We first compute an approximation t of 2*pi*x/u, then call sin(t).
         If t = 2*pi*x/u + s, then |sin(t) - sin(2*pi*x/u)| <= |s|. */
      mpfr_set_prec (t, prec);
      mpfr_const_pi (t, MPFR_RNDN); /* t = pi * (1 + theta1) where
                                       |theta1| <= 2^-prec */
      mpfr_mul_2ui (t, t, 1, MPFR_RNDN); /* t = 2*pi * (1 + theta1) */
      mpfr_mul (t, t, x, MPFR_RNDN);     /* t = 2*pi*x * (1 + theta2)^2 where
                                            |theta2| <= 2^-prec */
      mpfr_div_ui (t, t, u, MPFR_RNDN);  /* t = 2*pi*x/u * (1 + theta3)^3 where
                                            |theta3| <= 2^-prec */
      /* if t is zero here, it means the division by u underflows, then
         sin(t) also underflows, since |sin(x)| <= |x| for say |x| < 1. */
      if (MPFR_UNLIKELY (MPFR_IS_ZERO (t)))
        {
          inexact = mpfr_underflow (y, rnd_mode, MPFR_SIGN(t));
          MPFR_SAVE_EXPO_UPDATE_FLAGS (expo, MPFR_FLAGS_INEXACT
                                       | MPFR_FLAGS_UNDERFLOW);
          underflow = 1;
          goto end;
        }
      /* since prec >= 2, |(1 + theta3)^3 - 1| <= 4*theta3 <= 2^(2-prec) */
      expt = MPFR_GET_EXP (t);
      /* we have |s| <= 2^(expt + 2 - prec) */
      mpfr_sin (t, t, MPFR_RNDN);
      err = MPFR_GET_EXP (t) + prec - expt - 2;
      if (MPFR_CAN_ROUND (t, err, precy, rnd_mode))
        break;
      /* check exact cases: this can only occur if 2*pi*x/u is a multiple
         of pi/2, i.e., if x/u is a multiple of 1/4 */
      if (nloops == 1)
        {
          inexact = mpfr_div_ui (t, x, u, MPFR_RNDN);
          mpfr_mul_2ui (t, t, 2, MPFR_RNDN);
          if (inexact == 0 && mpfr_integer_p (t))
            {
              if (MPFR_IS_ZERO (t) || !mpfr_odd_p (t))
                /* t is even: we have a multiple of pi, thus sinu = 0,
                   for the sign, we follow IEEE 754-2019: sinPi(+n) is +0
                   and sinPi(-n) is -0 for positive integers n, so that the
                   function is odd. */
                mpfr_set_zero (y, MPFR_IS_POS(t) ? +1 : -1);
              else /* t is odd */
                {
                  inexact = mpfr_sub_ui (t, t, 1, MPFR_RNDZ);
                  MPFR_ASSERTD(inexact == 0);
                  inexact = mpfr_div_2ui (t, t, 1, MPFR_RNDZ);
                  MPFR_ASSERTD(inexact == 0);
                  if (MPFR_IS_ZERO (t) || !mpfr_odd_p (t))
                    /* case pi/4: sinu = 1 */
                    mpfr_set_ui (y, 1, MPFR_RNDZ);
                  else
                    mpfr_set_si (y, -1, MPFR_RNDZ);
                }
              goto end;
            }
        }
      MPFR_ZIV_NEXT (loop, prec);
    }
  MPFR_ZIV_FREE (loop);

  inexact = mpfr_set (y, t, rnd_mode);

 end:
  mpfr_clear (t);
  MPFR_SAVE_EXPO_FREE (expo);
  return underflow ? inexact : mpfr_check_range (y, inexact, rnd_mode);
}
