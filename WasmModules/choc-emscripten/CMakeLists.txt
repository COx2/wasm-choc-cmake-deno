project(choc-emscripten VERSION 0.0.1)

set (BaseTargetName choc-emscripten)

# Add executable target
add_executable(${BaseTargetName})

# Refer: https://stackoverflow.com/questions/75594285/emscripten-in-cmake-doesnt-output-html-file-when-i-setcmake-executable-suffix
# set(CMAKE_EXECUTABLE_SUFFIX ".html")
# set(CMAKE_EXECUTABLE_SUFFIX ".js")
# set(CMAKE_EXECUTABLE_SUFFIX ".wasm")

target_compile_options(${BaseTargetName} 
    PRIVATE 
        -Os --bind 
        "SHELL:-s WASM=1" 
        "SHELL:-s MODULARIZE=1" 
        "SHELL:-s EXPORT_ES6=1" 
        "SHELL:-s SINGLE_FILE=1" 
        "SHELL:-s ASSERTIONS=2")

# target_link_options(${BaseTargetName} 
#     PRIVATE 
#         -Os --bind 
#         "SHELL:-s WASM=1" 
#         "SHELL:-s MODULARIZE=1" 
#         "SHELL:-s EXPORT_ES6=1" 
#         "SHELL:-s SINGLE_FILE=1" 
#         "SHELL:-s ASSERTIONS=2")

target_sources(${BaseTargetName}
    PRIVATE
        Source/EmscriptenBinding.cpp)

target_compile_features(${BaseTargetName}
    PUBLIC
        cxx_std_17)

target_include_directories(${BaseTargetName}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../../External/choc)

target_link_libraries(${BaseTargetName}
    PRIVATE
        embind)

# Add cmake install task for this project.
if(TARGET ${BaseTargetName})
    set(WASM_PRODUCT_FILE "$<TARGET_FILE:${BaseTargetName}>")
    message("WASM_PRODUCT_FILE: ${WASM_PRODUCT_FILE}")

    install(FILES "${WASM_PRODUCT_FILE}"
            DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/../../WasmTests"
            COMPONENT ${BaseTargetName})
endif()