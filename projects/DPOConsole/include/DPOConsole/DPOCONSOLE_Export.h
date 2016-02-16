
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl DPOCONSOLE
// ------------------------------
#ifndef DPOCONSOLE_EXPORT_H
#define DPOCONSOLE_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (DPOCONSOLE_HAS_DLL)
#  define DPOCONSOLE_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && DPOCONSOLE_HAS_DLL */

#if !defined (DPOCONSOLE_HAS_DLL)
#  define DPOCONSOLE_HAS_DLL 1
#endif /* ! DPOCONSOLE_HAS_DLL */

#if defined (DPOCONSOLE_HAS_DLL) && (DPOCONSOLE_HAS_DLL == 1)
#  if defined (DPOCONSOLE_BUILD_DLL)
#    define DPOCONSOLE_Export ACE_Proper_Export_Flag
#    define DPOCONSOLE_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define DPOCONSOLE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* DPOCONSOLE_BUILD_DLL */
#    define DPOCONSOLE_Export ACE_Proper_Import_Flag
#    define DPOCONSOLE_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define DPOCONSOLE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* DPOCONSOLE_BUILD_DLL */
#else /* DPOCONSOLE_HAS_DLL == 1 */
#  define DPOCONSOLE_Export
#  define DPOCONSOLE_SINGLETON_DECLARATION(T)
#  define DPOCONSOLE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* DPOCONSOLE_HAS_DLL == 1 */

// Set DPOCONSOLE_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (DPOCONSOLE_NTRACE)
#  if (ACE_NTRACE == 1)
#    define DPOCONSOLE_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define DPOCONSOLE_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !DPOCONSOLE_NTRACE */

#if (DPOCONSOLE_NTRACE == 1)
#  define DPOCONSOLE_TRACE(X)
#else /* (DPOCONSOLE_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define DPOCONSOLE_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (DPOCONSOLE_NTRACE == 1) */

#endif /* DPOCONSOLE_EXPORT_H */

// End of auto generated file.
