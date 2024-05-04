import { fromFileUrl } from "https://deno.land/std/path/mod.ts";

console.log(Deno.cwd());

const __file_directory = fromFileUrl(new URL("./", import.meta.url));

const wasmCode = await Deno.readFile(__file_directory + "/HelloChocWasm.wasm");

const wasmModule = new WebAssembly.Module(wasmCode);

console.log(WebAssembly.Module.exports(wasmModule));
console.log(WebAssembly.Module.imports(wasmModule));

const wasmInstance = new WebAssembly.Instance(wasmModule);

// const add = wasmInstance.exports.add as CallableFunction;
// console.log(add(1,2));

// const sub = wasmInstance.exports.sub as CallableFunction;
// console.log(sub(1,2));

// const getPlatformName = wasmInstance.exports.getPlatformName as CallableFunction;
// console.log(getPlatformName().toString());

///////
// const StringList = wasmInstance.exports.StringList as CallableFunction;
// const use_vector_string = wasmInstance.exports.use_vector_string as CallableFunction;

// const vec = StringList();  // Allocates std::vector<std::string> which is managed by JS
// vec.push_back("hello");  // std::string and JavaScript strings are automatically interconverted
// vec.push_back("world");
// vec.push_back("1234");
// use_vector_string(vec);
// vec.delete();  // Required to avoid C++ memory leaks and undestructed object
