/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common [Unit Test] - Unit Test.h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_UNIT_TEST_UNIT_TEST_H)
#define TGS_COMMON_UNIT_TEST_UNIT_TEST_H
#pragma once

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wcast-align"
#pragma clang diagnostic ignored "-Wunused-local-typedefs"
#pragma clang diagnostic ignored "-Wmissing-prototypes"
#pragma clang diagnostic ignored "-Wunused-macros"
#endif




/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Test Defines                                                                                                                                                                   */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#define                                     Test__Expect_EQ( A, ... )                                                                                                               \
                                            {                                                                                                                                       \
                                                if (!((A) == (__VA_ARGS__)))                                                                                                        \
                                                {                                                                                                                                   \
                                                    TgBREAK_INLINE;                                                                                                                 \
                                                    return (KTgE_FAIL);                                                                                                             \
                                                };                                                                                                                                  \
                                            };

#define                                     Test__Expect_NE( A, ... )                                                                                                               \
                                            {                                                                                                                                       \
                                                if (!((A) != (__VA_ARGS__)))                                                                                                        \
                                                {                                                                                                                                   \
                                                    TgBREAK_INLINE;                                                                                                                 \
                                                    return (KTgE_FAIL);                                                                                                             \
                                                };                                                                                                                                  \
                                            };

#define                                     EXTN_METHOD_DECLARE( A ) TgEXTN TgRESULT A ( TgVOID )
#define                                     TEST_METHOD_DEFINE( A ) TgRESULT A ( TgVOID )
#define                                     TEST_METHOD( A ) static TgRESULT A ( TgVOID )
#define                                     TEST_MEMBER( ... ) static __VA_ARGS__
#define                                     TEST_LOCAL static
#define                                     TEST_END_METHOD(A) return (A);

//#define                                     TEST__ROOT_DIRECTORY u8"C:"
#define                                     TEST__ROOT_DIRECTORY u8"/"

#define UNIT_TEST__MSG_LITERAL_PREFIX       "%-16.16s %-24.24s  "
#define UNIT_TEST__MSG_LITERAL_1            "%-16.16s %-24.24s  %-16.16s\n"
#define UNIT_TEST__MSG_LITERAL_2            "%-16.16s %-24.24s  %-16.16s %-24.24s\n"
#define UNIT_TEST__MSG_LITERAL_3            "%-16.16s %-24.24s  %-16.16s %-24.24s %-16.16s\n"
#define UNIT_TEST__MSG_LITERAL_4            "%-16.16s %-24.24s  %-16.16s %-24.24s %-16.16s %-16.16s\n"

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Types                                                                                                                                                                   */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

TgTYPE_FORWARD_STRUCT( Test_Case );
TgTYPE_FORWARD_STRUCT( Test_Set );
TgTYPE_FORWARD_STRUCT( Test_Context );

typedef TgVOID(*TgREPORT_CSE_REPORT)( Test_Context_PC, Test_Case_PC, TgUINT_F32_C );
typedef TgVOID(*TgREPORT_CSE_RESULT)( Test_Context_PC, Test_Case_PC, TgCHAR_MB_CPC );
typedef TgVOID(*TgREPORT_SET_HEADER)( Test_Context_PC, Test_Set_PC );
typedef TgVOID(*TgREPORT_SET_FOOTER)( Test_Context_PC, Test_Set_PC );
typedef TgVOID(*TgREPORT_SET_REPORT)( Test_Context_PC, Test_Set_PC, TgCHAR_MB_CPC );
typedef TgVOID(*TgREPORT_CTX_HEADER)( Test_Context_PC );
typedef TgVOID(*TgREPORT_CTX_FOOTER)( Test_Context_PC );
typedef TgVOID(*TgREPORT_CTX_REPORT)( Test_Context_PC, TgCHAR_MB_CPC );
typedef TgRESULT(*TgVIRT_FUNC)( TgVOID );

enum { KTgNUM_TEST_PER_CASE = 32 };

TgEXTN TgBOOL g_bUnit_Test__Enabled_ERR_Write;


/* ---- Test Case ---------------------------------------------------------------------------------------------------------------------------------------------------------------- */

struct Test_Case
{
    TgVIRT_FUNC m_pfnInit;
    TgVIRT_FUNC m_pfnFree;
    TgVIRT_FUNC m_pfnTest[KTgNUM_TEST_PER_CASE];
    TgCHAR_MB_CP m_apszTest[KTgNUM_TEST_PER_CASE];

    TgCHAR_MB_CP m_pszFile;
    TgUINT_F32 m_nuiLN;
    TgUINT_F32 m_iPad0;
    TgCHAR_MB_CP m_pszSet;
    TgCHAR_MB_CP m_pszCase;

    Test_Case_P m_psNext;
    Test_Case_P m_psPrev;

    TgREPORT_CSE_REPORT m_pfnReport_Case_Report_Passed;
    TgREPORT_CSE_REPORT m_pfnReport_Case_Report_Failed;
    TgREPORT_CSE_RESULT m_pfnReport_Case_Passed;
    TgREPORT_CSE_RESULT m_pfnReport_Case_Failed;
};

TgEXTN TgVOID Unit_Test__Case_Init( Test_Case_PCU );
TgEXTN TgRESULT Unit_Test__Case_Execute( Test_Context_PCU, Test_Case_PCU );


/* ---- Test Set ----------------------------------------------------------------------------------------------------------------------------------------------------------------- */

struct Test_Set
{
    TgVIRT_FUNC m_pfnInit;
    TgVIRT_FUNC m_pfnFree;

    Test_Case_P m_psFirst_Case;
    TgCHAR_MB_CP m_szSet;

    Test_Set_P m_psNext;
    Test_Set_P m_psPrev;

    TgBOOL m_bPassed;
    TgUINT_E08 m_iPad0[7];

    TgREPORT_SET_HEADER m_pfnReport_Set_Header;
    TgREPORT_SET_FOOTER m_pfnReport_Set_Footer;
    TgREPORT_SET_REPORT m_pfnReport_Set_Passed;
    TgREPORT_SET_REPORT m_pfnReport_Set_Failed;
};

TgEXTN TgVOID Unit_Test__Set_Register_Case( Test_Set_PC, Test_Case_PC );
TgEXTN TgVOID Unit_Test__Set_Init( Test_Set_PC );
TgEXTN TgRESULT Unit_Test__Set_Execute( Test_Context_PCU, Test_Set_PCU );


/* ---- Test Context ------------------------------------------------------------------------------------------------------------------------------------------------------------- */

struct Test_Context
{
    TgVIRT_FUNC m_pfnInit;
    TgVIRT_FUNC m_pfnBoot;
    TgVIRT_FUNC m_pfnStop;
    TgVIRT_FUNC m_pfnFree;
    TgVIRT_FUNC m_pfnReset;

    TgUINT_F32 m_psRestart_Case_Test;
    TgUINT_F32 m_iPad0;
    Test_Case_P m_psRestart_Case;
    Test_Set_P m_psRestart_Set;

    TgBOOL m_bReport_Case_Report;
    TgBOOL m_bReport_Case_Result;
    TgBOOL m_bReport_Set_Report;
    TgBOOL m_bReport_Set_Result;
    TgBOOL m_bReport_Context_Report;
    TgBOOL m_bReport_Context_Result;
    TgBOOL m_bIgnore_On_Fail;
    TgBOOL m_bFail_On_First_Fail;
    TgFLOAT32 m_fStart;

    TgUINT_F32 m_nuiCase_Passed, m_nuiCase_Failed, m_nuiCase_Total;
    TgUINT_F32 m_nuiSet_Passed, m_nuiSet_Failed, m_nuiSet_Total;
    TgUINT_F32 m_iPad1;

    TgREPORT_CSE_REPORT m_pfnReport_Case_Report_Passed;
    TgREPORT_CSE_REPORT m_pfnReport_Case_Report_Failed;
    TgREPORT_CSE_RESULT m_pfnReport_Case_Passed;
    TgREPORT_CSE_RESULT m_pfnReport_Case_Failed;
    TgREPORT_SET_HEADER m_pfnReport_Set_Header;
    TgREPORT_SET_FOOTER m_pfnReport_Set_Footer;
    TgREPORT_SET_REPORT m_pfnReport_Set_Passed;
    TgREPORT_SET_REPORT m_pfnReport_Set_Failed;
    TgREPORT_CTX_HEADER m_pfnReport_Context_Header;
    TgREPORT_CTX_FOOTER m_pfnReport_Context_Footer;
    TgREPORT_CTX_REPORT m_pfnReport_Context_Passed;
    TgREPORT_CTX_REPORT m_pfnReport_Context_Failed;
};

TgEXTN TgVOID Unit_Test__Context_Init( Test_Context_PCU );


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

TgEXTN TgVOID Unit_Test__Sleep( TgUINT_F32_C );

TgEXTN TgVOID Unit_Test__Register( Test_Set_PC );
TgEXTN TgRESULT Unit_Test__Execute( Test_Context_PC );

TgEXTN TgVOID Default_Report_Case_Report_Passed( Test_Context_PC, Test_Case_PC, TgUINT_F32_C );
TgEXTN TgVOID Default_Report_Case_Report_Failed( Test_Context_PC, Test_Case_PC, TgUINT_F32_C );
TgEXTN TgVOID Default_Report_Case_Passed( Test_Context_PC, Test_Case_PC, TgCHAR_MB_CPC );
TgEXTN TgVOID Default_Report_Case_Failed( Test_Context_PC, Test_Case_PC, TgCHAR_MB_CPC );
TgEXTN TgVOID Default_Report_Set_Header( Test_Context_PC, Test_Set_PC );
TgEXTN TgVOID Default_Report_Set_Footer( Test_Context_PC, Test_Set_PC );
TgEXTN TgVOID Default_Report_Set_Passed( Test_Context_PC, Test_Set_PC, TgCHAR_MB_CPC );
TgEXTN TgVOID Default_Report_Set_Failed( Test_Context_PC, Test_Set_PC, TgCHAR_MB_CPC );
TgEXTN TgVOID Default_Report_Context_Header( Test_Context_PC );
TgEXTN TgVOID Default_Report_Context_Footer( Test_Context_PC );
TgEXTN TgVOID Default_Report_Context_Passed( Test_Context_PC, TgCHAR_MB_CPC );
TgEXTN TgVOID Default_Report_Context_Failed( Test_Context_PC, TgCHAR_MB_CPC );


/* =============================================================================================================================================================================== */
#endif
