project(HelloChocWasm VERSION 0.0.1)

set (BaseTargetName HelloChocWasm)

# Add executable target
if (DEFINED EMSCRIPTEN)
    add_executable(${BaseTargetName})

    # Refer: https://stackoverflow.com/questions/75594285/emscripten-in-cmake-doesnt-output-html-file-when-i-setcmake-executable-suffix
    # set(CMAKE_EXECUTABLE_SUFFIX ".html")
    # set(CMAKE_EXECUTABLE_SUFFIX ".js")
    set(CMAKE_EXECUTABLE_SUFFIX ".wasm")

    set_target_properties(${BaseTargetName} PROPERTIES COMPILE_FLAGS "-Os -s SIDE_MODULE=1 ")
    set_target_properties(${BaseTargetName} PROPERTIES LINK_FLAGS    "-Os -s WASM=1 -s SIDE_MODULE=1 -s STANDALONE_WASM --no-entry")
else()
    add_library(${BaseTargetName} SHARED calc.cpp)
endif()

target_sources(${BaseTargetName}
    PRIVATE
        Source/Main.cpp
        Source/Calc.cpp
        Source/Calc.h)

target_compile_features(${BaseTargetName}
    PUBLIC
        cxx_std_17)

target_include_directories(${BaseTargetName}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../External/choc)