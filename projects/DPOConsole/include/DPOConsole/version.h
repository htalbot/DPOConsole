
#pragma once

#define DPOCONSOLE_MAJOR 1
#define DPOCONSOLE_MINOR 0
#define DPOCONSOLE_PATCH 3


#if defined _MSC_VER
#   ifdef _DEBUG
        const char DPOCONSOLE_DebugFlag[] = "DEBUG";
#   else
        const char DPOCONSOLE_DebugFlag[] = "RELEASE";
#   endif
#else
#   ifdef DEBUG
        const char DPOCONSOLE_DebugFlag[] = "DEBUG";
#   else
        const char DPOCONSOLE_DebugFlag[] = "RELEASE";
#   endif
#endif


