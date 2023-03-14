#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_

#include <FL/Fl_Text_Display.H>

#define TEXTSIZE			20

class TextDisplay : public Fl_Text_Display
{
private:
	Fl_Text_Buffer *textBuffer;
public:
	TextDisplay(int x, int y, int w, int h);
	~TextDisplay();

	// set the text of the displayer
	void setText(const char *str);
	// @override event handler
	int handle(int event);
};

#endif