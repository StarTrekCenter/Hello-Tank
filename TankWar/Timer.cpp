#include "Timer.h"
#include "Event.h"

using namespace std;


Timer::Timer(void)
	:mTimeStarted(false),
	mTimeDelay(0),
	mTimeEventType(SDL_FIRSTEVENT),
	mThreadTimer(NULL),
	mUserDate(nullptr)
{
}


Timer::~Timer(void)
{
}

void Timer::StartTimer(Uint32 ms,SDL_EventType(*onTimer)(SDL_Event),void* userData)
{
	mTimeDelay = ms;
	mUserDate = userData;

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

void Timer::FlushTimeEvent()
{
	SDL_FlushEvent(mTimeEventType);
}

int Timer::TimerThread(void *data)
{
	Timer* timer = (Timer*)data;

	if (timer->mTimeDelay > 0)
	{
		while(timer->mTimeStarted)
		{
			SDL_Delay(timer->mTimeDelay);
			Event::PushEvent(timer->mTimeEventType,TIME_CODE,timer->mUserDate,(void*)SDL_GetTicks());
		}
	}

	return 0;
}

