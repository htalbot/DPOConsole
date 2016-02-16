
#ifndef __DPOCONSOLE_H__
#define __DPOCONSOLE_H__

#ifdef ACE_WIN32
#pragma warning (disable: 4251)
#endif

#include "DPOConsole/DPOCONSOLE_Export.h"
#include "DPOConsole/version.h"
#include <string>


namespace DPOConsole_ns
{
    extern "C" DPOCONSOLE_Export void DPOConsole_get_version(int & major, int & minor, int & patch);

    class DPOCONSOLE_Export DPOConsole
    {
    public:
        DPOConsole(const std::string & title, unsigned short width, unsigned short height);
        void show(bool show = true, bool maximized = false);
        void resize(unsigned short width, unsigned short height, bool maximized = false);

    protected:
        std::string title_;
        unsigned short width_;
        unsigned short height_;
        bool console_app_;
#ifdef ACE_WIN32
        CONSOLE_SCREEN_BUFFER_INFO csbi_;
#endif
    };
} // DPOConsole_ns namespace


#endif // __DPOCONSOLE_H__
