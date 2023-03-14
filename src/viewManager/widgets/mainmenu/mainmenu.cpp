#include "mainmenu.h"
#include "../../../resourceManager/resourceManager.h"

MainMenu::MainMenu():
	Fl_Box(MAINMENU_X, MAINMENU_Y, MAINMENU_WIDTH, MAINMENU_HEIGHT)
{
	// style
	this->box(FL_NO_BOX);
	this->image(ResourceManager::MainMenu);
	// when first create, it should not be shown
	this->hide();
}

MainMenu::~MainMenu()
{

}
