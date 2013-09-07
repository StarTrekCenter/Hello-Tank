#pragma once
#include <list>
#include "SDL.h"
#include "Item.h"
#include "Stage.h"
#include "Moveable.h"
#include "Tank.h"
#include "Bullet.h"
#include "Timer.h"

class Game
{
public:
	static const int SCREEN_WIDTH = 640;
	static const int SCREEN_HEIGHT = 480;
	static const int UPDATE_TIME = 50;

public:
	Game(void);
	~Game(void);
	static void Start();

	static void InitWindowAndStage(int width = SCREEN_WIDTH, int height = SCREEN_HEIGHT);
	static bool IsInit();

	static void Update();
	static void MoveAll(std::list<Moveable*> mover);
	static void DrawAll();
	static void onUpdateTimer();

	static SDL_EventType TimerEvent(SDL_Event evt);
	static void SetTimeSpace(int tick);

	static void AddItem(Item* pItem);
	static void RemoveItem(Item* pItem);
	static std::list<Item*>::iterator GetFirstImteIterator();
	static std::list<Item*>::iterator GetLastImteIterator();

	static Item* GetStage();

	static Tank* AddTank(int x, int y, float direction);

	static SDL_EventType KeyDownEvent(SDL_Event evt);
	static SDL_EventType KeyUpEvent(SDL_Event evt);

	static void AddDefaultTank();
	static void MoveDefaultTank(bool forward = true);
	static void StopMoveDefaultTank();
	static void RotateDefaultTank(bool right = true);
	static void StopRotateDefaultTank();
	static void DefaultTankFire();

	static void AddRandomTank();

private:
	static Timer* mTimer;
	static int mUpdateTime;
	static int mLastTimeEventTick;

	static std::list<Item*> mpItems;
	static Stage* mpStage;
	static Tank* mDefaultTank;
};


