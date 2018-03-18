#ifndef GAMESYSTEM_H
#define GAMESYSTEM_H

#include <iostream>
#include <string>
#include <Windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "Objects.h"
#include "LAudio.h"
#include "Entity.h"

class GameSystem
{
protected:
	SDL_Renderer* Renderer = nullptr;
	SDL_Window* Window = nullptr;
	SDL_Event Event;
public:
	GameSystem();
	~GameSystem();
	void LoadMap(const char* file_path);
	void DrawMap();
	inline bool IsClosed() { return _IsClosed; }
	void PollEvents();
	void Render() const;
	virtual void ShutDown() const;
	void CapFPS();
	void Update();
	void GameLoop();
	void Draw(const char* Msg, int x, int y, int r, int g, int b, int a, int Size);
	void Draw(Objects O);
private:
	const int FPS = 60;
	Uint32 FrameStart;
	int FrameTime;
	const int FrameDelay = 1000 / FPS;
	bool _IsClosed = true;
	bool _Success = true;
	int WINFlag = SDL_WINDOW_FULLSCREEN;
	int IMGFlag = IMG_INIT_PNG;
};

#endif //GAMESYSTEM_H