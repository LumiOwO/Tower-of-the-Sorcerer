#ifndef _WINUI_H_
#define _WINUI_H_

#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>

#define WINUI_X				280
#define WINUI_Y				60
#define WINUI_WIDTH			700
#define WINUI_HEIGHT		600

#define WINIMAGE_HEIGHT		494

#define WIN_BUTTONW			170
#define WIN_BUTTONH			50
#define WIN_TEXTSIZE		20

class WinUI: public Fl_Group
{
private:
	Fl_Box* winImage;
	Fl_Button* button;
public:
	WinUI();
	~WinUI();

};

#endif