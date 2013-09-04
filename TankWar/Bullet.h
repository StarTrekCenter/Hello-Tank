#pragma once
#include "Moveable.h"
#include "SDL.h"
#include "Item.h"

class Bullet : public Item, public Moveable
{
	public:
	static float SPEED;
	static int SIZE;
public:
	Bullet(int x, int y, float direction, float speed = SPEED, int size = SIZE);
	~Bullet(void);

	virtual void Update(int ms);
	virtual void Draw();

private:
	int mSize;		//the width or height of the tank rectangle
	SDL_Texture *mTexBullet;
};
