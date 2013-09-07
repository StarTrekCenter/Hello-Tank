#include "Item.h"
#include "Game.h"

using namespace std;

Item::Item(void):
	mType(ITEM),
	mLocationX(0),
	mLocationY(0),
	mDirection(0),
	mSize(0),
	mpLastHitItem(nullptr)
{
}


Item::~Item(void)
{
}

Item* Item::CheckHit()
{
	list<Item*>::iterator itItem;
	Item* pItem;
	for ( itItem = Game::GetFirstImteIterator() ; itItem != Game::GetLastImteIterator(); itItem++)
	{
		pItem = *itItem;
		if (Hit(pItem))
		{
			mpLastHitItem = pItem;
			return mpLastHitItem;
		}
	}

	if (HitStage())
	{
		mpLastHitItem = Game::GetStage();
		return mpLastHitItem;
	}
	mpLastHitItem = nullptr;
	return mpLastHitItem;
}

Item::ItemType Item::GetType()
{
	return mType;
}

Item* Item::GetLastHitItem()
{
	return mpLastHitItem;
}

bool Item::Hit(Item* pItem)
{
	if (this == pItem)
	{
		return false;
	}

	SDL_Rect rectThis = GetItemRect();
	SDL_Rect rectitem = pItem->GetItemRect();

	if (SDL_TRUE == SDL_HasIntersection(&rectThis, &rectitem))
	{
		return true;
	}
}

bool Item::HitStage()
{
	SDL_Rect rectThis = GetItemRect();
	Item* pStage = Game::GetStage();
	SDL_Rect rectStage = pStage->GetItemRect();
	if (rectThis.x < rectStage.x || rectThis.y < rectStage.y || 
		rectThis.x + rectThis.w > rectStage.x + rectStage.w || 
		rectThis.y + rectThis.h > rectStage.y + rectStage.h)
	{
		return true;
	}
	else
	{
		return false;
	}
}

SDL_Rect Item::GetItemRect()
{
	SDL_Rect rect;
	rect.x = mLocationX - mSize/2;
	rect.y = mLocationY - mSize/2;
	rect.h = mSize;
	rect.w = mSize;

	return rect;
}
