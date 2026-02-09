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
 * LALMetaIOVCSInfo.h - LALMetaIO VCS Information Header
 */

/** \cond DONT_DOXYGEN */

#ifndef _LALMETAIOVCSINFOHEADER_H
#define _LALMETAIOVCSINFOHEADER_H

#include <lal/LALVCSInfoType.h>
#include <lal/LALMetaIOVCSInfo.h>
#include <lal/LALMetaIOConfig.h>

#ifdef __cplusplus
extern "C" {
#endif

/* VCS information */
#define LALMETAIO_VCS_ID "cd5b9f2626ccb62c33ac3c4ecfcc5a9e42356b80"
#define LALMETAIO_VCS_DATE "2026-01-19 23:32:14 +0000"
#define LALMETAIO_VCS_BRANCH "master"
#define LALMETAIO_VCS_TAG "None"
#define LALMETAIO_VCS_AUTHOR "Leo Singer <leo.singer@ligo.org>"
#define LALMETAIO_VCS_COMMITTER "Leo Singer <leo.singer@ligo.org>"
#define LALMETAIO_VCS_CLEAN "CLEAN"
#define LALMETAIO_VCS_STATUS "CLEAN: All modifications committed"

#if LALMETAIO_VERSION_DEVEL != 0
/* VCS header/library mismatch link check function */
#define LALMETAIO_VCS_LINK_CHECK LALMETAIO_CLEAN_cd5b9f2626ccb62c33ac3c4ecfcc5a9e42356b80_VCS_HEADER_LIBRARY_MISMATCH
void LALMETAIO_VCS_LINK_CHECK(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* _LALMETAIOVCSINFOHEADER_H */

/** \endcond */
