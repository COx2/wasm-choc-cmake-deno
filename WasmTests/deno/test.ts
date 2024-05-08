import "jsr:/@kitsonk/xhr";
import Module from "../lib/choc-emscripten.js";

const moduleInstance = await Module({
    onRuntimeInitialized() {
      console.log("Module: instance created.");
    }
});

console.log(moduleInstance.getChocPlatformName());
console.log(moduleInstance.getStringFromCpp());
console.log(moduleInstance.lerp(1, 2, 100));
console.log(moduleInstance.getMP3AudioFileSuffixes());
