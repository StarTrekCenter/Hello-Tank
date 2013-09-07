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
	//if (nullptr != mpStage)
	//{
	//	delete mpStage;
	//}

	//list<Tank*>::iterator itTank;
	//for (itTank = mpTanks.begin();itTank != mpTanks.end(); itTank++)
	//{
	//	if (nullptr != *itTank)
	//	{
	//		delete (*itTank);
	//	}
	//}
	//mpTanks.clear();
}

Stage* Game::mpStage = nullptr;
int Game::mUpdateTime = UPDATE_TIME;
std::list<Item*> Game::mpItems;
Tank* Game::mDefaultTank;

void Game::Start()
{
	InitWindowAndStage();
	AddDefaultTank();

	srand(0);

	Timer time;
	time.StartTimer(mUpdateTime,TimerEvent);
	Event::AddEvent(SDL_KEYDOWN,KeyDownEvent);
	Event::AddEvent(SDL_KEYUP,KeyUpEvent);
	Event::StartListenEvent();
}

void Game::InitWindowAndStage(int width, int height)
{
	Window::Init("TankWar", width, height);
	mpStage = new Stage();
	mpStage->Init(width,height);
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
		for (itItem = mpItems.begin();itItem != mpItems.end(); itItem++)
		{
			if (nullptr != *itItem)
			{
				(*itItem)->Update(mUpdateTime);
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
	onUpdateTimer();
	return (SDL_EventType)evt.type;
}

Tank* Game::AddTank(int x, int y, float direction)
{
	Tank* pTank = new Tank(x,y,direction);
	mpItems.push_back(pTank);
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
		srand((int)time(NULL) * 100);
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
	Bullet* pBullet = mDefaultTank->Fire();
	mpItems.push_back(pBullet);
}

void Game::AddRandomTank()
{
	if (IsInit())
	{
		int x = rand()*mpStage->GetWidth()/RAND_MAX;
		int y = rand()*mpStage->GetHeight()/RAND_MAX;
		float dire = rand()*360/RAND_MAX;
		RandomTank* pTank = new RandomTank(x,y,dire);
		mpItems.push_back(pTank);
	}
}