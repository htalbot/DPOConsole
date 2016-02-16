
#include "test_DPOConsoleAppLayer.h"

int main(int, char *[])
{
    Test_DPOConsoleAppLayer app;

    if (!app.run())
    {
        // log
        return -1;
    }

    return 0;
}


