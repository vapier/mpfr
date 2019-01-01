/* Various Thresholds of MPFR, not exported.  -*- mode: C -*-

Copyright 2005-2019 Free Software Foundation, Inc.

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
http://www.gnu.org/licenses/ or write to the Free Software Foundation, Inc.,
51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA. */

/* Generated by MPFR's tuneup.c, 2018-02-22, gcc 6.3.0 */
/* gcc14.fsffrance.org (Intel(R) Xeon(R) CPU X5450  @ 3.00GHz)
   with GMP 6.1.2 configured with ABI=32,
   MPFR configured with CFLAGS='-O2 -m32 -march=i686 -mtune=generic' */

#define MPFR_MULHIGH_TAB  \
 -1,0,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,0,0, \
 0,0,0,0,0,0,0,15,0,0,0,16,0,17,18,19, \
 21,18,19,20,21,21,22,23,24,26,23,28,25,30,30,28, \
 29,30,34,32,32,34,34,36,36,38,38,38,40,42,42,42, \
 40,46,42,46,44,44,46,52,48,49,50,50,52,52,54,60, \
 56,56,58,59,60,60,60,63,64,64,64,64,68,68,68,68, \
 68,68,64,68,64,68,68,68,68,68,68,68,68,68,76,76, \
 76,76,68,80,84,68,68,84,84,84,84,84,84,84,84,77, \
 84,76,80,84,84,76,84,92,84,76,84,84,84,84,92,92, \
 93,93,84,110,111,99,93,99,111,99,110,111,106,105,108,104, \
 110,111,111,110,111,111,111,110,110,123,116,110,123,123,120,117, \
 116,117,116,123,123,123,120,126,123,123,123,129,126,123,129,129, \
 126,135,132,135,135,135,135,135,134,135,141,141,154,135,156,141, \
 134,148,156,156,156,147,148,164,164,155,156,156,164,163,164,163, \
 163,164,164,164,164,164,164,163,171,163,164,172,172,171,172,163, \
 164,171,180,177,180,179,180,184,172,179,180,180,176,179,180,171, \
 180,180,188,188,180,187,200,204,180,204,204,187,196,203,204,203, \
 204,203,204,203,204,203,220,204,220,204,220,220,219,203,204,220, \
 220,219,220,219,204,219,220,203,220,204,204,219,220,252,236,251, \
 250,251,252,249,252,249,252,251,252,252,252,251,252,251,252,249, \
 252,252,252,251,252,252,252,251,252,267,251,252,252,251,268,252, \
 252,249,250,252,252,252,268,252,252,268,252,268,268,268,268,252, \
 252,265,251,268,268,268,266,265,267,268,268,268,268,268,268,268, \
 268,267,268,268,268,268,268,267,268,306,306,306,306,268,306,306, \
 306,305,305,306,306,268,306,306,305,305,306,306,306,330,306,306, \
 306,306,306,306,306,306,330,306,306,306,306,330,330,330,330,306, \
 329,330,330,330,328,329,330,330,354,329,330,329,330,330,354,330, \
 330,354,329,330,330,354,330,352,354,329,354,330,354,330,330,354, \
 354,329,354,330,360,330,330,354,352,354,378,371,378,377,354,378, \
 378,402,354,402,378,378,378,401,402,378,402,378,354,401,377,378, \
 377,378,402,401,378,378,378,402,401,402,402,402,401,401,402,402, \
 401,402,401,402,402,402,402,402,402,402,402,402,402,402,401,402, \
 402,401,402,402,401,402,402,401,402,402,402,402,402,402,402,402, \
 402,401,402,402,402,401,402,439,439,440,402,440,402,402,426,439, \
 439,440,440,440,426,426,426,438,439,440,472,439,471,440,440,472, \
 472,440,440,440,471,439,472,440,472,472,472,440,470,472,471,472, \
 470,472,504,470,472,472,469,472,496,472,472,472,471,502,472,472, \
 471,472,471,504,472,472,472,472,480,504,472,496,503,503,504,504, \
 503,503,472,504,504,472,496,503,502,472,504,496,472,504,503,472, \
 504,496,504,504,503,536,470,536,472,536,535,535,536,534,504,536, \
 536,503,504,536,536,544,536,503,504,536,535,503,480,504,504,536, \
 535,568,568,504,568,568,568,544,568,536,535,568,568,535,504,535, \
 568,568,568,536,504,567,544,568,568,536,544,567,544,544,568,584, \
 544,568,560,568,600,559,568,584,583,568,568,600,599,567,568,567, \
 568,567,568,567,600,568,568,599,599,568,584,568,567,568,599,568, \
 567,568,567,600,600,568,600,584,568,599,599,568,600,568,600,599, \
 608,599,600,568,600,600,568,600,600,568,568,598,599,600,599,600, \
 600,600,600,664,664,600,632,584,600,664,663,600,664,600,632,663, \
 663,631,632,600,600,600,600,664,600,656,599,664,600,600,656,600, \
 600,664,664,664,664,663,663,663,664,664,664,664,663,664,662,663, \
 664,663,664,664,664,632,632,663,664,663,664,632,664,664,664,664, \
 664,664,663,664,664,664,662,664,663,664,664,664,664,663,663,664, \
 664,664,662,663,663,664,664,664,664,664,662,663,664,664,664,664, \
 664,664,664,664,663,664,664,664,664,664,663,664,663,664,664,664, \
 663,664,664,687,688,662,663,664,664,663,664,734,664,664,688,736, \
 736,664,664,664,664,663,664,663,664,736,735,664,664,663,736,733, \
 736,734,735,736,736,735,736,735,736,736,736,784,736,784,784,736, \
 736,784,735,736,736,783,736,783,736,736,736,735,784,784,736,736, \
 735,784,736,784,736,784,784,736,784,784,784,784,784,783,784,783, \
 783,783,784,784,784,784,784,784,784,783,824,784,782,831,832,783, \
 824,831,832,832,832,784,784,831,784,784,784,784,784,824,831,824, \
 823,824,824,824,824,824,831,832,824,822,824,832,824,824,832,823, \
 832,832,831,831,832,832,832,832,832,856,822,832,832,832,824,856, \
 824,824,832,832,824,832,856,831,832,832,856,831,832,856,832,830 \

#define MPFR_SQRHIGH_TAB  \
 -1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,8,9,10, \
 11,12,13,11,13,12,13,14,15,14,15,16,16,18,17,19, \
 19,18,19,19,20,20,22,23,23,22,23,24,25,25,26,27, \
 28,30,30,27,28,29,30,31,32,33,38,40,40,42,42,44, \
 40,40,42,42,44,44,42,42,44,42,50,50,42,46,50,44, \
 46,44,46,46,50,48,50,50,50,50,48,54,50,54,50,50, \
 54,50,54,54,54,62,60,53,54,54,56,56,58,56,60,58, \
 58,60,60,62,62,60,76,62,76,68,72,66,68,72,76,72, \
 72,72,76,76,76,80,80,80,76,80,80,88,84,80,84,88, \
 84,92,88,88,92,92,88,88,80,92,96,92,92,87,96,96, \
 100,100,100,100,96,100,96,104,96,104,100,100,100,100,108,100, \
 96,100,104,103,104,104,100,100,104,104,104,104,104,108,108,99, \
 100,108,108,100,112,100,106,123,108,108,128,123,112,129,112,108, \
 129,135,134,135,128,129,138,135,123,141,135,127,128,141,129,147, \
 128,141,134,135,135,141,138,139,135,141,138,141,135,153,146,147, \
 147,153,141,141,147,153,141,150,135,147,147,159,147,147,147,159, \
 135,141,135,146,147,165,146,147,159,152,147,147,147,147,146,158, \
 151,147,153,146,147,157,153,153,188,159,159,188,188,164,164,195, \
 196,160,180,187,188,180,187,188,180,188,188,165,187,188,196,188, \
 188,180,188,196,188,188,195,188,187,188,188,196,196,188,195,196, \
 196,195,196,195,196,196,195,196,196,188,211,203,212,195,196,196, \
 196,196,212,211,211,195,196,220,220,212,220,225,212,196,216,220, \
 216,220,220,195,196,196,220,220,196,220,228,203,212,212,212,212, \
 211,212,212,212,212,212,212,220,212,219,220,220,220,220,212,228, \
 227,220,228,228,228,228,228,212,212,228,227,211,228,236,276,219, \
 220,228,212,219,220,244,219,219,244,244,220,227,228,228,244,227, \
 282,244,294,270,264,282,269,276,264,270,294,276,282,270,270,276, \
 276,276,282,270,270,276,281,276,282,282,282,282,276,282,294,282, \
 282,294,270,294,282,294,282,294,294,294,294,294,276,282,282,282, \
 276,294,282,282,294,282,282,294,306,294,294,294,312,294,294,294, \
 294,294,294,294,317,318,318,294,293,318,294,306,306,318,330,324, \
 324,330,318,306,330,312,318,318,324,324,318,324,324,330,317,330, \
 324,323,324,318,318,330,330,329,329,330,330,318,324,329,329,330, \
 336,330,329,330,324,342,354,342,318,324,354,342,341,348,348,318, \
 330,354,354,342,318,368,354,376,368,354,375,330,376,392,392,376, \
 330,376,376,376,368,392,392,392,384,392,392,392,392,392,392,392, \
 392,392,392,408,392,392,407,392,392,392,392,406,408,408,407,407, \
 408,392,408,416,408,392,424,408,375,376,376,408,408,424,376,423, \
 416,424,392,408,424,408,376,431,432,424,424,423,424,424,424,407, \
 432,424,392,431,432,392,432,424,407,440,392,440,440,440,408,432, \
 439,440,424,440,416,440,424,407,423,424,424,424,424,456,424,424, \
 432,423,424,432,416,424,432,423,424,423,440,424,424,424,424,439, \
 440,472,424,424,424,424,440,439,440,456,440,456,438,408,456,440, \
 424,440,424,456,464,488,456,424,456,456,424,439,424,472,472,479, \
 456,456,432,480,480,455,480,440,472,488,480,488,440,440,464,440, \
 488,439,488,488,488,488,456,487,488,488,488,456,432,487,504,488, \
 480,456,488,488,487,488,488,487,488,520,520,520,488,520,520,439, \
 480,472,480,479,456,487,488,488,496,487,472,488,488,520,520,488, \
 520,488,520,520,496,488,520,488,488,504,488,520,440,600,536,600, \
 456,520,536,536,600,600,568,567,600,600,568,599,600,600,600,599, \
 598,600,600,568,599,600,568,600,600,599,600,600,600,568,568,599, \
 600,600,600,600,599,600,600,599,600,599,600,600,599,599,600,599, \
 599,599,600,600,600,599,600,600,599,599,600,600,632,600,600,600, \
 664,599,600,600,600,600,600,600,631,632,632,632,600,632,632,599, \
 663,664,624,631,632,632,664,662,663,664,664,632,632,664,632,663, \
 664,631,664,662,662,664,664,662,664,663,664,663,663,663,664,664, \
 664,662,663,664,664,664,664,663,664,663,664,664,664,664,664,663, \
 664,632,663,664,664,663,664,664,664,631,664,663,696,696,696,664, \
 600,664,664,662,664,664,664,664,664,663,664,663,664,664,663,664, \
 664,663,664,664,632,664,664,663,664,663,664,663,664,664,728,663, \
 664,727,663,664,664,663,664,664,696,632,728,728,663,663,664,696, \
 664,664,696,728,664,664,728,728,696,663,664,663,728,664,664,655, \
 696,663,664,661,664,695,696,663,656,728,664,663,664,663,664,664, \
 696,664,663,663,664,695,696,664,664,695,696,662,664,663,664,663 \

#define MPFR_DIVHIGH_TAB  \
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /*0-15*/ \
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /*16-31*/ \
 0,0,0,0,0,20,23,23,23,23,24,23,24,25,27,27, /*32-47*/ \
 27,27,31,29,32,29,30,30,32,31,33,31,35,35,36,35, /*48-63*/ \
 36,36,42,42,37,41,41,45,42,42,46,43,44,45,42,45, /*64-79*/ \
 44,45,49,47,46,49,50,54,50,56,51,56,56,58,54,56, /*80-95*/ \
 60,54,56,59,55,58,54,56,63,60,62,56,60,66,64,66, /*96-111*/ \
 63,62,67,68,62,66,64,68,68,72,67,70,67,68,66,67, /*112-127*/ \
 70,68,74,83,72,70,83,76,84,84,83,84,84,84,82,82, /*128-143*/ \
 84,84,84,87,84,84,84,82,84,84,84,86,84,88,91,92, /*144-159*/ \
 88,98,99,84,88,91,90,104,87,99,96,94,100,100,92,94, /*160-175*/ \
 92,92,112,105,100,104,100,100,104,104,104,104,112,112,104,105, /*176-191*/ \
 99,112,112,103,104,111,112,112,104,104,112,112,111,112,112,112, /*192-207*/ \
 111,111,112,128,112,128,111,112,116,120,120,116,120,118,118,128, /*208-223*/ \
 127,128,128,120,136,136,136,128,135,136,136,132,136,130,128,136, /*224-239*/ \
 128,136,136,136,126,136,136,136,135,136,136,136,136,136,136,136, /*240-255*/ \
 136,136,136,136,144,148,168,136,144,136,168,143,142,144,150,143, /*256-271*/ \
 168,168,143,168,167,167,168,176,176,166,168,171,168,168,172,168, /*272-287*/ \
 168,176,168,167,168,176,176,176,176,168,176,176,176,172,176,175, /*288-303*/ \
 176,176,175,176,176,176,174,175,176,168,168,167,168,168,168,183, /*304-319*/ \
 175,176,176,176,168,176,176,173,176,175,176,176,174,175,175,171, /*320-335*/ \
 176,184,198,176,176,184,175,175,208,186,186,198,208,184,186,177, /*336-351*/ \
 208,208,208,209,207,208,209,184,192,197,208,184,192,208,192,208, /*352-367*/ \
 224,192,222,198,208,196,198,198,210,207,222,216,208,222,222,222, /*368-383*/ \
 198,198,210,207,224,208,222,222,224,208,224,222,224,224,222,208, /*384-399*/ \
 210,216,222,222,208,216,222,222,208,224,224,224,222,224,224,228, /*400-415*/ \
 224,223,224,224,240,224,240,222,248,224,224,222,240,256,240,224, /*416-431*/ \
 256,257,222,255,224,228,224,256,240,256,240,255,256,255,256,240, /*432-447*/ \
 256,255,256,257,256,252,256,256,256,256,256,256,264,256,255,256, /*448-463*/ \
 257,272,256,255,272,270,256,256,272,256,240,257,288,272,252,254, /*464-479*/ \
 257,256,256,257,256,270,272,255,256,256,267,256,256,255,254,256, /*480-495*/ \
 255,256,257,268,264,269,256,255,256,256,288,256,269,270,267,336, /*496-511*/ \
 272,272,272,267,270,264,272,269,288,270,288,288,288,272,272,337, /*512-527*/ \
 288,336,336,335,288,352,336,334,286,344,288,296,344,288,288,293, /*528-543*/ \
 288,304,336,336,336,336,336,336,336,288,336,336,304,352,352,336, /*544-559*/ \
 336,336,336,336,336,336,336,336,336,343,344,340,336,335,336,336, /*560-575*/ \
 336,336,336,336,342,336,336,336,336,344,352,336,342,335,336,335, /*576-591*/ \
 336,352,344,344,352,352,352,344,352,352,336,351,350,352,352,352, /*592-607*/ \
 352,352,341,336,352,335,336,336,352,335,336,344,336,336,334,336, /*608-623*/ \
 336,343,336,344,344,344,352,344,352,336,344,335,352,343,351,344, /*624-639*/ \
 344,341,342,352,344,351,352,336,352,336,352,344,336,336,341,344, /*640-655*/ \
 336,336,344,336,352,336,352,342,352,344,344,344,347,344,344,341, /*656-671*/ \
 344,352,353,352,352,351,352,359,352,351,352,352,352,352,352,352, /*672-687*/ \
 352,349,350,351,352,367,368,352,357,352,352,352,360,352,353,353, /*688-703*/ \
 391,408,408,360,368,388,384,368,392,408,400,416,416,384,392,367, /*704-719*/ \
 384,408,408,416,408,408,408,392,392,416,416,408,416,415,408,415, /*720-735*/ \
 416,416,412,408,414,420,448,417,408,408,416,408,408,413,416,408, /*736-751*/ \
 416,408,415,415,416,431,416,416,416,392,448,415,416,432,416,444, /*752-767*/ \
 416,448,408,416,416,416,408,408,448,444,416,416,416,416,408,416, /*768-783*/ \
 408,448,414,415,416,417,418,448,444,416,416,406,416,416,414,432, /*784-799*/ \
 448,448,416,416,432,448,416,432,448,444,438,448,448,416,448,416, /*800-815*/ \
 444,448,444,448,416,432,416,416,416,432,416,448,448,416,432,448, /*816-831*/ \
 444,448,444,448,447,466,448,432,432,448,448,432,448,448,440,444, /*832-847*/ \
 454,432,448,480,438,447,504,432,448,448,448,448,448,447,448,447, /*848-863*/ \
 448,446,448,444,443,448,444,448,446,448,448,503,536,448,448,448, /*864-879*/ \
 448,448,448,448,448,447,450,448,514,448,512,480,448,512,480,454, /*880-895*/ \
 512,500,504,476,480,536,536,536,504,536,480,504,504,480,536,504, /*896-911*/ \
 480,504,504,504,480,504,512,480,480,512,480,512,512,480,478,536, /*912-927*/ \
 480,489,504,513,536,504,511,479,480,480,534,511,511,512,536,512, /*928-943*/ \
 512,504,504,504,504,504,504,512,511,509,512,512,504,511,544,504, /*944-959*/ \
 544,504,512,544,544,536,512,504,543,511,512,513,540,511,511,504, /*960-975*/ \
 544,511,508,504,512,536,536,504,504,512,536,544,504,544,512,536, /*976-991*/ \
 535,512,512,541,504,536,536,536,536,504,544,511,544,511,544,512, /*992-1007*/ \
 511,512,544,514,544,535,544,544,544,536,536,536,536,536,544,544 /*1008-1023*/ \

#define MPFR_MUL_THRESHOLD 13 /* limbs */
#define MPFR_SQR_THRESHOLD 18 /* limbs */
#define MPFR_DIV_THRESHOLD 3 /* limbs */
#define MPFR_EXP_2_THRESHOLD 522 /* bits */
#define MPFR_EXP_THRESHOLD 6920 /* bits */
#define MPFR_SINCOS_THRESHOLD 28160 /* bits */
#define MPFR_AI_THRESHOLD1 -24100 /* threshold for negative input of mpfr_ai */
#define MPFR_AI_THRESHOLD2 2303
#define MPFR_AI_THRESHOLD3 37484
/* Tuneup completed successfully, took 787 seconds */
