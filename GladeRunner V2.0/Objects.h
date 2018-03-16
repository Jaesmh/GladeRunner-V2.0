#ifndef OBJECTS_H
#define OBJECTS_H

#include "GameSystem.h"

class Objects
{
private:
	SDL_Rect dest;
	SDL_Rect src;
	SDL_Texture* tex;
public:
	Objects();
	~Objects();
	SDL_Rect GetDest() const { return dest; }
	SDL_Rect GetSource() const { return src; }
};

#endif //OBJECTS_H