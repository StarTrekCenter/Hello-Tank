#include "Stage.h"
#include "Window.h"

Stage::Stage(int width, int height)
{
	mWidth = width;
	mHeight = height;

	mRectStage.x = 0;
	mRectStage.y = 0;
	mRectStage.h = mHeight;
	mRectStage.w = mWidth;

	

	mTexDrawer = Window::LoadImage("../Res/Image/background.bmp");
}

Stage::~Stage(void)
{
}

void Stage::Update(int ms)
{
}

void Stage::UndoUpdate(int ms)
{
}

void Stage::DoSometingIfHit(int ms)
{
}

void Stage::Draw()
{
	Window::Draw(mTexDrawer,Window::Box());
}


SDL_Rect Stage::GetItemRect()
{
	return mRectStage;
}

int Stage::GetWidth()
{
	return mWidth;
}

int Stage::GetHeight()
{
	return mHeight;
}