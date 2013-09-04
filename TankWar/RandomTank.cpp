#include "RandomTank.h"
#include <iostream>
#include <ctime>

using namespace std;

RandomTank::RandomTank(int x, int y, float direction, float speed, int size ,float rotateSpeed):
	Tank(x, y, direction, speed, size ,rotateSpeed),
	mUpdateTime(UPDATE_TIME),
	mTimeCount(0)
{
	srand((int)time(0));
}

int RandomTank::UPDATE_TIME = 100;

RandomTank::~RandomTank(void)
{
}

void RandomTank::Update(int ms)
{
	mTimeCount += ms;
	if (mTimeCount > mUpdateTime)
	{
		RandomChangeMove();
		RandomChangeRotate();
		mTimeCount = 0;
	}

	Tank::Update(ms);
}

void RandomTank::RandomChangeMove()
{
	if (!IsMoving())
	{
		if (rand() > (RAND_MAX*3/4))
		{
			SetMoving(rand() > (RAND_MAX/6));
		}
	}
	else
	{
		if (rand() > (RAND_MAX*3/4))
		{
			SetStopMoving();
		}
	}
}
void RandomTank::RandomChangeRotate()
{
	if (!IsRotating())
	{
		if (rand() > (RAND_MAX*3/4))
		{
			SetRotating(rand() > (RAND_MAX/2));
		}
	}
	else
	{
		if (rand() > (RAND_MAX*3/4))
		{
			SetStopRotating();
		}
	}
}

	//void RandomTank::RandomFire()
	//{
	//	if (rand() > (RAND_MAX*3/4))
	//	{
	//		Fire();
	//	}
	//}