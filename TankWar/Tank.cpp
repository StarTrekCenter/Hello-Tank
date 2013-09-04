#include "Tank.h"
#include "Window.h"

Tank::Tank(int x, int y, float direction, float speed, int size ,float rotateSpeed):
	Moveable(x,  y, direction, speed, rotateSpeed),
	mSize(size)
{
	mTexTank = Window::LoadImage("../Res/Image/tank.gif");
}

Tank::~Tank(void)
{
}

float Tank::SPEED = 0.05f;
float Tank::ROTATE_SPEED = 0.1f;
int Tank::SIZE = 50;

Bullet* Tank::Fire()
{
	Bullet* bul = new Bullet(mLocationX, mLocationY, mDirection);
	return bul;
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