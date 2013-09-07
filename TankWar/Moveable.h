#pragma once
#include "Drawer.h"
#include "SDL.h"

class Moveable : public Drawer
{
public:
	Moveable(int x, int y, float direction, float speed, float rotateSpeed = 0);
	~Moveable(void);

	virtual void Update(int ms);
	virtual void UndoUpdate(int ms);
	
	virtual void MoveAndRotateItself(Uint32 msTime);
	virtual void UndoMoveAndRotateItself(Uint32 msTime);
	virtual void UndoMoveItself(Uint32 msTime);

	virtual void Move(Uint32 msTime, bool forward = true);
	virtual void Rotate(Uint32 msTime, bool right = true);
	
	virtual void SetMoving(bool forward = true);
	virtual void SetStopMoving();
	virtual void SetRotating(bool right = true);
	virtual void SetStopRotating();
	virtual bool IsMoving();
	virtual bool IsMovingForward();
	virtual bool IsRotating();
	virtual bool IsRotatingRight();

protected:
	float mSpeed;
	float mRotateSpeed;

	bool mIsMoving;
	bool mIsMovingForward;
	bool mIsRotating;
	bool mIsRotatingRight;

	float mLastLocationX;
	float mLastLocationY;
	float mLastDirection;

};

