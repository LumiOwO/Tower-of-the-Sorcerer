#include "viewManager.h"
#include "../game/game.h"
#include "../resourceManager/resourceManager.h"

using namespace Graph_lib;
ViewManager::ViewManager(Game *game):
	Window(Point(WIN_X, WIN_Y), WIN_WIDTH, WIN_HEIGHT, GAME_TITLE)
{
	// set window icon
	this->icon((const Fl_RGB_Image*)ResourceManager::WindowIcon);

	this->game = game;
	UIShowing = false;

	menuBar = new MenuBar();
	statusBar = new StatusBar();

	// music button
	musicButton = new ControlButton(
		SMALLBUTTON_X,
		SMALLBUTTON_Y,
		SMALLBUTTON_WIDTH,
		SMALLBUTTON_HEIGHT,
		Game::musicControl
	);
	// set image
	musicButton->image(ResourceManager::MusicOn);
	// do callback to turn on the music
	Game::musicControl(musicButton, nullptr);

	// help button
	helpButton = new ControlButton(
		SMALLBUTTON_X - SMALLBUTTON_WIDTH,
		SMALLBUTTON_Y,
		SMALLBUTTON_WIDTH,
		SMALLBUTTON_HEIGHT,
		Game::openHelpDoc
	);
	// set image
	helpButton->image(ResourceManager::Help);

	// main menu widgets
	mainMenu = new MainMenu();
	// new game button
	newGameButton = new ControlButton(
		GAMEBUTTON_X,
		GAMEBUTTON_Y,
		GAMEBUTTON_WIDTH,
		GAMEBUTTON_HEIGHT,
		Game::startNewGame,
		"新游戏"
	);
	// load game button
	loadGameButton = new ControlButton(
		GAMEBUTTON_X,
		GAMEBUTTON_Y + GAMEBUTTON_HEIGHT + GAMEBUTTON_INTERVAL,
		GAMEBUTTON_WIDTH,
		GAMEBUTTON_HEIGHT,
		Game::startLoadGame,
		"继续游戏"
	);

	// game widgets
	scene = new Scene();
	infoPanel = new InfoPanel();
	talkingUI = nullptr;

	// save button
	saveButton = new ControlButton(
		SMALLBUTTON_X - 2 * SMALLBUTTON_WIDTH,
		SMALLBUTTON_Y,
		SMALLBUTTON_WIDTH,
		SMALLBUTTON_HEIGHT,
		Game::saveGame
	);
	// set image
	saveButton->image(ResourceManager::SaveGame);

	// homepage button
	homeButton = new ControlButton(
		SMALLBUTTON_X - 3 * SMALLBUTTON_WIDTH,
		SMALLBUTTON_Y,
		SMALLBUTTON_WIDTH,
		SMALLBUTTON_HEIGHT,
		Game::goMainMenu
	);
	// set image
	homeButton->image(ResourceManager::HomePage);

	// transport button
	transportButton = new ControlButton(
		FUNCBUTTON_X,
		FUNCBUTTON_Y,
		FUNCBUTTON_WIDTH,
		FUNCBUTTON_HEIGHT,
		Game::openTransportUI
	);
	// set image
	transportButton->image(ResourceManager::Transport);

	// book button
	bookButton = new ControlButton(
		FUNCBUTTON_X - FUNCBUTTON_WIDTH,
		FUNCBUTTON_Y,
		FUNCBUTTON_WIDTH,
		FUNCBUTTON_HEIGHT,
		Game::openMonsterBook
	);
	// set image
	bookButton->image(ResourceManager::Book);

	// set window title
	this->label(GAME_TITLE);
	// set window styles
	this->color(ResourceManager::BackgroundColor);
	// make the window not resizable 
	this->size_range(WIN_WIDTH, WIN_HEIGHT, WIN_WIDTH, WIN_HEIGHT);
	// begin to add widgets into the window
	this->begin();
		this->add(menuBar);
		this->add(statusBar);
		this->add(musicButton);
		this->add(helpButton);

		this->add(mainMenu);
		this->add(newGameButton);
		this->add(loadGameButton);

		this->add(scene);
		this->add(infoPanel);
		this->add(saveButton);
		this->add(homeButton);
		this->add(transportButton);
		this->add(bookButton);
	this->end();

	// show the menubar and status bar
	menuBar->show();
	statusBar->show();
	musicButton->show();
	helpButton->show();
}

ViewManager::~ViewManager()
{
	// window widgets
	delete menuBar;
	delete statusBar;
	delete musicButton;
	delete helpButton;
	// main menu widgets
	delete mainMenu;
	delete newGameButton;
	delete loadGameButton;
	// game widgets
	delete scene;
	delete infoPanel;
	delete saveButton;
	delete homeButton;
	delete transportButton;
	delete bookButton;
	if (talkingUI)
		delete talkingUI;
}

void ViewManager::showMainMenu()
{
	// show the main menu
	mainMenu->show();
	newGameButton->show();
	loadGameButton->show();
	// hide the game widgets
	scene->hide();
	infoPanel->hide();
	saveButton->hide();
	homeButton->hide();
	transportButton->hide();
	bookButton->hide();
	removeTalkingUI();
	// redraw the window
	this->redraw();
}

void ViewManager::startPlaying()
{
	// hide the main menu
	mainMenu->hide();
	newGameButton->hide();
	loadGameButton->hide();
	// show the map and info panel
	scene->show();
	infoPanel->show();
	saveButton->show();
	homeButton->show();
	transportButton->show();
	bookButton->show();
	// redraw the window
	this->redraw();
}

void ViewManager::drawScene(Map *map)
{
	int matrixWidth = Map::getMatrixWidth();
	for (int i = 0; i < matrixWidth; i++)
		for (int j = 0; j < matrixWidth; j++)
			scene->drawCell(map->getCellAt(i, j));
}	

void ViewManager::drawCell(Cell *cell)
{
	scene->drawCell(cell);
}

void ViewManager::drawHero(Hero *hero)
{
	scene->drawHero(hero);
}

void ViewManager::updateHeroInfo(Hero *hero)
{
	// update the values
	infoPanel->updateHeroInfo(hero);
	// redraw the panel
	infoPanel->updateValueTexts();
}

void ViewManager::updateTowerLevel(int towerLevel)
{
	// update the value
	infoPanel->updateTowerLevel(towerLevel);
	// redraw the panel
	infoPanel->updateValueTexts();
}

void ViewManager::updateKeys(int red, int blue, int yellow)
{
	// update the value
	infoPanel->updateKeys(red, blue, yellow);
	// redraw the panel
	infoPanel->updateValueTexts();
}

void ViewManager::printStatus(string message)
{
	statusBar->printStatus(message);
}

bool ViewManager::isTalking()
{
	return talkingUI != nullptr;
}

void ViewManager::showTalkingUI(TalkingUI *ui)
{
	if (ui)
	{
		// stop anime
		game->stopAnime();
		// set the UI
		talkingUI = ui;
		this->add(talkingUI);
		// show the UI
		UIShowing = true;
		talkingUI->show();
		// focus the window instead of the UI
		Fl::focus(this);
		// print status
		game->printStatus("与人物进行对话");
	}
}

void ViewManager::removeTalkingUI()
{
	if (talkingUI)
	{
		// hide the UI
		talkingUI->hide();
		// remove the UI
		UIShowing = false;
		this->remove(talkingUI);
		talkingUI = nullptr;
		// restart the anime
		game->startAnime();
		// print the status
		game->printStatus("结束对话");
	}
}

bool ViewManager::isUIShowing()
{
	return UIShowing;
}

void ViewManager::setUIShowing(bool showing)
{
	UIShowing = showing;
}

int ViewManager::handle(int event)
{
	// if handle the event, return 1
	int ret;
	// get key code
	int keyCode = Fl::event_key();
	// get the state of the game
	Game::GameState state = game->getState();

	// direction keys
	if (state == Game::PLAYING && 
		(keyCode == KEY_W || keyCode == KEY_A ||
		 keyCode == KEY_S || keyCode == KEY_D ||
		 keyCode == KEY_UP || keyCode == KEY_DOWN || 
		 keyCode == KEY_LEFT || keyCode == KEY_RIGHT) )
	{
		if(event == FL_KEYDOWN)
			game->moveHero(keyCode);
		else if(event == FL_KEYUP)
			game->stopHero();
		ret = 1;
	}
	// space
	else if (state == Game::PLAYING && 
		keyCode == KEY_SPACE && event == FL_KEYDOWN)
	{
		game->talkToNPC();
		ret = 1;
	}
	// Esc
	else if (keyCode == KEY_ESC && event == FL_KEYDOWN)
	{
		game->stopTalking();
		Game::openHelpDoc(nullptr, nullptr);
		Game::openMonsterBook(nullptr, nullptr);
		Game::openTransportUI(nullptr, nullptr);
		ret = 1;
	}
	// else, return the default handle
	else
		ret = Window::handle(event);

	return ret;
}