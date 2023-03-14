#include "timer.h"
#include "../resourceManager/resourceManager.h"

Timer::Timer(double interval, Fl_Timeout_Handler callback):
	intervalTime(interval),
	running(false), callback(callback)
{

}

Timer::~Timer()
{

}

void Timer::start()
{
	if (!running)
	{
		running = true;
		Fl::add_timeout(intervalTime, callback, this);
	}
}

void Timer::stop()
{
	if (running)
	{
		running = false;
		Fl::remove_timeout(callback, this);
	}
}

void Timer::reset()
{
	this->stop();
	this->start();
}
