#pragma once
#include "SDL.h"

class Tank
{
public:
	Tank(void);
	~Tank(void);

private:
	SDL_Point mLocation;
	SDL_Rect mSize;
	float mDirection;

};

