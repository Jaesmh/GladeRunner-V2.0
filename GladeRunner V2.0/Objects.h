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
	inline SDL_Rect GetDest() const { return dest; }
	inline SDL_Rect GetSource() const { return src; }
	inline SDL_Texture* GetTex() const { return tex; }
	void SetDest(int x, int y, int w, int h);
	void SetSource(int x, int y, int w, int h);
	void SetImage(std::string file_path, SDL_Renderer* Renderer);
};

#endif //OBJECTS_H