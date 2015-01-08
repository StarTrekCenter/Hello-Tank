#pragma once
#include "Drawer.h"
#include "SDL.h"

class Stage : public Drawer 
{
public:
	Stage(int width, int height);
	~Stage(void);

	virtual void Update(int ms);
	virtual void UndoUpdate(int ms);
	virtual void DoSometingIfHit(int ms);
	virtual void Draw();

	virtual SDL_Rect GetItemRect();

	int GetWidth();
	int GetHeight();

private:
	int mWidth;
	int mHeight;
	SDL_Rect mRectStage;
};
