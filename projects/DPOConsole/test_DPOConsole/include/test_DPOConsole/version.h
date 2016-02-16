
#ifndef __TEST_DPOCONSOLE_VERSION_H__
#define __TEST_DPOCONSOLE_VERSION_H__

#define TEST_DPOCONSOLE_MAJOR 1
#define TEST_DPOCONSOLE_MINOR 0
#define TEST_DPOCONSOLE_PATCH 3


#if defined _MSC_VER
#   ifdef _DEBUG
        const char TEST_DPOCONSOLE_DebugFlag[] = "DEBUG";
#   else
        const char TEST_DPOCONSOLE_DebugFlag[] = "RELEASE";
#   endif
#else
#   ifdef DEBUG
        const char TEST_DPOCONSOLE_DebugFlag[] = "DEBUG";
#   else
        const char TEST_DPOCONSOLE_DebugFlag[] = "RELEASE";
#   endif
#endif


#endif // __TEST_DPOCONSOLE_VERSION_H__
