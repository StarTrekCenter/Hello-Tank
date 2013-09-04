#pragma once
#include "Item.h"
#include "Moveable.h"
#include "Bullet.h"
#include "SDL.h"

class Tank : public Item, public Moveable
{
public:
	static float SPEED;
	static float ROTATE_SPEED;
	static int SIZE;
public:
	Tank(int x, int y, float direction, float speed = SPEED, int size = SIZE, float rotateSpeed = ROTATE_SPEED);
	~Tank(void);
	
	virtual void Update(int ms);
	virtual void Draw();

	Bullet* Fire();
private:
	int mSize;		//the width or height of the tank rectangle
	SDL_Texture *mTexTank;
};

