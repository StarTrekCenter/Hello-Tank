#include "Timer.h"
#include "Event.h"

using namespace std;


Timer::Timer(void)
	:mTimeStarted(false),
	mTimeDelay(0),
	mTimeEventType(SDL_FIRSTEVENT),
	mThreadTimer(NULL)
{
}


Timer::~Timer(void)
{
}

void Timer::StartTimer(Uint32 ms,SDL_EventType(*onTimer)(SDL_Event))
{
	mTimeDelay = ms;

	if (!mTimeStarted)
	{
		mTimeStarted = true;
		mTimeEventType = Event::RegisterEvent();
		Event::AddEvent(mTimeEventType, onTimer);

		mThreadTimer = SDL_CreateThread(TimerThread, "TimerThread", this);
	}
}

void Timer::StopTimer()
{
	if (mTimeStarted)
	{
		mTimeStarted = false;
		if( NULL != mThreadTimer )
		{
			int threadReturnValue;
			SDL_WaitThread( mThreadTimer, &threadReturnValue);
		}
	}
}

int Timer::TimerThread(void *data)
{
	Timer* timer = (Timer*)data;

	if (timer->mTimeDelay > 0)
	{
		int count = 0;
		int ticks;
		while(timer->mTimeStarted)
		{
			SDL_Delay(timer->mTimeDelay);
			ticks = SDL_GetTicks();
			Event::PushEvent(timer->mTimeEventType,TIME_CODE,(void*)count,(void*)ticks);
			count++;
		}
	}

	return 0;
}

