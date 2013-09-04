#include "Moveable.h"
#include <math.h>

Moveable::Moveable(int x, int y, float direction, float speed, float rotateSpeed):
	mIsMoving(false),
	mIsMovingForward(true),
	mIsRotating(false),
	mIsRotatingRight(true)
{
	mLocationX = x;
	mLocationY = y;
	mDirection = direction;
	mSpeed = speed;
	mRotateSpeed = rotateSpeed;
}


Moveable::~Moveable(void)
{
}

void Moveable::Move(Uint32 msTime, bool forward)
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

void Moveable::Rotate(Uint32 msTime, bool right)
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
void Moveable::MoveAndRotateItself(Uint32 msTime)
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

void Moveable::SetMoving(bool forward )
{
	mIsMoving = true;
	mIsMovingForward = forward;
}

void Moveable::SetStopMoving()
{
	mIsMoving = false;
}

void Moveable::SetRotating(bool right )
{
	mIsRotating = true;
	mIsRotatingRight = right;
}

void Moveable::SetStopRotating()
{
	mIsRotating = false;
}