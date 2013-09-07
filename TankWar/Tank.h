#pragma once
#include "Item.h"
#include "Moveable.h"
#include "Bullet.h"
#include "SDL.h"

class Tank :  public Moveable
{
public:
	static float SPEED;
	static float ROTATE_SPEED;
	static int SIZE;
	static int FIRE_TIME_LIMIT;
public:
	Tank(int x, int y, float direction, float speed = SPEED, int size = SIZE, float rotateSpeed = ROTATE_SPEED);
	~Tank(void);
	
	virtual void Update(int ms);
	virtual void DoSometingIfHit(int ms);

	void Fire();
	bool GetCanFire();
private:

	void UpdateFireTime(int ms);
	int mFireTimeLimit;
	int mFireTimeCount;
	bool mCanFire;
	
};

