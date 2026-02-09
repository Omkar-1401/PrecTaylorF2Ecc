/* lib/LALConfig.h.  Generated from LALConfig.h.in by configure.  */
/* only include this file if LAL's config.h has not been included */
#ifndef LAL_VERSION

/* LAL Version */
#define LAL_VERSION "7.7.0.1"

/* LAL Version Major Number  */
#define LAL_VERSION_MAJOR 7

/* LAL Version Minor Number  */
#define LAL_VERSION_MINOR 7

/* LAL Version Micro Number  */
#define LAL_VERSION_MICRO 0

/* LAL Version Devel Number  */
#define LAL_VERSION_DEVEL 1

/* Define if using CUDA library */
/* #undef LAL_CUDA_ENABLED */

/* Define if using fftw3 library */
#define LAL_FFTW3_ENABLED 1

/* Define if using HDF5 library */
#define LAL_HDF5_ENABLED 1

/* Define if using fftw3 aligned memory optimizations */
/* #undef LAL_FFTW3_MEMALIGN_ENABLED */

/* Disable LAL memory functions */
/* #undef LAL_MEMORY_FUNCTIONS_DISABLED */

/* Use pthread mutex lock for threadsafety */
#define LAL_PTHREAD_LOCK 1

#endif /* LAL_VERSION */
