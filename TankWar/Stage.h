#pragma once
#include "SDL.h"

class Stage
{
public:
	Stage(void);
	~Stage(void);

	void Init(int width, int height);
	void Draw();

	int GetWidth();
	int GetHeight();

private:
	int mWidth;
	int mHeight;

	SDL_Texture *mTexBackground;
};
