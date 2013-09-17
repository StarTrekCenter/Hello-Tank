#pragma once
#include "Moveable.h"
#include "SDL.h"
#include "Item.h"

class Bullet : public Moveable
{
	public:
	static float SPEED;
	static int SIZE;
public:
	Bullet(Item* pItem, int x, int y, float direction, float speed = SPEED, int size = SIZE);
	~Bullet(void);

	virtual void Update(int ms);
	virtual void DoSometingIfHit(int ms);

	bool HitItself(Item* pItem);
protected:
	bool mIsHitted;
	Item* mpOwner;
};
