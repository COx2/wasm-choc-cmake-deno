#!/usr/bin/env -S deno run --allow-all

/*
This script requires the Deno runtime environment to execute.
Please refer to the official website for instructions on how to install Deno.
https://deno.com/
*/

import { $ } from "https://deno.land/x/dax/mod.ts";
import { fromFileUrl } from "https://deno.land/std/path/mod.ts";

//============================================
export async function prepareEmsdk() {
    console.log("Deno.cwd(): " + Deno.cwd());

    const __root_directory = fromFileUrl(new URL("../../", import.meta.url));
    Deno.chdir(__root_directory);

    console.log("Deno.cwd(): " + Deno.cwd());

    const __emsdk_directory = __root_directory + "./External/emsdk/";
    Deno.chdir(__emsdk_directory);

    console.log("Deno.cwd(): " + Deno.cwd());

    const platform = Deno.build.os;

    console.log("Deno.build.os: " + platform.toString())

    if(platform.toString() === "windows")
    {
        await $`./emsdk.bat install latest`;
        await $`./emsdk.bat activate latest`;
    }
    else if(platform.toString() === "darwin")
    {
        await $`./emsdk install latest`;
        await $`./emsdk activate latest`;
    }
    else if(platform.toString() === "linux")
    {
        await $`./emsdk install latest`;
        await $`./emsdk activate latest`;
    }
}

//============================================
await prepareEmsdk();
