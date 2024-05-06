#include <platform/choc_Platform.h>
#include <platform/choc_Assert.h>
#include <audio/choc_AudioFileFormat_MP3.h>
#include <string>

std::string getChocPlatformName() {
    return std::string("CHOC_OPERATING_SYSTEM_NAME: ") + std::string(CHOC_OPERATING_SYSTEM_NAME);
}

std::string getStringFromCpp() {
    return "Hello from C++!";
}

void callMP3AudioFileFormat()
{
    choc::audio::MP3AudioFileFormat mp3_audio_file;
}

std::string getMP3AudioFileSuffixes()
{
    choc::audio::MP3AudioFileFormat mp3_audio_file;
    return  mp3_audio_file.getFileSuffixes();
}

float lerp(float a, float b, float t) {
    return (1 - t) * a + t * b;
}

#ifdef __EMSCRIPTEN__
#include <emscripten/bind.h>
EMSCRIPTEN_BINDINGS(my_module) {
    emscripten::function("lerp", &lerp);
    emscripten::function("getStringFromCpp", &getStringFromCpp);
    emscripten::function("getChocPlatformName", &getChocPlatformName);
    emscripten::function("callMP3AudioFileFormat", &callMP3AudioFileFormat);
    emscripten::function("getMP3AudioFileSuffixes", &getMP3AudioFileSuffixes);
}
#endif
