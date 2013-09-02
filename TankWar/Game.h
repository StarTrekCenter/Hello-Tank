#pragma once
#include <list>
#include "SDL.h"
#include "Tank.h"
#include "Stage.h"

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
	static void DrawAll();
	static void onUpdateTimer();
	static SDL_EventType TimerEvent(SDL_Event evt);

	static Tank* AddTank(int x, int y, float direction);
	
	static void AddDefaultTank();
	static void MoveDefaultTank(bool forward = true);
	static void StopMoveDefaultTank();
	static void RotateDefaultTank(bool right = true);
	static void StopRotateDefaultTank();

	static SDL_EventType KeyDownEvent(SDL_Event evt);
	static SDL_EventType KeyUpEvent(SDL_Event evt);

private:
	static int mUpdateTime;

	static std::list<Tank*> mpTanks;
	static Stage* mpStage;

	static Tank* mDefaultTank;
};


