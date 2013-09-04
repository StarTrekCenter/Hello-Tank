#include "Event.h"
using namespace std;

Event::Event(void)
{

}


Event::~Event(void)
{
}

SDL_Event Event::mEvent;
map<SDL_EventType, SDL_EventType(*)(SDL_Event)> Event::mEventCallbackMap;

// add event callback function
void Event::AddEvent(SDL_EventType evtType, SDL_EventType(*fooEvent)(SDL_Event))
{
	if(fooEvent != NULL && evtType != SDL_FIRSTEVENT && evtType != SDL_LASTEVENT)
	{
		mEventCallbackMap[evtType] = fooEvent;
	}
}

// remove event callback function
void Event::RemoveEvent(SDL_EventType evtType)
{
	mEventCallbackMap.erase(evtType);
}

// clean event callback map
void Event::CleanEvent()
{
	mEventCallbackMap.clear();
}

// register event type
SDL_EventType Event::RegisterEvent()
{
	return (SDL_EventType)SDL_RegisterEvents(1);
}


// push event
void Event::PushEvent(SDL_EventType type, Sint32 userCode, void* userData1, void* userData2)
{
	SDL_Event evt;
	evt.type = type;
	evt.user.code = userCode;
	evt.user.data1 = userData1;
	evt.user.data2 = userData2;
	SDL_PushEvent(&evt);
}

// start polling event and do the callback fuction
void Event::StartListenEvent()
{
	map<SDL_EventType, SDL_EventType(*)(SDL_Event)>::iterator it;
	SDL_EventType typeEvent = SDL_FIRSTEVENT;
	SDL_EventType typeReturn = SDL_FIRSTEVENT;

	PollEvent();
	typeEvent = (SDL_EventType)mEvent.type;
	while(SDL_QUIT != typeEvent && SDL_QUIT != typeReturn)
	{
		it = mEventCallbackMap.find(typeEvent);
		if (it != mEventCallbackMap.end())
		{
			typeReturn = it->second(mEvent);
		}
		PollEvent();
		typeEvent = (SDL_EventType)mEvent.type;
	}
}


// poll next event
SDL_Event Event::PollEvent()
{
	SDL_WaitEvent(&mEvent);
	return mEvent;
}