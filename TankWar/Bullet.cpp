#include "Bullet.h"
#include "Window.h"
#include "Game.h"

Bullet::Bullet(int x, int y, float direction, float speed, int size):
	Moveable(x, y, direction, speed),
	mIsHitted(false)
{
	mType = BULLET;

	mSize = size;

	mIsMoving = true;
	mIsMovingForward = true;
	mTexDrawer = Window::LoadImage("../Res/Image/bullet.gif");
}


Bullet::~Bullet(void)
{
}

float Bullet::SPEED = 0.5f;
int Bullet::SIZE = 5;

void Bullet::Update(int ms)
{
	if (mIsHitted)
	{
		Game::RemoveItem(this);
	}
	else
	{
		Moveable::Update(ms);
	}
}

void Bullet::DoSometingIfHit(int ms)
{
	Item* pHitItem = GetLastHitItem();
	if (nullptr != pHitItem)
	{
		mIsHitted = true;
	}
}