/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
/*  »Project«   Teikitu Gaming System (TgS) (∂)
    »File«      TgS Collision - F - Convex.c
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
#include "TgS Collision - F - Convex-Box.c_inc"

#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Convex-Capsule.c_inc"

#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Convex-Cylinder.c_inc"

#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Convex-Plane.c_inc"

#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Convex-Sphere.c_inc"

#define TEMPLATE__VECTOR_DIM 4
#include "TgS Collision - F - Convex-Triangle.c_inc"
