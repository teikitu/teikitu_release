/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Base - Type [Constants].c
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Data                                                                                                                                                                    */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

TgALIGN(16) TgUN_SCALAR_C                   KTgMASK_TRUE                = { UINT64_MAX };

#define                                     TgPP_KVAL_PI_F              3.141592653589793238462643383279F
#define                                     TgPP_KVAL_SQRT3_F           1.732050807568877293527446341505F
#define                                     TgPP_KVAL_SQRT2_F           1.414213562373095048801688724209F
#define                                     TgPP_KVAL_SQRT5_F           2.236067977499789696409173668731F
#define                                     TgPP_KVAL_E_F               2.718281828459045F

TgALIGN(16) TgFLOAT32_C                     KTgEPS_F32                  = 1.192092896e-07F;
TgALIGN(16) TgFLOAT32_C                     KTgROOT_EPS_F32             = 3.4526698307252027193509668742125e-4F;
TgALIGN(16) TgFLOAT32_C                     KTgE_F32                    = TgPP_KVAL_E_F;
TgALIGN(16) TgFLOAT32_C                     KTgPI_F32                   = TgPP_KVAL_PI_F;
TgALIGN(16) TgFLOAT32_C                     KTgTWO_PI_F32               = 2.0F * TgPP_KVAL_PI_F;
TgALIGN(16) TgFLOAT32_C                     KTgHALF_PI_F32              = 0.5F * TgPP_KVAL_PI_F;
TgALIGN(16) TgFLOAT32_C                     KTgINVPI_F32                = 1.0F / TgPP_KVAL_PI_F;
TgALIGN(16) TgFLOAT32_C                     KTgSQRT2_F32                = TgPP_KVAL_SQRT2_F;
TgALIGN(16) TgFLOAT32_C                     KTgSQRT3_F32                = TgPP_KVAL_SQRT3_F;
TgALIGN(16) TgFLOAT32_C                     KTgSQRT5_F32                = TgPP_KVAL_SQRT5_F;
TgALIGN(16) TgFLOAT32_C                     KTgTHIRD_F32                = 1.0F / 3.0F;
TgALIGN(16) TgFLOAT32_C                     KTgTWENTYSEVENTH_F32        = 1.0F / 27.0F;
TgALIGN(16) TgFLOAT32_C                     KTgSQRT1_2_F32              = 1.0F / TgPP_KVAL_SQRT2_F;
TgALIGN(16) TgFLOAT32_C                     KTgDEG_TO_RAD_F32           = TgPP_KVAL_PI_F / 180.0F;
TgALIGN(16) TgFLOAT32_C                     KTgRAD_TO_DEG_F32           = 180.0F / TgPP_KVAL_PI_F;
TgALIGN(16) TgFLOAT32_C                     KTgGOLDEN_RATIO_F32         = (1.0F + TgPP_KVAL_SQRT5_F) * 0.5F;

#define                                     TgPP_KVAL_PI                3.141592653589793238462643383279
#define                                     TgPP_KVAL_SQRT3             1.732050807568877293527446341505
#define                                     TgPP_KVAL_SQRT2             1.414213562373095048801688724209
#define                                     TgPP_KVAL_SQRT5             2.236067977499789696409173668731
#define                                     TgPP_KVAL_E                 2.718281828459045

TgALIGN(16) TgFLOAT64_C                     KTgEPS_F64                  = 2.2204460492503131e-016;
TgALIGN(16) TgFLOAT64_C                     KTgROOT_EPS_F64             = 1.490116119384765631426592e-8;
TgALIGN(16) TgFLOAT64_C                     KTgE_F64                    = TgPP_KVAL_E;
TgALIGN(16) TgFLOAT64_C                     KTgPI_F64                   = TgPP_KVAL_PI;
TgALIGN(16) TgFLOAT64_C                     KTgTWO_PI_F64               = 2.0 * TgPP_KVAL_PI;
TgALIGN(16) TgFLOAT64_C                     KTgHALF_PI_F64              = 0.5 * TgPP_KVAL_PI;
TgALIGN(16) TgFLOAT64_C                     KTgINVPI_F64                = 1.0 / TgPP_KVAL_PI;
TgALIGN(16) TgFLOAT64_C                     KTgSQRT2_F64                = TgPP_KVAL_SQRT2;
TgALIGN(16) TgFLOAT64_C                     KTgSQRT3_F64                = TgPP_KVAL_SQRT3;
TgALIGN(16) TgFLOAT64_C                     KTgSQRT5_F64                = TgPP_KVAL_SQRT5;
TgALIGN(16) TgFLOAT64_C                     KTgTHIRD_F64                = 1.0 / 3.0;
TgALIGN(16) TgFLOAT64_C                     KTgTWENTYSEVENTH_F64        = 1.0 / 27.0;
TgALIGN(16) TgFLOAT64_C                     KTgSQRT1_2_F64              = 1.0 / TgPP_KVAL_SQRT2;
TgALIGN(16) TgFLOAT64_C                     KTgDEG_TO_RAD_F64           = TgPP_KVAL_PI / 180.0;
TgALIGN(16) TgFLOAT64_C                     KTgRAD_TO_DEG_F64           = 180.0 / TgPP_KVAL_PI;
TgALIGN(16) TgFLOAT64_C                     KTgGOLDEN_RATIO_F64         = (1.0 + TgPP_KVAL_SQRT5) * 0.5;

TgALIGN(16) TgVEC_N_F32_04_1_C              KTgEPS_N_F32_04_1           = { KTgEPS_F32, KTgEPS_F32, KTgEPS_F32, KTgEPS_F32 };
TgALIGN(16) TgVEC_N_F32_04_1_C              KTgROOT_EPS_N_F32_04_1      = { KTgROOT_EPS_F32, KTgROOT_EPS_F32, KTgROOT_EPS_F32, KTgROOT_EPS_F32 };
TgALIGN(16) TgVEC_N_F32_04_1_C              KTgE_N_F32_04_1             = { KTgE_F32, KTgE_F32, KTgE_F32, KTgE_F32 };
TgALIGN(16) TgVEC_N_F32_04_1_C              KTgPI_N_F32_04_1            = { KTgPI_F32, KTgPI_F32, KTgPI_F32, KTgPI_F32 };
TgALIGN(16) TgVEC_N_F32_04_1_C              KTgTWO_PI_N_F32_04_1        = { KTgTWO_PI_F32, KTgTWO_PI_F32, KTgTWO_PI_F32, KTgTWO_PI_F32 };
TgALIGN(16) TgVEC_N_F32_04_1_C              KTgHALF_PI_N_F32_04_1       = { KTgHALF_PI_F32, KTgHALF_PI_F32, KTgHALF_PI_F32, KTgHALF_PI_F32 };
TgALIGN(16) TgVEC_N_F32_04_1_C              KTgINVPI_N_F32_04_1         = { KTgINVPI_F32, KTgINVPI_F32, KTgINVPI_F32, KTgINVPI_F32 };
TgALIGN(16) TgVEC_N_F32_04_1_C              KTgSQRT2_N_F32_04_1         = { KTgSQRT2_F32, KTgSQRT2_F32, KTgSQRT2_F32, KTgSQRT2_F32 };
TgALIGN(16) TgVEC_N_F32_04_1_C              KTgSQRT3_N_F32_04_1         = { KTgSQRT3_F32, KTgSQRT3_F32, KTgSQRT3_F32, KTgSQRT3_F32 };
TgALIGN(16) TgVEC_N_F32_04_1_C              KTgSQRT5_N_F32_04_1         = { KTgSQRT5_F32, KTgSQRT5_F32, KTgSQRT5_F32, KTgSQRT5_F32 };
TgALIGN(16) TgVEC_N_F32_04_1_C              KTgTHIRD_N_F32_04_1         = { KTgTHIRD_F32, KTgTHIRD_F32, KTgTHIRD_F32, KTgTHIRD_F32 };
TgALIGN(16) TgVEC_N_F32_04_1_C              KTgTWENTYSEVENTH_N_F32_04_1 = { KTgTWENTYSEVENTH_F32, KTgTWENTYSEVENTH_F32, KTgTWENTYSEVENTH_F32, KTgTWENTYSEVENTH_F32 };
TgALIGN(16) TgVEC_N_F32_04_1_C              KTgSQRT1_2_N_F32_04_1       = { KTgSQRT1_2_F32, KTgSQRT1_2_F32, KTgSQRT1_2_F32, KTgSQRT1_2_F32 };
TgALIGN(16) TgVEC_N_F32_04_1_C              KTgDEG_TO_RAD_N_F32_04_1    = { KTgDEG_TO_RAD_F32, KTgDEG_TO_RAD_F32, KTgDEG_TO_RAD_F32, KTgDEG_TO_RAD_F32 };
TgALIGN(16) TgVEC_N_F32_04_1_C              KTgRAD_TO_DEG_N_F32_04_1    = { KTgRAD_TO_DEG_F32, KTgRAD_TO_DEG_F32, KTgRAD_TO_DEG_F32, KTgRAD_TO_DEG_F32 };
TgALIGN(16) TgVEC_N_F32_04_1_C              KTgGOLDEN_RATIO_N_F32_04_1  = { KTgGOLDEN_RATIO_F32, KTgGOLDEN_RATIO_F32, KTgGOLDEN_RATIO_F32, KTgGOLDEN_RATIO_F32 };



TgALIGN(16) TgUN_V128_C                     KTgFFFF_V128                = { .m_U32_04_1 = {{ 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF }} };
TgALIGN(16) TgUN_V128_C                     KTgFFF0_V128                = { .m_U32_04_1 = {{ 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000 }} };
TgALIGN(16) TgUN_V128_C                     KTgFF0F_V128                = { .m_U32_04_1 = {{ 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF }} };
TgALIGN(16) TgUN_V128_C                     KTgFF00_V128                = { .m_U32_04_1 = {{ 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0x00000000 }} };
TgALIGN(16) TgUN_V128_C                     KTgF0FF_V128                = { .m_U32_04_1 = {{ 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0xFFFFFFFF }} };
TgALIGN(16) TgUN_V128_C                     KTgF0F0_V128                = { .m_U32_04_1 = {{ 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000 }} };
TgALIGN(16) TgUN_V128_C                     KTgF00F_V128                = { .m_U32_04_1 = {{ 0xFFFFFFFF, 0x00000000, 0x00000000, 0xFFFFFFFF }} };
TgALIGN(16) TgUN_V128_C                     KTgF000_V128                = { .m_U32_04_1 = {{ 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000 }} };
TgALIGN(16) TgUN_V128_C                     KTg0FFF_V128                = { .m_U32_04_1 = {{ 0x00000000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF }} };
TgALIGN(16) TgUN_V128_C                     KTg0FF0_V128                = { .m_U32_04_1 = {{ 0x00000000, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000 }} };
TgALIGN(16) TgUN_V128_C                     KTg0F0F_V128                = { .m_U32_04_1 = {{ 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF }} };
TgALIGN(16) TgUN_V128_C                     KTg0F00_V128                = { .m_U32_04_1 = {{ 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000 }} };
TgALIGN(16) TgUN_V128_C                     KTg00FF_V128                = { .m_U32_04_1 = {{ 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFFFFFFFF }} };
TgALIGN(16) TgUN_V128_C                     KTg00F0_V128                = { .m_U32_04_1 = {{ 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00000000 }} };
TgALIGN(16) TgUN_V128_C                     KTg000F_V128                = { .m_U32_04_1 = {{ 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF }} };
TgALIGN(16) TgUN_V128_C                     KTg0000_V128                = { .m_U32_04_1 = {{ 0x00000000, 0x00000000, 0x00000000, 0x00000000 }} };
TgALIGN(16) TgUN_V128_C                     KTgNaN_V128                 = { .m_U32_04_1 = {{ 0x7F800000, 0x7F800000, 0x7F800000, 0x7F800000 }} };
TgALIGN(16) TgUN_V128_C                     KTgSgnM_V128                = { .m_U32_04_1 = {{ 0x80000000, 0x80000000, 0x80000000, 0x80000000 }} };
TgALIGN(16) TgUN_V128_C                     KTgINF_V128                 = { .m_U32_04_1 = {{ 0x7F800000, 0x7F800000, 0x7F800000, 0x7F800000 }} };
TgALIGN(16) TgUN_V128_C                     KTgPNNP_V128                = { .m_U32_04_1 = {{ 0x00000000, 0x80000000, 0x80000000, 0x00000000 }} };
TgALIGN(16) TgUN_V128_C                     KTgYZXW_V128                = { .m_U32_04_1 = {{ 0x04050607, 0x08090a0b, 0x00010203, 0x0c0d0e0f }} };
TgALIGN(16) TgUN_V128_C                     KTgZXYW_V128                = { .m_U32_04_1 = {{ 0x08090a0b, 0x00010203, 0x04050607, 0x0c0d0e0f }} };



TgALIGN(16) TgUN_V128_C                     KTgZERO_V128                = { .m_F32_04_1 = {{ 0.0F, 0.0F, 0.0F, 0.0F }} };
TgALIGN(16) TgUN_V128_C                     KTgONE_V128                 = { .m_F32_04_1 = {{ 1.0F, 1.0F, 1.0F, 1.0F }} };
TgALIGN(16) TgUN_V128_C                     KTgUNIT_X_V128              = { .m_F32_04_1 = {{ 1.0F, 0.0F, 0.0F, 0.0F }} };
TgALIGN(16) TgUN_V128_C                     KTgUNIT_Y_V128              = { .m_F32_04_1 = {{ 0.0F, 1.0F, 0.0F, 0.0F }} };
TgALIGN(16) TgUN_V128_C                     KTgUNIT_Z_V128              = { .m_F32_04_1 = {{ 0.0F, 0.0F, 1.0F, 0.0F }} };
TgALIGN(16) TgUN_V128_C                     KTgUNIT_W_V128              = { .m_F32_04_1 = {{ 0.0F, 0.0F, 0.0F, 1.0F }} };

TgALIGN(16) TgVEC_N_F32_04_3_C              KTgIDENT_N_F32_04_3         = { .m_avRow = {
                                                                            1.0F, 0.0F, 0.0F, 0.0F,
                                                                            0.0F, 1.0F, 0.0F, 0.0F,
                                                                            0.0F, 0.0F, 1.0F, 0.0F
                                                                          } };

TgALIGN(16) TgVEC_N_F32_04_4_C              KTgIDENT_N_F32_04_4         = { .m_avRow = {
                                                                            1.0F, 0.0F, 0.0F, 0.0F,
                                                                            0.0F, 1.0F, 0.0F, 0.0F,
                                                                            0.0F, 0.0F, 1.0F, 0.0F,
                                                                            0.0F, 0.0F, 0.0F, 1.0F
                                                                          } };

TgALIGN(16) TgVEC_F32_03_1_C                KTgZERO_F32_03_1            = { { 0.0F, 0.0F, 0.0F } };
TgALIGN(16) TgVEC_F32_03_1_C                KTgONE_F32_03_1             = { { 1.0F, 1.0F, 1.0F } };
TgALIGN(16) TgVEC_F32_03_1_C                KTgUNIT_X_F32_03_1          = { { 1.0F, 0.0F, 0.0F } };
TgALIGN(16) TgVEC_F32_03_1_C                KTgUNIT_Y_F32_03_1          = { { 0.0F, 1.0F, 0.0F } };
TgALIGN(16) TgVEC_F32_03_1_C                KTgUNIT_Z_F32_03_1          = { { 0.0F, 0.0F, 1.0F } };

TgALIGN(16) TgVEC_F32_04_1_C                KTgZERO_F32_04_1            = { { 0.0F, 0.0F, 0.0F, 0.0F } };
TgALIGN(16) TgVEC_F32_04_1_C                KTgONE_F32_04_1             = { { 1.0F, 1.0F, 1.0F, 1.0F } };
TgALIGN(16) TgVEC_F32_04_1_C                KTgUNIT_X_F32_04_1          = { { 1.0F, 0.0F, 0.0F, 0.0F } };
TgALIGN(16) TgVEC_F32_04_1_C                KTgUNIT_Y_F32_04_1          = { { 0.0F, 1.0F, 0.0F, 0.0F } };
TgALIGN(16) TgVEC_F32_04_1_C                KTgUNIT_Z_F32_04_1          = { { 0.0F, 0.0F, 1.0F, 0.0F } };
TgALIGN(16) TgVEC_F32_04_1_C                KTgUNIT_W_F32_04_1          = { { 0.0F, 0.0F, 0.0F, 1.0F } };

TgALIGN(16) TgVEC_F64_03_1_C                KTgZERO_F64_03_1            = { { 0.0, 0.0, 0.0 } };
TgALIGN(16) TgVEC_F64_03_1_C                KTgONE_F64_03_1             = { { 1.0, 1.0, 1.0 } };
TgALIGN(16) TgVEC_F64_03_1_C                KTgUNIT_X_F64_03_1          = { { 1.0, 0.0, 0.0 } };
TgALIGN(16) TgVEC_F64_03_1_C                KTgUNIT_Y_F64_03_1          = { { 0.0, 1.0, 0.0 } };
TgALIGN(16) TgVEC_F64_03_1_C                KTgUNIT_Z_F64_03_1          = { { 0.0, 0.0, 1.0 } };

TgALIGN(16) TgVEC_F64_04_1_C                KTgZERO_F64_04_1            = { { 0.0, 0.0, 0.0, 0.0 } };
TgALIGN(16) TgVEC_F64_04_1_C                KTgONE_F64_04_1             = { { 1.0, 1.0, 1.0, 1.0 } };
TgALIGN(16) TgVEC_F64_04_1_C                KTgUNIT_X_F64_04_1          = { { 1.0, 0.0, 0.0, 0.0 } };
TgALIGN(16) TgVEC_F64_04_1_C                KTgUNIT_Y_F64_04_1          = { { 0.0, 1.0, 0.0, 0.0 } };
TgALIGN(16) TgVEC_F64_04_1_C                KTgUNIT_Z_F64_04_1          = { { 0.0, 0.0, 1.0, 0.0 } };
TgALIGN(16) TgVEC_F64_04_1_C                KTgUNIT_W_F64_04_1          = { { 0.0, 0.0, 0.0, 1.0 } };

TgALIGN(16) TgVEC_F32_04_3_C                KTgIDENT_F32_04_3           = { {
                                                                              1.0F, 0.0F, 0.0F, 0.0F,
                                                                              0.0F, 1.0F, 0.0F, 0.0F,
                                                                              0.0F, 0.0F, 1.0F, 0.0F
                                                                            } };

TgALIGN(16) TgVEC_F32_04_4_C                KTgIDENT_F32_04_4           = { {
                                                                              1.0F, 0.0F, 0.0F, 0.0F,
                                                                              0.0F, 1.0F, 0.0F, 0.0F,
                                                                              0.0F, 0.0F, 1.0F, 0.0F,
                                                                              0.0F, 0.0F, 0.0F, 1.0F
                                                                            } };
