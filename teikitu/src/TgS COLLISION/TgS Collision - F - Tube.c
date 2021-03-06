/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Collision - F - Tube.c
    »Author«    Andrew Aye (mailto: andrew.aye@teikitu.com, https://www.andrew.aye.page)
    »Version«   5.16 / »GUID« 015482FC-A4BD-4E1C-AE49-A30E5728D73A */
/*  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */
/*  Copyright: © 2002-2020, Andrew Aye.  All Rights Reserved.
    This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation,
    either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details. You should have received a copy of the
    GNU Affero General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>. */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/* == Collision ================================================================================================================================================================== */

#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Tube-Sphere.c_inc"

#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Tube-Tube.c_inc"

#define TB_CAP_0 0
#define TB_CAP_1 0

    #define LN_CAP_0 0
    #define LN_CAP_1 0
    #define VI2(A,B) FCN_VO(A##00_##B##00)
    #define TEMPLATE__VECTOR_DIM 4
    #include "TgS Collision - F - Tube-Linear.c_inc"
    #undef VI2
    #undef LN_CAP_0
    #undef LN_CAP_1

    #define LN_CAP_0 1
    #define LN_CAP_1 0
    #define VI2(A,B) FCN_VO(A##00_##B##10)
    #define TEMPLATE__VECTOR_DIM 4
    #include "TgS Collision - F - Tube-Linear.c_inc"
    #undef VI2
    #undef LN_CAP_0
    #undef LN_CAP_1

    #define LN_CAP_0 1
    #define LN_CAP_1 1
    #define VI2(A,B) FCN_VO(A##00_##B##11)
    #define TEMPLATE__VECTOR_DIM 4
    #include "TgS Collision - F - Tube-Linear.c_inc"
    #undef VI2
    #undef LN_CAP_0
    #undef LN_CAP_1

#undef TB_CAP_0
#undef TB_CAP_1

#define TB_CAP_0 1
#define TB_CAP_1 0

    #define LN_CAP_0 0
    #define LN_CAP_1 0
    #define VI2(A,B) FCN_VO(A##10_##B##00)
    #define TEMPLATE__VECTOR_DIM 4
    #include "TgS Collision - F - Tube-Linear.c_inc"
    #undef VI2
    #undef LN_CAP_0
    #undef LN_CAP_1

    #define LN_CAP_0 1
    #define LN_CAP_1 0
    #define VI2(A,B) FCN_VO(A##10_##B##10)
    #define TEMPLATE__VECTOR_DIM 4
    #include "TgS Collision - F - Tube-Linear.c_inc"
    #undef VI2
    #undef LN_CAP_0
    #undef LN_CAP_1

    #define LN_CAP_0 1
    #define LN_CAP_1 1
    #define VI2(A,B) FCN_VO(A##10_##B##11)
    #define TEMPLATE__VECTOR_DIM 4
    #include "TgS Collision - F - Tube-Linear.c_inc"
    #undef VI2
    #undef LN_CAP_0
    #undef LN_CAP_1

#undef TB_CAP_0
#undef TB_CAP_1

#define TB_CAP_0 1
#define TB_CAP_1 1

    #define LN_CAP_0 0
    #define LN_CAP_1 0
    #define VI2(A,B) FCN_VO(A##11_##B##00)
    #define TEMPLATE__VECTOR_DIM 4
    #include "TgS Collision - F - Tube-Linear.c_inc"
    #undef VI2
    #undef LN_CAP_0
    #undef LN_CAP_1

    #define LN_CAP_0 1
    #define LN_CAP_1 0
    #define VI2(A,B) FCN_VO(A##11_##B##10)
    #define TEMPLATE__VECTOR_DIM 4
    #include "TgS Collision - F - Tube-Linear.c_inc"
    #undef VI2
    #undef LN_CAP_0
    #undef LN_CAP_1

    #define LN_CAP_0 1
    #define LN_CAP_1 1
    #define VI2(A,B) FCN_VO(A##11_##B##11)
    #define TEMPLATE__VECTOR_DIM 4
    #include "TgS Collision - F - Tube-Linear.c_inc"
    #undef VI2
    #undef LN_CAP_0
    #undef LN_CAP_1

#undef TB_CAP_0
#undef TB_CAP_1
