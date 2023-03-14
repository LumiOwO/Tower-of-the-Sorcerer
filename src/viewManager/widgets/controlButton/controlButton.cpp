#include "controlButton.h"
#include "../../../resourceManager/resourceManager.h"

ControlButton::ControlButton(
	int x, int y, int w, int h, 
	 Fl_Callback callback, const char *text):
	Fl_Button(x, y, w, h, text)
{
	// set style
	this->box(FL_ROUND_UP_BOX);
	this->clear_visible_focus();
	this->color(ResourceManager::BackgroundColor);
	// set font
	this->labelfont(ResourceManager::HeiTi);
	this->labelcolor(FL_WHITE);
	this->labelsize(GAMEBUTTON_TEXTSIZE);
	// set callback
	this->callback(callback);
	// when init, hide the button
	this->hide();
}

ControlButton::~ControlButton()
{

}