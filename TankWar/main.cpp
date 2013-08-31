#include "Window.h"
#include "Event.h"
#include "Timer.h"
#include "Tank.h"
#include <iostream>
using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Tank *pTank;
SDL_Texture *texBackground;
SDL_EventType funKeyDown(SDL_Event evt)
{
	return (SDL_EventType)SDL_QUIT;
}

SDL_EventType onTimer(SDL_Event evt)
{
	pTank->Rotate(100,true);
	pTank->Move(100);
	Window::Draw(texBackground,Window::Box());
	pTank->Draw();
	Window::Present();
	return (SDL_EventType)evt.type;
}

int main(int argv, char** argc)
{
	Window::Init("MyWindow");
	
	pTank = new Tank();
	pTank->Init(300,300,30);
	

	texBackground = Window::LoadImage("../Res/Image/background.bmp");
	Window::Clear();
	Window::Draw(texBackground,Window::Box());
	pTank->Draw();
	Window::Present();



	Timer time;
	time.StartTimer(100,onTimer);
	Event::AddEvent(SDL_KEYDOWN,funKeyDown);
	Event::StartListenEvent();

	return 0;
}