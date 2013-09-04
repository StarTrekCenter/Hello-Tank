#include "Stage.h"
#include "Window.h"

Stage::Stage(void)
{
	mTexBackground = Window::LoadImage("../Res/Image/background.bmp");
}


Stage::~Stage(void)
{
}

void Stage::Init(int width, int height)
{
	mWidth = width;
	mHeight = height;
}

void Stage::Draw()
{
	Window::Draw(mTexBackground,Window::Box());
}

int Stage::GetWidth()
{
	return mWidth;
}

int Stage::GetHeight()
{
	return mHeight;
}