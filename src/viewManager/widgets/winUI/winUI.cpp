#include "winUI.h"
#include "../../../resourceManager/resourceManager.h"
#include "../../../game/game.h"

WinUI::WinUI():
	Fl_Group(WINUI_X, WINUI_Y, WINUI_WIDTH, WINUI_HEIGHT)
{
	// set style
	this->box(FL_FLAT_BOX);
	this->color(ResourceManager::BackgroundColor);

	// begin to add widgets
	this->begin();

	// image of the ui
	winImage = new Fl_Box(WINUI_X, WINUI_Y, WINUI_WIDTH, WINIMAGE_HEIGHT);
	winImage->box(FL_NO_BOX);
	winImage->image(ResourceManager::WinUI);
	this->add(winImage);

	// button of the ui
	int WIN_BUTTONX = WINUI_X + (WINUI_WIDTH - WIN_BUTTONW) / 2;
	int WIN_BUTTONY = WINUI_Y + WINIMAGE_HEIGHT + 
		(WINUI_HEIGHT - WINIMAGE_HEIGHT - WIN_BUTTONH) / 2;
	button = new Fl_Button(WIN_BUTTONX, WIN_BUTTONY, WIN_BUTTONW, WIN_BUTTONH, "返回主菜单");
	// set style
	button->box(FL_FLAT_BOX);
	button->color(ResourceManager::GREEN);
	button->clear_visible_focus();
	// set font
	button->labelsize(WIN_TEXTSIZE);
	button->labelfont(ResourceManager::HeiTi);
	button->labelcolor(FL_WHITE);
	// set callback
	button->callback(Game::openWinUI, this);

	this->add(button);

	// finish adding widgets
	this->end();
}

WinUI::~WinUI()
{

}