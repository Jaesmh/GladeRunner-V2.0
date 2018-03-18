#ifndef LAUDIO_H
#define LAUDIO_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_mixer.h>

class LAudio
{
public:
	LAudio(){}
	~LAudio();
	void LoadAudio(const char* file_path);
	void PlayAudio();
private:
	SDL_AudioSpec WavSpec;
	Uint32 WavLength;
	Uint8 *WavBuffer;
	SDL_AudioDeviceID DeviceID;

};

#endif //LAUDIO_H