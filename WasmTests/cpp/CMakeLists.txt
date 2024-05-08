cmake_minimum_required(VERSION 3.16)

project(test-choc-emscripten VERSION 0.0.1)

#First, we'll add the CMake folder, incase we'll need to find_package later:
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(DbgHelp REQUIRED)
if(DBGHELP_FOUND)
    include_directories(${DBGHELP_INCLUDE_DIR})
endif()
set(HAVE_DBGHELP ${DBGHELP_FOUND})

set(V8_LOCATION "C:/SDKs/V8/v8_Windows_x64")
set(V8_BUILD_NAME "arm64.release")

# V8 screws up the sanitizer...
if (DEFINED V8_LOCATION)
    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCHOC_V8_AVAILABLE=1 -DV8_COMPRESS_POINTERS=1 -DV8_ENABLE_SANDBOX=1")
    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCHOC_V8_AVAILABLE=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCHOC_V8_AVAILABLE=1")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj ")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
endif()

#static linking in Windows
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

#For building in multibyte language environment.
if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  add_compile_options(/utf-8)
endif()

set (BaseTargetName test-choc-emscripten)

# Add executable target
add_executable(${BaseTargetName})

target_sources(${BaseTargetName}
    PRIVATE
        main.cpp)

target_compile_features(${BaseTargetName}
    PUBLIC
        cxx_std_17)

target_include_directories(${BaseTargetName}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../../External/choc
        ${CMAKE_CURRENT_SOURCE_DIR}/../lib)

# On OSX, need to add the WebKit framework for WebView functionality
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    target_link_libraries(${BaseTargetName} "-framework WebKit -framework CoreServices")
endif()

# This is an example of how to link the packages required for WebView on Linux
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    find_package(PkgConfig REQUIRED)
    pkg_check_modules (gtk3 REQUIRED gtk+-3.0 IMPORTED_TARGET)
    pkg_check_modules (webkit2 REQUIRED webkit2gtk-4.0 IMPORTED_TARGET)
    target_link_libraries (${BaseTargetName} PUBLIC pthread PkgConfig::gtk3 PkgConfig::webkit2)
endif()

if (DEFINED V8_LOCATION)
    target_include_directories(${BaseTargetName}  PRIVATE "${V8_LOCATION}")
    target_link_directories(${BaseTargetName}  PRIVATE "${V8_LOCATION}")
    target_link_libraries(${BaseTargetName}  v8_monolith ${DBGHELP_LIBRARIES} winmm.lib)
    # target_link_libraries(${BaseTargetName}  "-lv8_monolith -lv8_libbase -lv8_libplatform")
endif()

enable_testing()

add_test(NAME ${BaseTargetName} COMMAND ${BaseTargetName})
