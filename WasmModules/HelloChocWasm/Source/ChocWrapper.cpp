#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
// #include <emscripten/bind.h>
#else
#define EMSCRIPTEN_KEEPALIVE
#endif

// #include <platform/choc_Platform.h>

// #include <iostream>
// #include <string>
// #include <vector>

extern "C" 
{
    // EMSCRIPTEN_KEEPALIVE const char* getPlatformName()
    // {
        // const auto str = std::string("Hello with CHOC, this platform is: ") + std::string(CHOC_OPERATING_SYSTEM_NAME);
        // return str.c_str();
        // return CHOC_OPERATING_SYSTEM_NAME;
        // return "my platform";
    // }
}

// namespace
// {

// void use_vector_string(const std::vector<std::string> &vec)
// {
//     std::cout << "size() = " << vec.size() << ", capacity()=" << vec.capacity() << "\n";
//     for (const auto &str : vec) {
//         std::cout << "vec[]=|" << str << "|\n";
//     }
// }

// }

// EMSCRIPTEN_BINDINGS(EmbindVectorStringDemo)
// {
//     emscripten::register_vector<std::string>("StringList");
//     emscripten::function("use_vector_string", &use_vector_string);
// }