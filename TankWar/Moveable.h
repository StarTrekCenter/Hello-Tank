#pragma once
#include "SDL.h"

class Moveable
{
public:
	Moveable(int x, int y, float direction, float speed, float rotateSpeed = 0);
	~Moveable(void);

	virtual void Move(Uint32 msTime, bool forward = true);
	virtual void Rotate(Uint32 msTime, bool right = true);
	virtual void MoveAndRotateItself(Uint32 msTime);
	virtual void SetMoving(bool forward = true);
	virtual void SetStopMoving();
	virtual void SetRotating(bool right = true);
	virtual void SetStopRotating();
	virtual bool IsMoving();
	virtual bool IsMovingForward();
	virtual bool IsRotating();
	virtual bool IsRotatingRight();

protected:
	float mLocationX;
	float mLocationY;
	float mDirection;	//0 => x-axis,  90 =>y-axis
	float mSpeed;
	float mRotateSpeed;

	bool mIsMoving;
	bool mIsMovingForward;
	bool mIsRotating;
	bool mIsRotatingRight;
};

