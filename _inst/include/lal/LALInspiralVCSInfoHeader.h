/*
 * Copyright (C) 2014, 2016 Karl Wette
 * Copyright (C) 2009-2013 Adam Mercer
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with with program; see the file COPYING. If not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301 USA
 */

/*
 * LALInspiralVCSInfo.h - LALInspiral VCS Information Header
 */

/** \cond DONT_DOXYGEN */

#ifndef _LALINSPIRALVCSINFOHEADER_H
#define _LALINSPIRALVCSINFOHEADER_H

#include <lal/LALVCSInfoType.h>
#include <lal/LALInspiralVCSInfo.h>
#include <lal/LALInspiralConfig.h>

#ifdef __cplusplus
extern "C" {
#endif

/* VCS information */
#define LALINSPIRAL_VCS_ID "cd5b9f2626ccb62c33ac3c4ecfcc5a9e42356b80"
#define LALINSPIRAL_VCS_DATE "2026-01-19 23:32:14 +0000"
#define LALINSPIRAL_VCS_BRANCH "master"
#define LALINSPIRAL_VCS_TAG "None"
#define LALINSPIRAL_VCS_AUTHOR "Leo Singer <leo.singer@ligo.org>"
#define LALINSPIRAL_VCS_COMMITTER "Leo Singer <leo.singer@ligo.org>"
#define LALINSPIRAL_VCS_CLEAN "CLEAN"
#define LALINSPIRAL_VCS_STATUS "CLEAN: All modifications committed"

#if LALINSPIRAL_VERSION_DEVEL != 0
/* VCS header/library mismatch link check function */
#define LALINSPIRAL_VCS_LINK_CHECK LALINSPIRAL_CLEAN_cd5b9f2626ccb62c33ac3c4ecfcc5a9e42356b80_VCS_HEADER_LIBRARY_MISMATCH
void LALINSPIRAL_VCS_LINK_CHECK(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* _LALINSPIRALVCSINFOHEADER_H */

/** \endcond */
