#ifndef _STATUSBAR_H_
#define _STATUSBAR_H_

#include <FL/Fl_Box.H>
#include <iostream>
using namespace std;

#define STATUSBAR_WIDTH		1260
#define STATUSBAR_HEIGHT	24
#define STATUSBAR_Y			695
#define STATUSBAR_TEXTSIZE	13

class StatusBar : public Fl_Box
{
public:
	// constructor and destructor
	StatusBar();
	~StatusBar();
	// print current status
	void printStatus(string message);
};

#endif
