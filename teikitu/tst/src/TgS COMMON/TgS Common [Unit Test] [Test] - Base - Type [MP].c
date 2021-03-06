/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common [Unit Test] [Test] - Base - Type [MP].c
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
/*  Test Functions                                                                                                                                                                 */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

TEST_METHOD( UNIT_TEST__PM_MT_MX_Init );
TEST_METHOD( UNIT_TEST__PM_MT_MX_Free );
TEST_METHOD( UNIT_TEST__PM_MT_MX_Wait_Block );
TEST_METHOD( UNIT_TEST__PM_MT_MX_Wait );
TEST_METHOD( UNIT_TEST__PM_MT_MX_Release );
TEST_METHOD( UNIT_TEST__PM_MT_SM_Init );
TEST_METHOD( UNIT_TEST__PM_MT_SM_Free );
TEST_METHOD( UNIT_TEST__PM_MT_SM_Wait_Block );
TEST_METHOD( UNIT_TEST__PM_MT_SM_Wait );
TEST_METHOD( UNIT_TEST__PM_MT_SM_Signal );




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  File Local Functions and Data                                                                                                                                                  */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#if TgCOMPILE__THREAD

TEST_LOCAL TgUINT_F32                       UNIT_TEST__TEST__MUTEX( TgUINT_PTR_C UNUSED_PARAM uiUnused );
TEST_LOCAL TgUINT_F32                       UNIT_TEST__TEST__SEMAPHORE( TgUINT_PTR_C UNUSED_PARAM uiUnused );

/*# TgCOMPILE__THREAD */
#endif

TEST_LOCAL STg1_MT_MX                       s_sMP_MX;
TEST_LOCAL STg1_MT_SM                       s_sMP_SM;
TEST_LOCAL TgSINT_F32_A                     s_iTest_Enabled;




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/* Public Functions                                                                                                                                                                */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- UNIT_TEST__TEST__Base_Type_MP -------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__TEST__Base_Type_MP )
{
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__PM_MT_MX_Init() );
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__PM_MT_MX_Free() );
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__PM_MT_MX_Wait_Block() );
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__PM_MT_MX_Wait() );
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__PM_MT_MX_Release() );
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__PM_MT_SM_Init() );
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__PM_MT_SM_Free() );
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__PM_MT_SM_Wait_Block() );
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__PM_MT_SM_Wait() );
    Test__Expect_EQ(KTgS_OK, UNIT_TEST__PM_MT_SM_Signal() );

    TEST_END_METHOD( KTgS_OK );
}




/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Test Functions                                                                                                                                                                 */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

#if TgCOMPILE__THREAD

TEST_LOCAL TgUINT_F32 UNIT_TEST__TEST__MUTEX( TgUINT_PTR_C UNUSED_PARAM uiUnused )
{
    atomic_store( &s_iTest_Enabled, 1 );
    tgPM_MT_MX_Wait_Block( &s_sMP_MX );
    atomic_store( &s_iTest_Enabled, 2 );
    tgPM_MT_MX_Release( &s_sMP_MX );
    atomic_store( &s_iTest_Enabled, 3 );

    return (0);
}


TEST_LOCAL TgUINT_F32 UNIT_TEST__TEST__SEMAPHORE( TgUINT_PTR_C UNUSED_PARAM uiUnused )
{
    atomic_store( &s_iTest_Enabled, 1 );
    tgPM_MT_SM_Wait_Block( &s_sMP_SM );
    atomic_store( &s_iTest_Enabled, 2 );
    tgPM_MT_SM_Signal( &s_sMP_SM, 1 );
    atomic_store( &s_iTest_Enabled, 3 );

    return (0);
}

/*# TgCOMPILE__THREAD */
#endif


/* ---- UNIT_TEST__PM_MT_MX_Init ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__PM_MT_MX_Init )
{
#if TgCOMPILE__THREAD
    Test__Expect_EQ(KTgS_OK, tgPM_MT_MX_Init( &s_sMP_MX, "MutexTest001" ));
    tgPM_MT_MX_Free( &s_sMP_MX );

/*# TgCOMPILE__THREAD */
#endif

    return (KTgS_OK);
}


/* ---- UNIT_TEST__PM_MT_MX_Free ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__PM_MT_MX_Free )
{
#if TgCOMPILE__THREAD
    Test__Expect_EQ(KTgS_OK, tgPM_MT_MX_Init( &s_sMP_MX, "MutexTest001" ));
    tgPM_MT_MX_Free( &s_sMP_MX );
    Test__Expect_EQ(KTgS_OK, tgPM_MT_MX_Init( &s_sMP_MX, "MutexTest001" ));
    tgPM_MT_MX_Free( &s_sMP_MX );

/*# TgCOMPILE__THREAD */
#endif

    return (KTgS_OK);
}


/* ---- UNIT_TEST__PM_MT_MX_Wait_Block ------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__PM_MT_MX_Wait_Block )
{
#if TgCOMPILE__THREAD
    TgTHREAD_ID                         tiThread;

    Test__Expect_EQ(KTgS_OK, tgPM_MT_MX_Init( &s_sMP_MX, "MutexTest001" ));
    Test__Expect_EQ(KTgS_OK, tgPM_MT_MX_Wait( &s_sMP_MX ));

    atomic_store( &s_iTest_Enabled, 0 );
    tiThread = tgTR_Create( UNIT_TEST__TEST__MUTEX, 0, 0, ETgTHREAD_PRIORITY__NORMAL, "UNIT_TEST__TEST__MUTEX" );
    Test__Expect_NE(KTgID__INVALID_VALUE, tiThread.m_uiKI);

    while (0 == atomic_load( &s_iTest_Enabled ))
    {
        tgTR_Yield();
    };

    Test__Expect_EQ(KTgS_OK, tgPM_MT_MX_Wait( &s_sMP_MX )); /* Re-entrant (recursive) */
    tgPM_MT_MX_Release( &s_sMP_MX );
    tgPM_MT_MX_Release( &s_sMP_MX );
    while (0 == atomic_load( &s_iTest_Enabled ))
    {
        tgTR_Yield();
    };

    tgTR_Close( tiThread );

    tgPM_MT_MX_Free( &s_sMP_MX );

/*# TgCOMPILE__THREAD */
#endif

    return (KTgS_OK);
}


/* ---- UNIT_TEST__PM_MT_MX_Wait ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__PM_MT_MX_Wait )
{
#if TgCOMPILE__THREAD
    Test__Expect_EQ(KTgS_OK, tgPM_MT_MX_Init( &s_sMP_MX, "MutexTest001" ));
    Test__Expect_EQ(KTgS_OK, tgPM_MT_MX_Wait( &s_sMP_MX ));
    Test__Expect_EQ(KTgS_OK, tgPM_MT_MX_Wait( &s_sMP_MX )); /* Re-entrant (recursive) */
    tgPM_MT_MX_Release( &s_sMP_MX );
    tgPM_MT_MX_Release( &s_sMP_MX );
    tgPM_MT_MX_Free( &s_sMP_MX );

/*# TgCOMPILE__THREAD */
#endif

    return (KTgS_OK);
}


/* ---- UNIT_TEST__PM_MT_MX_Release ---------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__PM_MT_MX_Release )
{
#if TgCOMPILE__THREAD
    Test__Expect_EQ(KTgS_OK, tgPM_MT_MX_Init( &s_sMP_MX, "MutexTest001" ));
    Test__Expect_EQ(KTgS_OK, tgPM_MT_MX_Wait( &s_sMP_MX ));
    Test__Expect_EQ(KTgS_OK, tgPM_MT_MX_Wait( &s_sMP_MX )); /* Re-entrant (recursive) */
    tgPM_MT_MX_Release( &s_sMP_MX );
    tgPM_MT_MX_Release( &s_sMP_MX );
    Test__Expect_EQ(KTgS_OK, tgPM_MT_MX_Wait( &s_sMP_MX ));
    Test__Expect_EQ(KTgS_OK, tgPM_MT_MX_Wait( &s_sMP_MX )); /* Re-entrant (recursive) */
    tgPM_MT_MX_Release( &s_sMP_MX );
    tgPM_MT_MX_Release( &s_sMP_MX );
    tgPM_MT_MX_Free( &s_sMP_MX );

/*# TgCOMPILE__THREAD */
#endif

    return (KTgS_OK);
}


/* ---- UNIT_TEST__PM_MT_SM_Init ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__PM_MT_SM_Init )
{
#if TgCOMPILE__THREAD
    Test__Expect_EQ(KTgS_OK, tgPM_MT_SM_Init( &s_sMP_SM, "SemTest001", 0, TgPLATFORM__SEMAPHORE_MAX_VALUE ));
    tgPM_MT_SM_Free( &s_sMP_SM );

    Test__Expect_EQ(KTgS_OK, tgPM_MT_SM_Init( &s_sMP_SM, "SemTest001", 1, 2 ));
    Test__Expect_EQ(KTgS_OK, tgPM_MT_SM_Wait( &s_sMP_SM ));
    Test__Expect_NE(KTgS_OK, tgPM_MT_SM_Wait( &s_sMP_SM ));
    tgPM_MT_SM_Free( &s_sMP_SM );

/*# TgCOMPILE__THREAD */
#endif

    return (KTgS_OK);
}


/* ---- UNIT_TEST__PM_MT_SM_Free ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__PM_MT_SM_Free )
{
    Test__Expect_EQ(KTgS_OK, tgPM_MT_SM_Init( &s_sMP_SM, "SemTest001", 0, TgPLATFORM__SEMAPHORE_MAX_VALUE ));
    tgPM_MT_SM_Free( &s_sMP_SM );
    Test__Expect_EQ(KTgS_OK, tgPM_MT_SM_Init( &s_sMP_SM, "SemTest001", 0, TgPLATFORM__SEMAPHORE_MAX_VALUE ));
    tgPM_MT_SM_Free( &s_sMP_SM );

    return (KTgS_OK);
}


/* ---- UNIT_TEST__PM_MT_SM_Wait_Block ------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__PM_MT_SM_Wait_Block )
{
#if TgCOMPILE__THREAD
    TgTHREAD_ID                         tiThread;

    Test__Expect_EQ(KTgS_OK, tgPM_MT_SM_Init( &s_sMP_SM, "SemTest001", 0, TgPLATFORM__SEMAPHORE_MAX_VALUE ));

    atomic_store( &s_iTest_Enabled, 0 );
    tiThread = tgTR_Create( UNIT_TEST__TEST__SEMAPHORE, 0, 0, ETgTHREAD_PRIORITY__NORMAL, "UNIT_TEST__TEST__SEMAPHORE" );
    Test__Expect_NE(KTgID__INVALID_VALUE, tiThread.m_uiKI);

    while (0 == atomic_load( &s_iTest_Enabled ))
    {
        tgTR_Yield();
    };

    tgPM_MT_SM_Signal( &s_sMP_SM, 1 );
    while (0 == atomic_load( &s_iTest_Enabled ))
    {
        tgTR_Yield();
    };

    tgTR_Close( tiThread );

    tgPM_MT_SM_Free( &s_sMP_SM );

/*# TgCOMPILE__THREAD */
#endif

    return (KTgS_OK);
}


/* ---- UNIT_TEST__PM_MT_SM_Wait ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__PM_MT_SM_Wait )
{
    Test__Expect_EQ(KTgS_OK, tgPM_MT_SM_Init( &s_sMP_SM, "SemTest001", 1, 2 ));
    Test__Expect_EQ(KTgS_OK, tgPM_MT_SM_Wait( &s_sMP_SM ));
    Test__Expect_NE(KTgS_OK, tgPM_MT_SM_Wait( &s_sMP_SM ));
    tgPM_MT_SM_Free( &s_sMP_SM );

    return (KTgS_OK);
}


/* ---- UNIT_TEST__PM_MT_SM_Signal ----------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TEST_METHOD_DEFINE( UNIT_TEST__PM_MT_SM_Signal )
{
    Test__Expect_EQ(KTgS_OK, tgPM_MT_SM_Init( &s_sMP_SM, "SemTest001", 1, 2 ));
    tgPM_MT_SM_Signal( &s_sMP_SM, 1 );
    Test__Expect_EQ(KTgS_OK, tgPM_MT_SM_Wait( &s_sMP_SM ));
    Test__Expect_EQ(KTgS_OK, tgPM_MT_SM_Wait( &s_sMP_SM ));
    Test__Expect_NE(KTgS_OK, tgPM_MT_SM_Wait( &s_sMP_SM ));
    tgPM_MT_SM_Signal( &s_sMP_SM, 2 );
    Test__Expect_EQ(KTgS_OK, tgPM_MT_SM_Wait( &s_sMP_SM ));
    Test__Expect_EQ(KTgS_OK, tgPM_MT_SM_Wait( &s_sMP_SM ));
    Test__Expect_NE(KTgS_OK, tgPM_MT_SM_Wait( &s_sMP_SM ));
    tgPM_MT_SM_Free( &s_sMP_SM );

    return (KTgS_OK);
}


