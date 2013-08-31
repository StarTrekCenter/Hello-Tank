#pragma once
#include "SDL.h"

class Tank
{
public:
	static float SPEED;
	static float ROTATE_SPEED;
	static int SIZE;
public:
	Tank(void);
	~Tank(void);

	void Init(int x, int y, float direction);
	void Move(Uint32 msTime);
	void Rotate(Uint32 msTime, bool right);
	void Draw();

private:
	float mLocationX;
	float mLocationY;
	int mSize;		//the width or height of the tank rectangle
	float mDirection;	//0 => x-axis,  90 =>y-axis
	float mSpeed;
	float mRotateSpeed;

	SDL_Texture *mTexTank;
};

