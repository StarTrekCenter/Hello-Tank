#include "Drawer.h"
#include "Window.h"

Drawer::Drawer(void):
	mTexDrawer(nullptr)
{
}


Drawer::~Drawer(void)
{
}

void Drawer::Draw()
{
	SDL_Rect rect = GetItemRect();

	Window::Draw(mTexDrawer,rect,NULL,mDirection);
	Window::DrawRect(&rect);
}