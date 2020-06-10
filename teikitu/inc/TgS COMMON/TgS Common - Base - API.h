/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Common - Base - API.h
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#if !defined(TGS_COMMON_BASE_API_H)
#define TGS_COMMON_BASE_API_H
#pragma once

#include TgHEADER_HARDWARE(TgS COMMON/TgS,Common - Base - API.h)
#include "TgS COMMON/TgS Common - Base - API [Math].h"
#include "TgS COMMON/TgS Common - Base - API [Platform].h"
#include "TgS COMMON/TgS Common - Base - API [Text].h"


/* == Common ===================================================================================================================================================================== */
/* MARK: Unit Test Complete 00D008E0-5616-4AAF-8989-24865B450F52                                                                                                                   */

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  DOXYGEN                                                                                                                                                                        */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/** @defgroup TGS_COMMON_BASE_API_RANDOM Random
    @ingroup TGS_COMMON_BASE
*/

/** @defgroup TGS_COMMON_BASE_API_MEMORY Memory
    @ingroup TGS_COMMON_BASE
*/

/** @defgroup TGS_COMMON_BASE_API_TIME Time
    @ingroup TGS_COMMON_BASE
*/

/** @defgroup TGS_COMMON_BASE_API_IO Input / Output
    @ingroup TGS_COMMON_BASE
*/


/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */
/*  Public Functions                                                                                                                                                               */
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- */

/* ---- Random ------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/** @addtogroup TGS_COMMON_BASE_API_RANDOM */
/** @{ */

                                            /** @brief Init Mersenne Twister Random Generator (Default for TGS)
                                                @param[in] ARG Seed */
TgEXTN TgVOID                               tgCM_Init_Random_MT( TgUINT_F32 ARG );

                                            /** @brief Init Mersenne Twister Random Generator (Default for TGS)
                                                @param[in] ARG0 Seed List
                                                @param[in] ARG1 Number of Seeds */
TgEXTN TgVOID                               tgCM_Init_Random_MT__Key_List( TgUINT_F32_PU ARG0, TgUINT_F32 ARG1 );

                                            /** @return A random number from the Mersenne Twister Random Generator [0,UINTMAX] */
TgEXTN TgUINT_F32                           tgCM_RAND_MT_U32( TgVOID );

                                            /** @return A value on a normal (Gaussian) distribution with the given mean and standard deviation.
                                                @param[in] ARG0 Mean
                                                @param[in] ARG1 Standard Deviation */
TgEXTN TgFLOAT32                            tgCM_RAND_NRM_F32( TgFLOAT32_C ARG0, TgFLOAT32_C ARG1 );

                                            /** @brief Create a random name
                                                @param[in] ARG0 Pointer to the destination string buffer
                                                @param[in] ARG1 Number of bytes in the buffer at ARG0
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgCM_Random_Name( TgCHAR_NC_P ARG0, TgRSIZE_C ARG1 );

/** @} TGS_COMMON_BASE_API_RANDOM */


/* ---- Memory ------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/** @addtogroup TGS_COMMON_BASE_API_MEMORY */
/** @{ */

                                            /** @brief Copy the contents at ARG2 into the region at ARG0 up to a maximum of the minimum of (ARG1, ARG3)
                                                @param[out] OUT0 Pointer to the starting location of a region of memory (destination)
                                                @param[in] ARG1 Total capacity of the region at ARG0
                                                @param[in] ARG2 Pointer to the starting location of a region of memory (source)
                                                @param[in] ARG3 Total capacity of the region at ARG2
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgMM_Copy( TgVOID_PU OUT0, TgRSIZE_C ARG1, TgVOID_CPU ARG2, TgRSIZE_C ARG3 );

                                            /** @brief Move the contents at ARG2 into the region at ARG0 up to a maximum of the minimum of (ARG1, ARG3)
                                                @param[out] OUT0 Pointer to the starting location of a region of memory (destination)
                                                @param[in] ARG1 Total capacity of the region at ARG0
                                                @param[in] ARG2 Pointer to the starting location of a region of memory (source)
                                                @param[in] ARG3 Total capacity of the region at ARG2
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgMM_Move( TgVOID_PU OUT0, TgRSIZE_C ARG1, TgVOID_CPU ARG2, TgRSIZE_C ARG3 );

                                            /** @brief Copy the byte value in ARG2 into the region at ARG0 up to a maximum of the minimum of (ARG1, ARG3)
                                                @param[out] OUT0 Pointer to the starting location of a region of memory (destination)
                                                @param[in] ARG1 byte value (unsigned 8bit integer)
                                                @param[in] ARG2 Total capacity of the region at ARG0
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgMM_Set_U08( TgVOID_PU OUT0, TgRSIZE_C ARG2, TgUINT_E08_C ARG1 );

                                            /** @brief Reset all bits in the region at ARG0
                                                @param[out] OUT0 Pointer to the starting location of a region of memory (destination)
                                                @param[in] ARG1 Total capacity of the region at ARG0
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgMM_Set_U08_0x00( TgVOID_PU OUT0, TgRSIZE_C ARG1 );

                                            /** @brief Set all bits in the region at ARG0
                                                @param[out] OUT0 Pointer to the starting location of a region of memory (destination)
                                                @param[in] ARG1 Total capacity of the region at ARG0
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgMM_Set_U08_0xFF( TgVOID_PU OUT0, TgRSIZE_C ARG1 );

                                            /** @brief Copy the contents at ARG2 into the region at ARG0 up to a maximum of the minimum of (ARG1, ARG3)
                                                @param[out] OUT0 Pointer to the starting location of a region of memory (destination)
                                                @param[in] ARG1 Total capacity of the region at ARG0
                                                @param[in] ARG2 Pointer to the starting location of a region of memory (source)
                                                @param[in] ARG3 Total capacity of the region at ARG2
                                                @return A negative result if ARG0 is less than ARG1, zero if both are equal and positive otherwise */
TgEXTN TgSINT_F32                           tgMM_Compare( TgVOID_CPU OUT0, TgRSIZE_C ARG1, TgVOID_CPU ARG2, TgRSIZE_C ARG3 );

/** @} TGS_COMMON_BASE_API_MEMORY */


/* ---- Time --------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/** @addtogroup TGS_COMMON_BASE_API_TIME */
/** @{ */

                                            /** @brief Initialize the ability to track, query and measure time */
TgEXTN TgVOID                               tgTM_Init( TgVOID );

                                            /** @return The rawest (as close to the hardware) measure of time, normally cpu ticks since TM_Init*/
TgEXTN TgSINT_F64                           tgTM_Query_Counter_Tick( TgVOID );

                                            /** @return A conversion of the tick count argument as milliseconds
                                                @param[in] ARG The number of ticks to convert */
TgEXTN TgFLOAT32                            tgTM_Counter_Tick_To_MilliSeconds( TgSINT_F64_C ARG );

                                            /** @return The number of milliseconds since TM_Init */
TgEXTN TgFLOAT32                            tgTM_Query_Time( TgVOID );


                                            /** @return The current perceived time for this channel
                                                @param[in] ARG Time channel identifier */
TgEXTN TgFLOAT32                            tgTM_Channel_Query_Time( ETgTIMER_CHANNEL_C ARG );

                                            /** @return The current perceived elapsed time for this channel, since it was last reset
                                                @param[in] ARG Time channel identifier */
TgEXTN TgFLOAT32                            tgTM_Channel_Elapsed_Time( ETgTIMER_CHANNEL_C ARG );

                                            /** @brief Reinitialize the starting time for the channel 
                                                @param[in] ARG Time channel identifier */
TgEXTN TgVOID                               tgTM_Channel_Reset( ETgTIMER_CHANNEL_C ARG );

                                            /** @brief Allow the channel continue to be updated
                                                @param[in] ARG Time channel identifier */
TgEXTN TgVOID                               tgTM_Channel_Start( ETgTIMER_CHANNEL_C ARG );

                                            /** @brief Prevent future updates from modifying the channels perceived time
                                                @param[in] ARG Time channel identifier */
TgEXTN TgVOID                               tgTM_Channel_Stop( ETgTIMER_CHANNEL_C ARG );

                                            /** @brief Update the channel's perceived time
                                                @param[in] ARG Time channel identifier */
TgEXTN TgVOID                               tgTM_Channel_Update( ETgTIMER_CHANNEL_C ARG );

                                            /** @brief Step the channel's perceived time by the given step size
                                                @param[in] ARG0 Time channel identifier
                                                @param[in] ARG1 Time in milliseconds as the step size */
TgEXTN TgVOID                               tgTM_Channel_Step( ETgTIMER_CHANNEL_C ARG0, TgFLOAT32_C ARG1 );

/** @} TGS_COMMON_BASE_API_TIME */


/* ---- IO ----------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/** @addtogroup TGS_COMMON_BASE_API_IO */
/** @{ */

                                            /** @brief File_Open
                                                @param[in] ARG0 Full path
                                                @param[in] ARG1 Total capacity of the string in ARG0
                                                @param[in] ARG2 FILE_IO_ACCESS Mask
                                                @return Resulting file identifier or invalid (zero) otherwise */
TgEXTN TgSINT_PTR                           tgIO_File_Open( TgCHAR_MB_CPC ARG0, TgRSIZE_C ARG1, TgSINT_F32_C ARG2 );

                                            /** @brief File_Read
                                                @param[out] OUT0 Pointer to region of memory used to store the read results
                                                @param[in] ARG1 File identifier
                                                @param[in] ARG2 The maximum number of bytes to read from file object ARG1
                                                @return The number of bytes read */
TgEXTN TgRSIZE                              tgIO_File_Read( TgVOID_P OUT0, TgSINT_PTR_C ARG1, TgRSIZE ARG2 );

                                            /** @brief File_Write
                                                @param[in] ARG0 File identifier
                                                @param[in] ARG1 Pointer to the sourcing region of memory
                                                @param[in] ARG2 The number of bytes to write to the file object ARG1
                                                @return The number of bytes written */
TgEXTN TgRSIZE                              tgIO_File_Write( TgSINT_PTR_C ARG0, TgVOID_CP ARG1, TgRSIZE ARG2 );

                                            /** @brief File_Flush
                                                @param[in] ARG File identifier
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgIO_File_Flush( TgSINT_PTR_C ARG );

                                            /** @brief File_Close
                                                @param[in] ARG File identifier
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgIO_File_Close( TgSINT_PTR_C ARG );

                                            /** @brief File_Valid
                                                @param[in] ARG File identifier */
TgEXTN TgBOOL                               tgIO_File_Valid( TgSINT_PTR_C ARG );

                                            /** @brief Change the current access location in the file
                                                @param[in] ARG0 File identifier
                                                @param[in] ARG1 Seek Mode
                                                @param[in] ARG2 Seek Position
                                                @return The resulting new position in the file */
TgEXTN TgSINT_MAX                           tgIO_File_Seek( TgSINT_PTR_C ARG0, ETgIO_SEEK_C ARG1, TgSINT_MAX_C ARG2 );

                                            /** @return The size of the file
                                                @param[in] ARG File identifier */
TgEXTN TgRSIZE                              tgIO_File_Size( TgSINT_PTR_C ARG );

                                            /** @brief Make the given directory
                                                @param[in] ARG0 Full path
                                                @param[in] ARG1 Total capacity of the string in ARG0
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgIO_Directory_Make( TgCHAR_MB_CPC ARG0, TgRSIZE_C ARG1 );

                                            /** @brief Remove the given directory, if it exists 
                                                @param[in] ARG0 Full path
                                                @param[in] ARG1 Total capacity of the string in ARG0
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgIO_Directory_Remove( TgCHAR_MB_CPC ARG0, TgRSIZE_C ARG1 );

                                            /** @brief Check to see if a directory exists
                                                @param[in] ARG0 Full path
                                                @param[in] ARG1 Total capacity of the string in ARG0 */
TgEXTN TgBOOL                               tgIO_Directory_Exists( TgCHAR_MB_CPC ARG0, TgRSIZE_C ARG1 );

                                            /** @brief File_Delete
                                                @param[in] ARG0 Full path
                                                @param[in] ARG1 Total capacity of the string in ARG0
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgIO_File_Delete( TgCHAR_MB_CPC ARG0, TgRSIZE_C ARG1 );

                                            /** @brief Copy the source file to the destination file
                                                @param[in] ARG0 Full path for the destination file*/
                                            /** @param[in] ARG1 Total capacity of the string in ARG0
                                                @param[in] ARG2 Full path for the source file*/
                                            /** @param[in] ARG3 Total capacity of the string in ARG0
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgIO_File_Copy( TgCHAR_MB_CPC ARG0, TgRSIZE_C ARG1, TgCHAR_MB_CPC ARG2, TgRSIZE_C ARG3 );

                                            /** @brief Move (or rename) the source to the destination file 
                                                @param[in] ARG0 Full path for the destination file*/
                                            /** @param[in] ARG1 Total capacity of the string in ARG0
                                                @param[in] ARG2 Full path for the source file*/
                                            /** @param[in] ARG3 Total capacity of the string in ARG0
                                                @return KTgS_OK on success and KTgE_FAIL (or other failure error code) otherwise */
TgEXTN TgRESULT                             tgIO_File_Move( TgCHAR_MB_CPC ARG0, TgRSIZE_C ARG1, TgCHAR_MB_CPC ARG2, TgRSIZE_C ARG3 );

                                            /** @brief Check to see if the given file exists
                                                @param[in] ARG0 Full path
                                                @param[in] ARG1 Total capacity of the string in ARG0 */
TgEXTN TgBOOL                               tgIO_File_Exists( TgCHAR_MB_CPC ARG0, TgRSIZE_C ARG1 );

/** @} TGS_COMMON_BASE_API_IO */


/* =============================================================================================================================================================================== */
#endif
