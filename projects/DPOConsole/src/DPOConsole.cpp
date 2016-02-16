
#include "DPOConsole/DPOConsole.h"
#include "DPOConsole/version.h"
#include "ace/Log_Msg.h"

namespace DPOConsole_ns
{
    void DPOConsole_get_version(int & major, int & minor, int & patch)
    {
        major = DPOCONSOLE_MAJOR;
        minor = DPOCONSOLE_MINOR;
        patch = DPOCONSOLE_PATCH;
    }

    DPOConsole::DPOConsole(const std::string & title, unsigned short width, unsigned short height)
    : title_(title)
    , width_(width)
    , height_(height)
    , console_app_(false)
    {
        #ifdef ACE_WIN32
        console_app_ = (GetStdHandle(STD_OUTPUT_HANDLE) != 0);
        #else
        #endif
    }

    void DPOConsole::show(bool show, bool maximized)
    {
#ifdef ACE_WIN32
        if (show)
        {
            resize(width_, height_, maximized);
        }
        else
        {
            HWND hwnd = GetConsoleWindow();
            ShowWindow(hwnd, SW_HIDE);
        }
#else
        ACE_UNUSED_ARG (show);
        ACE_UNUSED_ARG (maximized);
#endif
    }

    void DPOConsole::resize(unsigned short width, unsigned short height, bool maximized)
    {
#ifdef ACE_WIN32
        HANDLE con_out = GetStdHandle(STD_OUTPUT_HANDLE);

        BOOL rc = AllocConsole();
        if (rc)
        {
            if (!console_app_)
            {
                freopen("conin$","r",stdin);
                freopen("conout$","w",stdout);
                freopen("conout$","w",stderr);
            }
        }

        //printf("size %d, %d...\n", width, height);

        if (con_out)
        {
            COORD c;
            c.X = width;
            c.Y = 9999;
            SetConsoleScreenBufferSize(con_out, c);

            _CONSOLE_SCREEN_BUFFER_INFO info;
            GetConsoleScreenBufferInfo(con_out,&info);

            SMALL_RECT r;
            r.Left = r.Top = 0;
            r.Right = std::min((int)width, (int)info.dwMaximumWindowSize.X) - 1;
            r.Bottom = std::min((int)height, (int)info.dwMaximumWindowSize.Y) - 1;
            SetConsoleWindowInfo(con_out, TRUE, &r);
        }

        width_ = width;
        height_ = height;

        SetConsoleTitle(title_.c_str());

        HWND hwnd = GetConsoleWindow();
        HMENU hmenu = GetSystemMenu(hwnd, FALSE);
        DeleteMenu(hmenu, SC_CLOSE, MF_BYCOMMAND);

        if (maximized)
        {
            ShowWindow(hwnd, SW_SHOWMAXIMIZED);
        }
        else
        {
            ShowWindow(hwnd, SW_SHOWNOACTIVATE);
        }
#else
        ACE_UNUSED_ARG (width);
        ACE_UNUSED_ARG (height);
        ACE_UNUSED_ARG (maximized);
#endif
    }

} // DPOConsole_ns namespace
