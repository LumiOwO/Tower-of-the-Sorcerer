#ifndef _CONTROLBUTTON_H_
#define _CONTROLBUTTON_H_

#include <FL/Fl_Button.H>

#define GAMEBUTTON_TEXTSIZE		50

class ControlButton: public Fl_Button
{
public:
	// constructors and destructors
	ControlButton(int x, int y, int w, int h, 
		Fl_Callback callback, const char *text = (const char*)0);
	~ControlButton();
};

#endif