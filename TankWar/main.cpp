#include "Window.h"
#include "Event.h"
#include "Timer.h"

#include <iostream>
using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_EventType funKeyDown(SDL_Event evt)
{
	return (SDL_EventType)SDL_QUIT;
}

int myCount = 0;
SDL_EventType onTimer(SDL_Event evt)
{
	cout<<(int)evt.user.data1<<"   "<<myCount++<<endl;
	return (SDL_EventType)evt.type;
}

int main(int argv, char** argc)
{
	Window win;
	win.Init("MyWindow");

	SDL_Texture *texBackground = win.LoadImage("../Res/Image/background.bmp");
	win.Clear();
	win.Draw(texBackground,win.Box());
	win.Present();

	Timer time;
	time.StartTimer(1000,onTimer);
	Event::AddEvent(SDL_KEYDOWN,funKeyDown);
	Event::StartListenEvent();

	return 0;
}