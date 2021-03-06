/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Util ST - Queue.inl
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_UTIL_ST_QUEUE_INL)
#define TGS_COMMON_UTIL_ST_QUEUE_INL
#pragma once


/* == Common ===================================================================================================================================================================== */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- Spin-Lock Queue ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/* ---- tgCM_UT_ST__QU__Init ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgRESULT tgCM_UT_ST__QU__Init( STg2_UT_ST__QU_PC NONULL psMP_QU )
{
    psMP_QU->m_sNode.m_pNext_Node = &psMP_QU->m_sNode;
    psMP_QU->m_psTail_Node = &psMP_QU->m_sNode;
    return (KTgS_OK);
}


/* ---- tgCM_UT_ST__QU__Free ----------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgCM_UT_ST__QU__Free( STg2_UT_ST__QU_PC NONULL psMP_QU )
{
    TgERROR(tgCM_UT_ST__QU__Is_Empty( psMP_QU ));
}


/* ---- tgCM_UT_ST__QU__Enqueue -------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgCM_UT_ST__QU__Enqueue( STg2_UT_ST__QU_PC NONULL psMP_QU, STg2_UT_ST__QU_Node_PC NONULL psNode )
{
    STg2_UT_ST__QU_Node_P               psTailNode;

    psTailNode = psNode;
    while (nullptr != psTailNode->m_pNext_Node)
    {
        psTailNode = psTailNode->m_pNext_Node;
    } 

    psMP_QU->m_psTail_Node->m_pNext_Node = psNode;
    psMP_QU->m_psTail_Node = psTailNode;
    psMP_QU->m_psTail_Node->m_pNext_Node = &psMP_QU->m_sNode;
}


/* ---- tgCM_UT_ST__QU__Merge ---------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgVOID tgCM_UT_ST__QU__Merge( STg2_UT_ST__QU_PC NONULL psMP_QU0, STg2_UT_ST__QU_PC NONULL psMP_QU1 )
{
    STg2_UT_ST__QU_Node_P               psTailNode;
    STg2_UT_ST__QU_Node_P               psNode;

    if( tgCM_UT_ST__QU__Is_Empty( psMP_QU1 ))
    {
        return;
    };

    psNode = psMP_QU1->m_sNode.m_pNext_Node;

    psTailNode = psMP_QU1->m_psTail_Node;
    psTailNode->m_pNext_Node = &psMP_QU0->m_sNode;

    psMP_QU0->m_psTail_Node->m_pNext_Node = psNode;
    psMP_QU0->m_psTail_Node = psTailNode;

    psMP_QU1->m_sNode.m_pNext_Node = &psMP_QU1->m_sNode;
    psMP_QU1->m_psTail_Node = &psMP_QU1->m_sNode;
}


/* ---- tgCM_UT_ST__QU__Dequeue -------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE STg2_UT_ST__QU_Node_P tgCM_UT_ST__QU__Dequeue( STg2_UT_ST__QU_PC NONULL psMP_QU )
{
    STg2_UT_ST__QU_Node_P               psNode;

    psNode = psMP_QU->m_sNode.m_pNext_Node;
    if (&psMP_QU->m_sNode == psNode)
    {
        return (nullptr);
    };

    psMP_QU->m_sNode.m_pNext_Node = psNode->m_pNext_Node;

    if (&psMP_QU->m_sNode == psNode->m_pNext_Node)
    {
        psMP_QU->m_psTail_Node = &psMP_QU->m_sNode;
    };

    psNode->m_pNext_Node = (TgVOID_P)nullptr;
    return (psNode);
}


/* ---- tgCM_UT_ST__QU__Is_Empty ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgBOOL tgCM_UT_ST__QU__Is_Empty( STg2_UT_ST__QU_PC NONULL psMP_QU )
{
    return (&psMP_QU->m_sNode == psMP_QU->m_sNode.m_pNext_Node);
}


/* ---- tgCM_UT_ST__QU__Is_Valid ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgBOOL tgCM_UT_ST__QU__Is_Valid( STg2_UT_ST__QU_PC NONULL psMP_QU )
{
    STg2_UT_ST__QU_Node_P               psNode;

    if ((nullptr == psMP_QU->m_psTail_Node) || (psMP_QU->m_psTail_Node->m_pNext_Node != &psMP_QU->m_sNode))
    {
        return (false);
    };

    psNode = psMP_QU->m_sNode.m_pNext_Node;
    do
    {
        if (psNode == psMP_QU->m_psTail_Node)
        {
            return (true);
        };
        psNode = psNode->m_pNext_Node;
    }
    while (psNode != &psMP_QU->m_sNode);
    return (false);
}


/* ---- tgCM_UT_ST__QU__In_Queue ------------------------------------------------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
TgINLINE TgBOOL tgCM_UT_ST__QU__In_Queue( STg2_UT_ST__QU_PC NONULL psMP_QU, STg2_UT_ST__QU_Node_PC NONULL psTest )
{
    STg2_UT_ST__QU_Node_P               psNode;

    psNode = psMP_QU->m_sNode.m_pNext_Node;
    do
    {
        if (psNode == psTest)
        {
            return (true);
        };
        if (psNode == psMP_QU->m_psTail_Node)
        {
            break;
        };
        psNode = psNode->m_pNext_Node;
    }
    while (psNode != &psMP_QU->m_sNode);
    return (false);
}


/* =============================================================================================================================================================================== */
#endif
