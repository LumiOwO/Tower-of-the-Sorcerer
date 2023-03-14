#ifndef _MAINMENU_H_
#define _MAINMENU_H_

#include <FL/Fl_Box.H>

#define MAINMENU_X			212
#define MAINMENU_Y			25
#define MAINMENU_WIDTH		836
#define MAINMENU_HEIGHT		671

class MainMenu: public Fl_Box
{
public:
	MainMenu();
	~MainMenu();
};

#endif