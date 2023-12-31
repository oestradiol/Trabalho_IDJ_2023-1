#pragma once

#define INCLUDE_SDL_MIXER
#include "../../SDL_include.h"

#include <string>

class Music {
public:
    Music();
    Music(const std::string& file);
    ~Music();

    void Play(int times = -1);
    void Stop(int msToStop = 1500);
    void Open(const std::string& file);
    bool IsOpen() const;

private:
    std::shared_ptr<Mix_Music> music;
};

inline bool Music::IsOpen() const {
    return music != nullptr;
}