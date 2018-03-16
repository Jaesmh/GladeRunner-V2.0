#include "GameSystem.h"

GameSystem::GameSystem()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cerr << "SDL was unable to initialize correctly... | Error: " << SDL_GetError() << std::endl;
		ShutDown();
	}
	
	else if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
	{
		std::cerr << "SDL_Mixer was unable to initialize correctly... | Error: " << SDL_GetError() << std::endl;
		ShutDown();
	}

	else if (!IMGFlag & IMG_Init(IMGFlag) == -1)
	{
		std::cerr << "SDL_Image was unable to initialize correctly... | Error: " << SDL_GetError() << std::endl;
		ShutDown();
	}

	else if(TTF_Init() == -1)
	{
		std::cerr << "SDL_TTF was unable to initialize correctly... | Error: " << SDL_GetError() << std::endl;
		ShutDown();
	}

	else
	{
		SDL_CreateWindowAndRenderer(540, 540, NULL, &Window, &Renderer);
		SDL_SetWindowTitle(Window, "GladeRunner");
		_IsClosed = false;
	}
}


GameSystem::~GameSystem()
{
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	atexit(Mix_CloseAudio);
	atexit(TTF_Quit);
	atexit(IMG_Quit);
	atexit(SDL_Quit);
}

void GameSystem::PollEvents()
{
	while (SDL_PollEvent(&Event))
	{
		switch (Event.type)
		{
		case SDL_QUIT:
			SDL_Quit();
			ShutDown();
			break;
		default:
			break;
		}
	}
}

void GameSystem::Render() const
{
	SDL_RenderPresent(Renderer);
	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);
	SDL_RenderClear(Renderer);
}

void GameSystem::ShutDown() const
{
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	Mix_CloseAudio();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void GameSystem::CapFPS()
{
	FrameStart = SDL_GetTicks();
	FrameTime = SDL_GetTicks() - FrameStart;
	if (FrameDelay > FrameTime)
	{
		SDL_Delay(FrameDelay - FrameTime);
	}
}

void GameSystem::Loop()
{
	while (_IsClosed == false)
	{
		Render();
		PollEvents();
	}
}
