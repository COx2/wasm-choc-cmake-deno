#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#else
#define EMSCRIPTEN_KEEPALIVE
#endif

#include <platform/choc_Platform.h>

extern "C" 
{
    EMSCRIPTEN_KEEPALIVE std::string getPlatformName()
    {
        return "Hello with CHOC, this platform is: " + CHOC_OPERATING_SYSTEM_NAME;
    }
}
