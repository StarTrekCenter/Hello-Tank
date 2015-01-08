#pragma once
#include "item.h"
#include "SDL.h"

class Drawer :
	public Item
{
public:
	Drawer(void);
	~Drawer(void);

	virtual void Draw();

protected:
	SDL_Texture *mTexDrawer;
};

