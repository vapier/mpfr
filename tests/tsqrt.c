/* Test file for mpfr_sqrt.

Copyright (C) 1999 Free Software Foundation.

This file is part of the MPFR Library.

The MPFR Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Library General Public License as published by
the Free Software Foundation; either version 2 of the License, or (at your
option) any later version.

The MPFR Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
License for more details.

You should have received a copy of the GNU Library General Public License
along with the MPFR Library; see the file COPYING.LIB.  If not, write to
the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
MA 02111-1307, USA. */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "gmp.h"
#include "gmp-impl.h"
#include "mpfr.h"
#include "mpfr-impl.h"
#ifdef __mips
#include <sys/fpu.h>
#endif

extern int isnan(), getpid();

#define check(a,r) check3(a,r,-1.0)

int maxulp=0;

void check3(a, rnd_mode, Q) double a; unsigned char rnd_mode; double Q;
{
  mpfr_t q; double Q2; int ck,u;

  ck = (Q!=-1.0); /* if ck=1, then Q is certified correct */
  mpfr_init2(q, 53);
  mpfr_set_d(q, a, rnd_mode);
#ifdef TEST
  mpfr_set_machine_rnd_mode(rnd_mode);
#endif
  mpfr_sqrt(q, q, rnd_mode);
  if (ck==0) Q = sqrt(a);
  else {
    if (Q != sqrt(a) && (!isnan(Q) || !isnan(sqrt(a)))) {
      fprintf(stderr, "you've found a bug in your machine's sqrt for x=%1.20e\n", a);
      mpfr_clear(q); 
      exit(1);

    }
  }
  Q2 = mpfr_get_d(q);
  if (Q!=Q2 && (!isnan(Q) || !isnan(Q2))) {
    u = ulp(Q2,Q);
    if (ck) {
      printf("mpfr_sqrt failed for a=%1.20e, rnd_mode=%s\n",
	     a, mpfr_print_rnd_mode(rnd_mode));
      printf("expected sqrt is %1.20e, got %1.20e (%d ulp)\n",Q,Q2,u);
      mpfr_clear(q); 
      exit(1);
    }
    else if (u>maxulp || u<-maxulp) {
      maxulp = (u>maxulp) ? u : -u;
      printf("libm.a differs from mpfr_sqrt for a=%1.20e, rnd_mode=%s\n",
	     a, mpfr_print_rnd_mode(rnd_mode));
      printf("libm.a gives %1.20e, mpfr_sqrt gives %1.20e (%d ulp)\n",Q,Q2,u);
    }
  }
  mpfr_clear(q);
}

void check4(a, rnd_mode, Q) double a; unsigned char rnd_mode; char *Q;
{
  mpfr_t q, res;

  mpfr_init2(q, 53); mpfr_init2(res, 53);
  mpfr_set_d(q, a, rnd_mode);
  mpfr_sqrt(q, q, rnd_mode);
  mpfr_set_str(res, Q, 16, GMP_RNDN);
  if (mpfr_cmp(q, res)) {
      printf("mpfr_sqrt failed for a=%1.20e, rnd_mode=%s\n",
	     a, mpfr_print_rnd_mode(rnd_mode));
      printf("expected "); mpfr_print_raw(res); putchar('\n');
      printf("got      "); mpfr_print_raw(q); putchar('\n');
      mpfr_clear(q); mpfr_clear(res); 
      exit(1);
  }
  mpfr_clear(res); 
  mpfr_clear(q);
}

void check24(a, rnd_mode, Q) float a; unsigned char rnd_mode; float Q;
{
  mpfr_t q; float Q2;

  mpfr_init2(q, 24);
  mpfr_set_d(q, a, rnd_mode);
  mpfr_sqrt(q, q, rnd_mode);
  Q2 = mpfr_get_d(q);
  if (Q!=Q2) {
    printf("mpfr_sqrt failed for a=%1.10e, prec=24, rnd_mode=%s\n",
	   a, mpfr_print_rnd_mode(rnd_mode));
    printf("expected sqrt is %1.10e, got %1.10e\n",Q,Q2);
    exit(1);
  }
  mpfr_clear(q);
}

/* the following examples come from the paper "Number-theoretic Test 
   Generation for Directed Rounding" from Michael Parks, Table 3 */
void check_float()
{
  float b = 8388608.0; /* 2^23 */

  check24(b*8388610.0, GMP_RNDN, 8.388609e6);
  check24(b*2.0*16777214.0, GMP_RNDN, 1.6777215e7);
  check24(b*8388612.0, GMP_RNDN, 8.388610e6);
  check24(b*2.0*16777212.0, GMP_RNDN, 1.6777214e7);
  check24(b*11946704.0, GMP_RNDN, 1.0010805e7);
  check24(b*14321479.0, GMP_RNDN, 1.0960715e7);
  check24(b*2.0*13689673.0, GMP_RNDN, 1.5155019e7);
  check24(b*8388614.0, GMP_RNDN, 8.388611e6);
  check24(b*2.0*16777210.0, GMP_RNDN, 1.6777213e7);
  check24(b*10873622.0, GMP_RNDN, 9.550631e6);

  check24(b*8388610.0, GMP_RNDZ, 8.388608e6);
  check24(b*2.0*16777214.0, GMP_RNDZ, 1.6777214e7);
  check24(b*8388612.0, GMP_RNDZ, 8.388609e6);
  check24(b*2.0*16777212.0, GMP_RNDZ, 1.6777213e7);
  check24(b*11946704.0, GMP_RNDZ, 1.0010805e7);
  check24(b*14321479.0, GMP_RNDZ, 1.0960715e7);
  check24(b*2.0*13689673.0, GMP_RNDZ, 1.5155019e7);
  check24(b*8388614.0, GMP_RNDZ, 8.38861e6);
  check24(b*2.0*16777210.0, GMP_RNDZ, 1.6777212e7);
  check24(b*10873622.0, GMP_RNDZ, 9.550631e6);

  check24(b*8388610.0, GMP_RNDU, 8.388609e6);
  check24(b*2.0*16777214.0, GMP_RNDU, 1.6777215e7);
  check24(b*8388612.0, GMP_RNDU, 8.388610e6);
  check24(b*2.0*16777212.0, GMP_RNDU, 1.6777214e7);
  check24(b*11946704.0, GMP_RNDU, 1.0010806e7);
  check24(b*14321479.0, GMP_RNDU, 1.0960716e7);
  check24(b*2.0*13689673.0, GMP_RNDU, 1.515502e7);
  check24(b*8388614.0, GMP_RNDU, 8.388611e6);
  check24(b*2.0*16777210.0, GMP_RNDU, 1.6777213e7);
  check24(b*10873622.0, GMP_RNDU, 9.550632e6);

  check24(b*8388610.0, GMP_RNDD, 8.388608e6);
  check24(b*2.0*16777214.0, GMP_RNDD, 1.6777214e7);
  check24(b*8388612.0, GMP_RNDD, 8.388609e6);
  check24(b*2.0*16777212.0, GMP_RNDD, 1.6777213e7);
  check24(b*11946704.0, GMP_RNDD, 1.0010805e7);
  check24(b*14321479.0, GMP_RNDD, 1.0960715e7);
  check24(b*2.0*13689673.0, GMP_RNDD, 1.5155019e7);
  check24(b*8388614.0, GMP_RNDD, 8.38861e6);
  check24(b*2.0*16777210.0, GMP_RNDD, 1.6777212e7);
  check24(b*10873622.0, GMP_RNDD, 9.550631e6);
}

void special()
{
  mpfr_t x, z;

  mpfr_init2 (x, 1);
  mpfr_init2 (z, 1);

  /* checks the sign is correctly set */
  mpfr_set_d (x, 1.0, GMP_RNDN);
  mpfr_set_d (z, -1.0, GMP_RNDN);
  mpfr_sqrt (z, x, GMP_RNDN);
  if (mpfr_cmp_ui (z, 0) < 0) {
    fprintf (stderr, "Error: square root of %e gives %e\n", 
	     mpfr_get_d (x), mpfr_get_d (z));
    exit (1);
  }

  mpfr_set_prec (x, 192);
  mpfr_set_prec (z, 160);
  mpfr_set_str_raw (z, "0.1011010100000100100100100110011001011100100100000011000111011001011101101101110000110100001000100001100001011000E1");
  mpfr_set_prec(x, 160);
  mpfr_sqrt(x, z, GMP_RNDN);
  mpfr_sqrt(z, x, GMP_RNDN);

  mpfr_clear (x);
  mpfr_clear (z);
}

int main()
{
  double a;
#ifdef TEST
  int i; 
#ifdef __mips
    /* to get denormalized numbers on IRIX64 */
    union fpc_csr exp;
    exp.fc_word = get_fpc_csr();
    exp.fc_struct.flush = 0;
    set_fpc_csr(exp.fc_word);
#endif

  srand(getpid());
  for (i=0;i<100000;i++) {
    a = drand();
    if (a < 0.0) a = -a; /* ensures a is positive */
    check(a, rand() % 4);
  }
#endif
  special ();
  check_float();
  check3(0.0/0.0, GMP_RNDN, 0.0/0.0); 
  check3(-1.0, GMP_RNDN, 0.0/0.0); 
  check3(1.0/0.0, GMP_RNDN, 1.0/0.0); 
  check3(-1.0/0.0, GMP_RNDN, 0.0/0.0); 
  check3(-0.0, GMP_RNDN, 0.0); 
  check4(6.37983013646045901440e+32, GMP_RNDN, "5.9bc5036d09e0c@13");
  check4(1.0, GMP_RNDN, "1");
  check4(1.0, GMP_RNDZ, "1");
  check4(3.725290298461914062500000e-9, GMP_RNDN, "4@-4");
  check4(3.725290298461914062500000e-9, GMP_RNDZ, "4@-4");
  a=1190456976439861.0;
  check4(a, GMP_RNDZ, "2.0e7957873529a@6");
  check4(1024.0*a, GMP_RNDZ, "4.1cf2af0e6a534@7");
  /* the following examples are bugs in Cygnus compiler/system, found by
     Fabrice Rouillier while porting mpfr to Windows */
  check4(9.89438396044940256501e-134, GMP_RNDU, "8.7af7bf0ebbee@-56");
  check4(7.86528588050363751914e+31, GMP_RNDZ, "1.f81fc40f32062@13");
  check4(0.99999999999999988897, GMP_RNDN, "f.ffffffffffff8@-1");
  check4(1.00000000000000022204, GMP_RNDN, "1");
  /* the following examples come from the paper "Number-theoretic Test 
   Generation for Directed Rounding" from Michael Parks, Table 4 */
  a = 4503599627370496.0; /* 2^52 */

  check4(a*2.0*8732221479794286.0, GMP_RNDN, "1.f81fc40f32063@13");
  check4(a*8550954388695124.0, GMP_RNDN, "1.60c012a92fc65@13");
  check4(a*7842344481681754.0, GMP_RNDN, "1.51d17526c7161@13");
  check4(a*5935035262218600.0, GMP_RNDN, "1.25e19302f7e51@13");
  check4(a*5039650445085418.0, GMP_RNDN, "1.0ecea7dd2ec3d@13");
  check4(a*5039721545366078.0, GMP_RNDN, "1.0ecf250e8e921@13");
  check4(a*8005963117781324.0, GMP_RNDN, "1.5552f3eedcf33@13");
  check4(a*6703494707970582.0, GMP_RNDN, "1.3853ee10c9c99@13");
  check4(a*8010323124937260.0, GMP_RNDN, "1.556abe212b56f@13");
  check4(a*2.0*8010776873384260.0, GMP_RNDN, "1.e2d9a51977e6e@13");

  check4(a*2.0*8732221479794286.0, GMP_RNDZ, "1.f81fc40f32062@13");
  check4(a*8550954388695124.0, GMP_RNDZ, "1.60c012a92fc64@13");
  check4(a*7842344481681754.0, GMP_RNDZ, "1.51d17526c716@13");
  check4(a*5935035262218600.0, GMP_RNDZ, "1.25e19302f7e5@13");
  check4(a*5039650445085418.0, GMP_RNDZ, "1.0ecea7dd2ec3c@13");
  check4(a*5039721545366078.0, GMP_RNDZ, "1.0ecf250e8e92@13");
  check4(a*8005963117781324.0, GMP_RNDZ, "1.5552f3eedcf32@13");
  check4(a*6703494707970582.0, GMP_RNDZ, "1.3853ee10c9c98@13");
  check4(a*8010323124937260.0, GMP_RNDZ, "1.556abe212b56e@13");
  check4(a*2.0*8010776873384260.0, GMP_RNDZ, "1.e2d9a51977e6d@13");

  check4(a*2.0*8732221479794286.0, GMP_RNDU, "1.f81fc40f32063@13");
  check4(a*8550954388695124.0, GMP_RNDU, "1.60c012a92fc65@13");
  check4(a*7842344481681754.0, GMP_RNDU, "1.51d17526c7161@13");
  check4(a*5935035262218600.0, GMP_RNDU, "1.25e19302f7e51@13");
  check4(a*5039650445085418.0, GMP_RNDU, "1.0ecea7dd2ec3d@13");
  check4(a*5039721545366078.0, GMP_RNDU, "1.0ecf250e8e921@13");
  check4(a*8005963117781324.0, GMP_RNDU, "1.5552f3eedcf33@13");
  check4(a*6703494707970582.0, GMP_RNDU, "1.3853ee10c9c99@13");
  check4(a*8010323124937260.0, GMP_RNDU, "1.556abe212b56f@13");
  check4(a*2.0*8010776873384260.0, GMP_RNDU, "1.e2d9a51977e6e@13");

  check4(a*2.0*8732221479794286.0, GMP_RNDD, "1.f81fc40f32062@13");
  check4(a*8550954388695124.0, GMP_RNDD, "1.60c012a92fc64@13");
  check4(a*7842344481681754.0, GMP_RNDD, "1.51d17526c716@13");
  check4(a*5935035262218600.0, GMP_RNDD, "1.25e19302f7e5@13");
  check4(a*5039650445085418.0, GMP_RNDD, "1.0ecea7dd2ec3c@13");
  check4(a*5039721545366078.0, GMP_RNDD, "1.0ecf250e8e92@13");
  check4(a*8005963117781324.0, GMP_RNDD, "1.5552f3eedcf32@13");
  check4(a*6703494707970582.0, GMP_RNDD, "1.3853ee10c9c98@13");
  check4(a*8010323124937260.0, GMP_RNDD, "1.556abe212b56e@13");
  check4(a*2.0*8010776873384260.0, GMP_RNDD, "1.e2d9a51977e6d@13");
  return 0;
}
