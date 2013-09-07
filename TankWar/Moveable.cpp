#include "Moveable.h"
#include <math.h>

Moveable::Moveable(int x, int y, float direction, float speed, float rotateSpeed):
	mIsMoving(false),
	mIsMovingForward(true),
	mIsRotating(false),
	mIsRotatingRight(true),
	mSpeed(speed),
	mRotateSpeed(rotateSpeed),
	mLastLocationX(0),
	mLastLocationY(0),
	mLastDirection(0)
{
	mLocationX = x;
	mLocationY = y;
	mDirection = direction;
}


Moveable::~Moveable(void)
{
}

void Moveable::Update(int ms)
{
	MoveAndRotateItself(ms);
}

void Moveable::UndoUpdate(int ms)
{
	UndoMoveAndRotateItself(ms);
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

void Moveable::UndoMoveAndRotateItself(Uint32 msTime)
{
	UndoMoveItself(msTime);
	if (mIsRotating)
	{
		Rotate(msTime,!mIsRotatingRight);
	}
}

void Moveable::UndoMoveItself(Uint32 msTime)
{
	if (mIsMoving)
	{
		mLocationX = mLastLocationX;
		mLocationY = mLastLocationY;
		mDirection = mLastDirection;
	}
}

void Moveable::Move(Uint32 msTime, bool forward)
{
	mLastLocationX = mLocationX;
	mLastLocationY = mLocationY;
	mLastDirection = mDirection;

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

bool Moveable::IsMoving()
{
	return mIsMoving;
}

bool Moveable::IsMovingForward()
{
	return mIsMovingForward;
}

bool Moveable::IsRotating()
{
	return mIsRotating;
}

bool Moveable::IsRotatingRight()
{
	return mIsRotatingRight;
}
