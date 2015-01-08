#pragma once
#include "Tank.h"

class RandomTank : public Tank
{
public:
	RandomTank(int x, int y, float direction, float speed = SPEED, int size = SIZE, float rotateSpeed = ROTATE_SPEED);
	~RandomTank(void);

	virtual void Update(int ms);

private:
	void RandomChangeMove();
	void RandomChangeRotate();
	void RandomFire();

	static int UPDATE_TIME ; 
	int mUpdateTime;
	int mTimeCount;
};

