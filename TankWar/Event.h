#pragma once
#include "SDL.h"
#include <map>

class Event
{
public:
	Event(void);
	~Event(void);

	// add event callback function
	static void AddEvent(SDL_EventType evtType, SDL_EventType(*fooEvent)(SDL_Event));

	// remove event callback function
	static void RemoveEvent(SDL_EventType evtType);
		
	// clean event callback map
	static void CleanEvent();

	// register event type
	static SDL_EventType RegisterEvent();

	// push event
	static void PushEvent(SDL_EventType type, Sint32 userCode = 0, void* userData1 = NULL, void* userData2 = NULL);

	// start polling event and do the callback fuction
	static void StartListenEvent();

private:
	// poll next event
	static SDL_Event PollEvent();

private:
	static SDL_Event mEvent;
	static std::map<SDL_EventType, SDL_EventType(*)(SDL_Event)> mEventCallbackMap;
};

