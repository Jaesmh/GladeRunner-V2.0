#include "LAudio.h"

LAudio::~LAudio()
{
	SDL_CloseAudioDevice(DeviceID);
	SDL_FreeWAV(WavBuffer);
}

void LAudio::LoadAudio(const char* file_path)
{
	SDL_LoadWAV(file_path, &WavSpec, &WavBuffer, &WavLength);
	DeviceID = SDL_OpenAudioDevice(NULL, NULL, &WavSpec, NULL, NULL);
}

void LAudio::PlayAudio()
{
	SDL_QueueAudio(DeviceID, WavBuffer, WavLength);
	SDL_PauseAudio(DeviceID);
}