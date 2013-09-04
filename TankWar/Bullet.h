#pragma once
#include "Moveable.h"
#include "SDL.h"

class Bullet : public Moveable
{
	public:
	static float SPEED;
	static int SIZE;
public:
	Bullet(int x, int y, float direction, float speed = SPEED, int size = SIZE);
	~Bullet(void);

	void Draw();
private:
	int mSize;		//the width or height of the tank rectangle
	SDL_Texture *mTexBullet;
};
