#!/usr/bin/env -S deno run --allow-all

/*
This script requires the Deno runtime environment to execute.
Please refer to the official website for instructions on how to install Deno.
https://deno.com/
*/

import { prepareEmsdk } from "./tasks/prepare-emsdk.ts"
import { buildWasmModules } from "./tasks/build-wasm-modules.ts";
import { moveArtefacts } from "./tasks/move-artefacts.ts"

//============================================
await prepareEmsdk();
await buildWasmModules();
await moveArtefacts();