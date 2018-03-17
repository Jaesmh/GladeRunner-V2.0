#include "Objects.h"

void Objects::SetDest(int x, int y, int w, int h)
{
	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;
}

void Objects::SetSource(int x, int y, int w, int h)
{
	src.x = x;
	src.y = y;
	src.w = w;
	src.h = h;
}

void Objects::SetImage(std::string file_path, SDL_Renderer * Renderer)
{
	SDL_Surface* TempSurface = IMG_Load(file_path.c_str());
	tex = SDL_CreateTextureFromSurface(Renderer, TempSurface);
	SDL_FreeSurface(TempSurface);
}
