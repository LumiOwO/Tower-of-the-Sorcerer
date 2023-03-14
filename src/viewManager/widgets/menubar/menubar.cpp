#include "menubar.h"
#include "../../../resourceManager/resourceManager.h"
#include "../../../game/game.h"

MenuBar::MenuBar():
	Fl_Menu_Bar(0, 0, MENUBAR_WIDTH, MENUBAR_HEIGHT)
{
	// set style
	this->box(FL_FLAT_BOX);
	// set color
	this->color(FL_WHITE);
	// set font
	this->textfont(ResourceManager::HeiTi);
	this->textsize(MENUBAR_TEXTSIZE);
	// add menu items
	// ^ --> Ctrl
	// control menu
	this->add("控制(C)/_ 回到主菜单  ", "^h", Game::goMainMenu, ResourceManager::game);
	this->add("控制(C)/ 新游戏  ", "^n", Game::startNewGame, ResourceManager::game);
	this->add("控制(C)/_ 继续游戏  ", "^l", Game::startLoadGame, ResourceManager::game);
	this->add("控制(C)/ 音乐开\\/关  ", "^m", Game::musicControl, ResourceManager::game);
	// game menu
	this->add("游戏(G)/ 存储当前进度  ", "^o", Game::saveGame, ResourceManager::game);
	this->add("游戏(G)/ 怪物图鉴开\\/关  ", "^b", Game::openMonsterBook, ResourceManager::game);
	this->add("游戏(G)/ 传送界面开\\/关  ", "^t", Game::openTransportUI, ResourceManager::game);
	// help menu
	this->add("帮助(H)/ 帮助界面开\\/关  ", "^q", Game::openHelpDoc, ResourceManager::game);
	// when first create, it should not be shown
	this->hide();
}

MenuBar::~MenuBar()
{

}