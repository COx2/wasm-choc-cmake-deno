#include <platform/choc_Platform.h>
#include <platform/choc_Assert.h>
#include <string>

std::string getChocPlatformName() {
    return std::string("CHOC_OPERATING_SYSTEM_NAME: ") + std::string(CHOC_OPERATING_SYSTEM_NAME);
}

std::string getStringFromCpp() {
    return "Hello from C++!";
}

float lerp(float a, float b, float t) {
    return (1 - t) * a + t * b;
}

#ifdef __EMSCRIPTEN__
#include <emscripten/bind.h>
EMSCRIPTEN_BINDINGS(my_module) {
    emscripten::function("lerp", &lerp);
    emscripten::function("getStringFromCpp", &getStringFromCpp);
    emscripten::function("getChocPlatformName", &getChocPlatformName);
}
#endif
