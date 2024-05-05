# wasm-choc-cmake-deno

Research project.

## How to build

### Prerequisites

In general, having a setup that allows building emsdk should be sufficient.

+ Git: 2.3 or later - Refer to: [Git](https://git-scm.com/)
+ Deno: 1.42 or later - Refer to: [Deno](https://deno.com/)
+ CMake: 3.25 or later - Refer to: [CMake](https://cmake.org/)
+ Ninja-build: 1.11 or later - Refer to: [Ninja](https://ninja-build.org/)

### Run build scripts

#### Cross-Platform shell-script by Deno

This script requires the Deno runtime environment to execute.
Please refer to the official website for instructions on how to install Deno.
https://deno.com/

Deno:
```sh
deno run --allow-all ./Scripts/deno/run-all.ts
```

### Test module

#### Run test program with Deno

This test program requires the Deno runtime environment to execute.
Please refer to the official website for instructions on how to install Deno.
https://deno.com/

Deno:
```sh
deno run --allow-all ./WasmTests/test.ts
```

## Attention Regarding Licenses

If you are using this project to create and distribute software, please ensure compliance with the licenses of the following software libraries:

+ [CHOC](https://github.com/Tracktion/choc)  
+ [emsdk](https://github.com/emscripten-core/emsdk)
