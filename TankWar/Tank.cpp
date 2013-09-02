#include "Tank.h"
#include "Window.h"
#include <math.h>

Tank::Tank(void):
	mSpeed(SPEED),
	mRotateSpeed(ROTATE_SPEED),
	mSize(SIZE),
	mIsMoving(false),
	mIsMovingForward(false),
	mIsRotating(false),
	mIsRotatingRight(false)
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

void Tank::Move(Uint32 msTime, bool forward)
{
	float rec = mDirection/180*M_PI;
	if (forward)
	{
		mLocationX += mSpeed * cos(rec) * msTime;
		mLocationY += mSpeed * sin(rec) * msTime;
	}
	else
	{
		mLocationX -= mSpeed * cos(rec) * msTime;
		mLocationY -= mSpeed * sin(rec) * msTime;
	}
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
void Tank::MoveAndRotateItself(Uint32 msTime)
{
	if (mIsMoving)
	{
		Move(msTime,mIsMovingForward);
	}
	if (mIsRotating)
	{
		Rotate(msTime,mIsRotatingRight);
	}
}

void Tank::SetMoving(bool forward )
{
	mIsMoving = true;
	mIsMovingForward = forward;
}

void Tank::SetStopMoving()
{
	mIsMoving = false;
}

void Tank::SetRotating(bool right )
{
	mIsRotating = true;
	mIsRotatingRight = right;
}

void Tank::SetStopRotating()
{
	mIsRotating = false;
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