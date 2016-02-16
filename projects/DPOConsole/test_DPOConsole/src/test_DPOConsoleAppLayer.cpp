
#include "test_DPOConsoleAppLayer.h"
#include "DPOConsole/DPOConsole.h"
#include "ace/OS.h"

using namespace DPOConsole_ns;

#include <stdio.h>

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

Test_DPOConsoleAppLayer::Test_DPOConsoleAppLayer()
{
}


bool Test_DPOConsoleAppLayer::run()
{
    printf("***** Test_DPOConsoleAppLayer (%s) *****\n\n", TEST_DPOCONSOLE_DebugFlag);

    int major, minor, patch;
    DPOConsole_get_version(major, minor, patch);
    printf("DPOConsole version: %d.%d.%d\n", major, minor, patch);

    printf("construct...\n");
    DPOConsole console("TestDPOConsole", 40, 10);
    printf("1- show...\n");
    console.show();
    ACE_OS::sleep(2);

    printf("2- hide...\n");
    console.show(false);
    ACE_OS::sleep(2);

    printf("3- resize...\n");
    console.resize(40, 10);
    ACE_OS::sleep(2);

    printf("4- resize...\n");
    console.resize(180, 40);
    ACE_OS::sleep(2);

    printf("5- hide...\n");
    console.show(false);
    ACE_OS::sleep(2);

    printf("6- resize...\n");
    console.resize(120, 20);

    ACE_OS::sleep(2);

    printf("7- resize...\n");
    console.resize(40, 10);

    ACE_OS::sleep(2);

    return true;
}

