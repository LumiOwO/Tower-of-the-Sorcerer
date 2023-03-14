#include "helpPanel.h"
#include "../../../resourceManager/resourceManager.h"

HelpPanel::HelpPanel():
	TextDisplay(HELP_X, HELP_Y, HELP_WIDTH, HELP_HEIGHT)
{
	this->color(ResourceManager::HelpPanelColor);
	this->setText(ResourceManager::helpText.data());
}

HelpPanel::~HelpPanel()
{

}