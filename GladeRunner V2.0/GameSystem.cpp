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

	else if (IMG_Init(IMGFlag) == -1)
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
		GameLoop(); //Begin the game loop
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

void GameSystem::LoadMap(const char * file_path)
{

}

void GameSystem::DrawMap()
{
	
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
	exit(-1);
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

void GameSystem::Update()
{

}

void GameSystem::GameLoop()
{
	while (_IsClosed == false)
	{
		CapFPS();
		Render();
		PollEvents();
		Update();
	}

	ShutDown();
}

void GameSystem::Draw(const char * Msg, int x, int y, int r, int g, int b, int a, int Size)
{
	SDL_Surface* TempSurface;
	SDL_Texture* TempTexture;
	TTF_Font* Font = TTF_OpenFont("Assets/Fonts/Moon.ttf", Size);
	SDL_Color TextColor = {r, g, b, a };
	SDL_Rect TextRect;
	TempSurface = TTF_RenderText_Blended(Font, Msg, TextColor);
	TempTexture = SDL_CreateTextureFromSurface(Renderer, TempSurface);
	TextRect = { x,y,TempSurface->w, TempSurface->h };
	SDL_FreeSurface(TempSurface);
	SDL_RenderCopy(Renderer, TempTexture, nullptr, &TextRect);
	SDL_DestroyTexture(TempTexture);
}

void GameSystem::Draw(Objects O)
{
	SDL_Rect dest = O.GetDest();
	SDL_Rect src = O.GetSource();
	SDL_RenderCopy(Renderer, O.GetTex(), &src, &dest);
}
