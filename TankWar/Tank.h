#pragma once
#include "Moveable.h"
#include "Bullet.h"
#include "SDL.h"

class Tank : public Moveable
{
public:
	static float SPEED;
	static float ROTATE_SPEED;
	static int SIZE;
public:
	Tank(int x, int y, float direction, float speed = SPEED, int size = SIZE, float rotateSpeed = ROTATE_SPEED);
	~Tank(void);
	
	Bullet* Fire();

	void Draw();
private:
	int mSize;		//the width or height of the tank rectangle
	SDL_Texture *mTexTank;
};

