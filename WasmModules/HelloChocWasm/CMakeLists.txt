project(HelloJuceWasm VERSION 0.0.1)

# Refer: https://stackoverflow.com/questions/75594285/emscripten-in-cmake-doesnt-output-html-file-when-i-setcmake-executable-suffix
set(CMAKE_EXECUTABLE_SUFFIX ".html")

set (BaseTargetName HelloChocWasm)

# Add executable target
add_executable(${BaseTargetName})

target_sources(${BaseTargetName}
    PRIVATE
        Source/Main.cpp)

target_compile_features(${BaseTargetName}
    PUBLIC
        cxx_std_17)

target_include_directories(${BaseTargetName}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../External/choc)