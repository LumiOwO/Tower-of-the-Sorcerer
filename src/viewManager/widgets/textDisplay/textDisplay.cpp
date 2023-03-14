#include "textDisplay.h"
#include "../../../resourceManager/resourceManager.h"
#include "../../../game/game.h"

TextDisplay::TextDisplay(int x, int y, int w, int h):
	Fl_Text_Display(x, y, w, h)
{
	// set text buffer
	textBuffer = new Fl_Text_Buffer();
	this->buffer(textBuffer);
	// set style
	this->wrap_mode(Fl_Text_Display::WRAP_AT_BOUNDS, 0);
	this->box(FL_FLAT_BOX);
	// set text font
	this->textsize(TEXTSIZE);
	this->textfont(ResourceManager::HeiTi);
	this->textcolor(FL_WHITE);
}

TextDisplay::~TextDisplay()
{
	// remove the buffer from the displayer
	this->buffer(nullptr);
	// free memory
	delete textBuffer;
}

void TextDisplay::setText(const char* str)
{
	// set the text of the displayer
	textBuffer->text(str);
}

int TextDisplay::handle(int event)
{
	int ret;
	// disable all event except mouse wheel and shortcut
	if (event == FL_MOUSEWHEEL)
		ret = Fl_Text_Display::handle(event);
	else if (event == FL_SHORTCUT)
		ret = Fl_Text_Display::handle(event);
	else if (event == FL_DRAG || event == FL_PUSH)
		ret = Fl_Text_Display::handle(event);
	else
		ret = 1;
	Fl::focus(ResourceManager::game->getMainWindow());
	return ret;
}
