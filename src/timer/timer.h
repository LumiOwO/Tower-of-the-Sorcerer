#ifndef _TIMER_H_
#define _TIMER_H_

#include <FL/Fl.H>

// declare the Game class
// in order to avoid references to each other
class Game;

class Timer
{
private:
	double intervalTime;
	bool running;
	Fl_Timeout_Handler callback;
public:
	// constructor and destructor
	Timer(double interval, Fl_Timeout_Handler callback);
	~Timer();
	// control
	void start();
	void stop();
	void reset();
};

#endif
