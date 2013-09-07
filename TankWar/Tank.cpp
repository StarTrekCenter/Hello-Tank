#include "Tank.h"
#include "Game.h"
#include "Window.h"

Tank::Tank(int x, int y, float direction, float speed, int size ,float rotateSpeed):
	Moveable(x,  y, direction, speed, rotateSpeed),
	mCanFire(true),
	mFireTimeCount(0),
	mFireTimeLimit(FIRE_TIME_LIMIT)
{
	mType = TANK;

	mSize = size;

	mTexDrawer = Window::LoadImage("../Res/Image/tank.gif");
}

Tank::~Tank(void)
{
}

float Tank::SPEED = 0.05f;
float Tank::ROTATE_SPEED = 0.1f;
int Tank::SIZE = 50;
int Tank::FIRE_TIME_LIMIT = 500;

void Tank::Update(int ms)
{
	UpdateFireTime(ms);
	Moveable::Update(ms);
}

void Tank::DoSometingIfHit(int ms)
{
	Item* pHitItem = GetLastHitItem();
	if (nullptr != pHitItem)
	{
		if (TANK == pHitItem->GetType())
		{
			UndoMoveItself(ms);
		}
	}
}

void Tank::Fire()
{
	if (mCanFire)
	{
		Bullet* bul = new Bullet(mLocationX, mLocationY, mDirection);
		Game::AddItem(bul);
		mCanFire = false;
	}
}

bool Tank::GetCanFire()
{
	return mCanFire;
}

void Tank::UpdateFireTime(int ms)
{
	if (!mCanFire)
	{
		mFireTimeCount += ms;
		if (mFireTimeCount > mFireTimeLimit)
		{
			mCanFire = true;
			mFireTimeCount = 0;
		}
	}
}
