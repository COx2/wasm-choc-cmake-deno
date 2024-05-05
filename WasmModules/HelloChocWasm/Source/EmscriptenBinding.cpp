#ifdef __EMSCRIPTEN__
// quick_example.cpp
#include <emscripten/bind.h>
#include <string>

std::string getStringFromCpp() {
    return "Hello from C++!";
}

float lerp(float a, float b, float t) {
    return (1 - t) * a + t * b;
}

EMSCRIPTEN_BINDINGS(my_module) {
    emscripten::function("lerp", &lerp);
}
#endif
