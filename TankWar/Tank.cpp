#include "Tank.h"
#include "Window.h"
#include <math.h>

Tank::Tank(void):
	mSpeed(SPEED),
	mRotateSpeed(ROTATE_SPEED),
	mSize(SIZE)
{
	mTexTank = Window::LoadImage("../Res/Image/tank.gif");
}

Tank::~Tank(void)
{
}

float Tank::SPEED = 0.05f;
float Tank::ROTATE_SPEED = 0.1f;
int Tank::SIZE = 50;

void Tank::Init(int x, int y, float direction)
{
	mLocationX = x;
	mLocationY = y;
	mDirection = direction;
}

void Tank::Move(Uint32 msTime)
{
	float rec = mDirection/180*M_PI;
	mLocationX += mSpeed * cos(rec) * msTime;
	mLocationY += mSpeed * sin(rec) * msTime;
}

void Tank::Rotate(Uint32 msTime, bool right)
{
	if (right)
	{
		mDirection += mRotateSpeed * msTime;
	}
	else
	{
		mDirection -= mRotateSpeed * msTime;
	}
}

void Tank::Draw()
{
	
	

	SDL_Rect rectTank;
	rectTank.x = mLocationX - mSize/2;
	rectTank.y = mLocationY - mSize/2;
	rectTank.h = mSize;
	rectTank.w = mSize;

	Window::Draw(mTexTank,rectTank,NULL,mDirection);
}
