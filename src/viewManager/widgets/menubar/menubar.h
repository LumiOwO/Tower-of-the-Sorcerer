#ifndef _MENUBAR_H_
#define _MENUBAR_H_

#include <FL/Fl_Menu_Bar.H>

#define MENUBAR_WIDTH		1260
#define MENUBAR_HEIGHT		25
#define MENUBAR_TEXTSIZE	13

class MenuBar: public Fl_Menu_Bar
{
public:
	// constructor and destructor
	MenuBar();
	~MenuBar();
};

#endif
