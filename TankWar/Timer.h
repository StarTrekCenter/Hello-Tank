#pragma once
#include "SDL.h"
#include "SDL_thread.h"

#define TIME_CODE 0x0001

class Timer
{
public:
	Timer(void);
	~Timer(void);

	void StartTimer(Uint32 ms,SDL_EventType(*onTimer)(SDL_Event),void* userData = nullptr);
	void StopTimer();
	
	void FlushTimeEvent();

private:
	//SDL_ThreadFunction TimerThread;
	static int TimerThread(void *data);

private:
	int mTimeDelay;
	bool mTimeStarted;
	SDL_EventType mTimeEventType;
	SDL_Thread *mThreadTimer;

	void* mUserDate;
};

