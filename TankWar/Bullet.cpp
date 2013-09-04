#include "Bullet.h"
#include "Window.h"

Bullet::Bullet(int x, int y, float direction, float speed, int size):
	Moveable(x, y, direction, speed),
	mSize(size)
{
	mIsMoving = true;
	mIsMovingForward = true;
	mTexBullet = Window::LoadImage("../Res/Image/bullet.gif");
}


Bullet::~Bullet(void)
{
}

float Bullet::SPEED = 0.5f;
int Bullet::SIZE = 5;

void Bullet::Draw()
{
	SDL_Rect rectTank;
	rectTank.x = mLocationX - mSize/2;
	rectTank.y = mLocationY - mSize/2;
	rectTank.h = mSize;
	rectTank.w = mSize;

	Window::Draw(mTexBullet,rectTank,NULL,mDirection);
}