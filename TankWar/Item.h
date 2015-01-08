#pragma once
#include "SDL.h"
class Item
{
public:
	enum ItemType
	{
		ITEM = 0,
		TANK,
		BULLET
	};

public:
	Item(void);
	~Item(void);

	virtual void Update(int ms) =0; 
	virtual void UndoUpdate(int ms) =0;
	virtual void Draw() =0;
	virtual void DoSometingIfHit(int ms) =0;
	virtual Item* CheckHit();
	virtual SDL_Rect GetItemRect();

	ItemType GetType();
	Item* GetLastHitItem();
	bool Hit(Item* pItem);
	bool HitStage();


protected:
	ItemType mType;

	float mLocationX;
	float mLocationY;
	float mDirection;	//0 => x-axis,  90 =>y-axis
	int mSize;

private:
	Item* mpLastHitItem;
};

