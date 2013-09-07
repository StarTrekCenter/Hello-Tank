#include "Game.h"
#include "Window.h"
#include "Timer.h"
#include "Event.h"
#include <math.h>
#include <ctime>

#include "RandomTank.h"

using namespace std;

Game::Game(void)
{
}


Game::~Game(void)
{
}

Stage* Game::mpStage = nullptr;
Timer* Game::mTimer = nullptr;
int Game::mUpdateTime = UPDATE_TIME;
int Game::mLastTimeEventTick = 0;
std::list<Item*> Game::mpItems;
Tank* Game::mDefaultTank;

void Game::Start()
{
	srand(time(0));

	InitWindowAndStage();
	AddDefaultTank();

	mTimer = new Timer();
	mTimer->StartTimer(mUpdateTime,TimerEvent);
	Event::AddEvent(SDL_KEYDOWN,KeyDownEvent);
	Event::AddEvent(SDL_KEYUP,KeyUpEvent);
	Event::StartListenEvent();
}

void Game::InitWindowAndStage(int width, int height)
{
	Window::Init("TankWar", width, height);
	mpStage = new Stage(width,height);
}

bool Game::IsInit()
{
	return nullptr != mpStage;
}

void Game::Update()
{
	if (IsInit())
	{
		list<Item*>::iterator itItem;
		for (itItem = mpItems.end();itItem != mpItems.begin(); itItem++)
		{
			if (nullptr != *itItem)
			{
				(*itItem)->Update(mUpdateTime);
			}
		}

		for (itItem = mpItems.end();itItem != mpItems.begin(); itItem++)
		{
			if (nullptr != *itItem)
			{
				(*itItem)->CheckHit();
			}
		}

		for (itItem = mpItems.end();itItem != mpItems.begin(); itItem++)
		{
			if (nullptr != *itItem)
			{
				(*itItem)->DoSometingIfHit(mUpdateTime);
			}
		}
	}
}

void Game::DrawAll()
{
	if (IsInit())
	{
		Window::Clear();

		mpStage->Draw();

		list<Item*>::iterator itItem;
		for (itItem = mpItems.begin();itItem != mpItems.end(); itItem++)
		{
			if (nullptr != *itItem)
			{
				(*itItem)->Draw();
			}
		}

		Window::Present();
	}
}

void Game::onUpdateTimer()
{
	Update();
	DrawAll();
}

SDL_EventType Game::TimerEvent(SDL_Event evt)
{
	SetTimeSpace((int) evt.user.data2);
	mTimer->FlushTimeEvent();
	onUpdateTimer();
	return (SDL_EventType)evt.type;
}

void Game::SetTimeSpace(int tick)
{
	if (0 != mLastTimeEventTick)
	{
		mUpdateTime = tick - mLastTimeEventTick;
	}
	mLastTimeEventTick = tick;
}

void Game::AddItem(Item* pItem)
{
	mpItems.push_back(pItem);
}

void Game::RemoveItem(Item* pItem)
{
	mpItems.remove(pItem);
	delete pItem;
}

list<Item*>::iterator Game::GetFirstImteIterator()
{
	return mpItems.begin();
}

list<Item*>::iterator Game::GetLastImteIterator()
{
	return mpItems.end();
}

 Item* Game::GetStage()
{
	return mpStage;
}

Tank* Game::AddTank(int x, int y, float direction)
{
	Tank* pTank = new Tank(x,y,direction);
	AddItem(pTank);
	return pTank;
}

SDL_EventType Game::KeyDownEvent(SDL_Event evt)
{
	switch (evt.key.keysym.sym)
	{
	case SDLK_UP:
		MoveDefaultTank(true);
		break;
	case SDLK_DOWN:
		MoveDefaultTank(false);
		break;
	case SDLK_RIGHT:
		RotateDefaultTank(true);
		break;
	case SDLK_LEFT:
		RotateDefaultTank(false);
		break;
	default:
		break;
	}

	return (SDL_EventType)evt.type;
}

SDL_EventType Game::KeyUpEvent(SDL_Event evt)
{
	switch (evt.key.keysym.sym)
	{
	case SDLK_UP:
		StopMoveDefaultTank();
		break;
	case SDLK_DOWN:
		StopMoveDefaultTank();
		break;
	case SDLK_RIGHT:
		StopRotateDefaultTank();
		break;
	case SDLK_LEFT:
		StopRotateDefaultTank();
		break;
	case SDLK_SPACE:
		DefaultTankFire();
		break;
	case SDLK_a:
		AddRandomTank();
		break;
	default:
		break;
	}

	return (SDL_EventType)evt.type;
}

void Game::AddDefaultTank()
{
	if (IsInit())
	{
		int x = rand()*mpStage->GetWidth()/RAND_MAX;
		int y = rand()*mpStage->GetHeight()/RAND_MAX;
		float dire = rand()*360/RAND_MAX;
		mDefaultTank = AddTank(x,y,dire);
	}
}

void Game::MoveDefaultTank(bool forward )
{
	mDefaultTank->SetMoving(forward);
}

void Game::StopMoveDefaultTank()
{
	mDefaultTank->SetStopMoving();
}

void Game::RotateDefaultTank(bool right)
{
	mDefaultTank->SetRotating(right);
}

void Game::StopRotateDefaultTank()
{
	mDefaultTank->SetStopRotating();
}
void Game::DefaultTankFire()
{
	mDefaultTank->Fire();
}

void Game::AddRandomTank()
{
	if (IsInit())
	{
		int x = rand()*mpStage->GetWidth()/RAND_MAX;
		int y = rand()*mpStage->GetHeight()/RAND_MAX;
		float dire = rand()*360/RAND_MAX;
		RandomTank* pTank = new RandomTank(x,y,dire);
		AddItem(pTank);
	}
}