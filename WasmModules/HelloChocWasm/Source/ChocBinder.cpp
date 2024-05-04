#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#include <emscripten/bind.h>
#else
#define EMSCRIPTEN_KEEPALIVE
#endif

#include <platform/choc_Platform.h>

#include <iostream>
#include <string>
#include <vector>

// namespace
// {

std::string get_platform_name()
{
    return std::string(CHOC_OPERATING_SYSTEM_NAME);
}

void use_vector_string(const std::vector<std::string> &vec)
{
    std::cout << "size() = " << vec.size() << ", capacity()=" << vec.capacity() << "\n";
    for (const auto &str : vec) {
        std::cout << "vec[]=|" << str << "|\n";
    }
}

// }

EMSCRIPTEN_BINDINGS(EmbindVectorStringDemo)
{
    emscripten::register_vector<std::string>("StringList");
    emscripten::function("use_vector_string", &use_vector_string);
    emscripten::function("get_platform_name", &get_platform_name);
}