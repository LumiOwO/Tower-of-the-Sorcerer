#include "game.h"
#include "../resourceManager/resourceManager.h"

Game::Game()
{
	// register game
	ResourceManager::registerGame(this);
	// load all resource for the game
	ResourceManager::loadResources();

	// initialize members
	Anime_Timer = new Timer(ANIME_CLK, Game::handleAnime);
	Status_Timer = new Timer(STATUS_CLK, Game::handleStatus);
	dataManager = new DataManager(this);
	viewManager = new ViewManager(this);
	// set game state
	state = MAIN_MENU;
}

Game::~Game()
{
	// stop timer
	Anime_Timer->stop();
	Status_Timer->stop();
	// free members
	delete viewManager;
	delete dataManager;
	delete Anime_Timer;
	delete Status_Timer;
	// free resources
	ResourceManager::freeResources();
}

Game::GameState Game::getState()
{
	return state;
}

int Game::start()
{
	// play the background music
	ResourceManager::playBGM(START_MUSIC);
	// show the main menu
	showMainMenu();
	// print the status
	printStatus("游戏开始");
	return Fl::run();
}

void Game::showMainMenu()
{
	viewManager->showMainMenu();
	stopAnime();
	this->state = MAIN_MENU;
	// update bgm
	ResourceManager::playBGM();
}

void Game::newGame()
{
	// initialize the game map
	// if it's a new game, then init the maps with new maps
	dataManager->setMaps(ResourceManager::New_Maps);
	// init data
	dataManager->initGameData();
	// init game
	initGame();
	// print the status
	printStatus("开始新游戏");
}

void Game::loadGame()
{
	// initialize the game map
	// if it's a load game, then init the maps with saved maps
	dataManager->setMaps(ResourceManager::Saved_Maps);
	// load data
	dataManager->loadHeroInfo();
	// init game
	initGame();
	// print the status
	printStatus("加载游戏存档");
}

void Game::initGame()
{
	// initialize the scene
	drawScene(dataManager->getMap());
	updateInfo();
	viewManager->drawHero(dataManager->getHero());
	// start the timer
	Anime_Timer->start();
	// start the game
	viewManager->startPlaying();
	// set the game state
	this->state = PLAYING;
	// update bgm
	ResourceManager::playBGM(dataManager->getTowerLevel());
}

void Game::moveHero(int keyCode)
{
	// find the direction
	Hero::Direction direction;
	if (keyCode == KEY_W || keyCode == KEY_UP)
		direction = Hero::UP;
	else if (keyCode == KEY_S || keyCode == KEY_DOWN)
		direction = Hero::DOWN;
	else if (keyCode == KEY_A || keyCode == KEY_LEFT)
		direction = Hero::LEFT;
	else if (keyCode == KEY_D || keyCode == KEY_RIGHT)
		direction = Hero::RIGHT;
	// move the hero
	dataManager->moveHero(direction);
	// if the hero can move, redraw the hero
	Hero *hero = dataManager->getHero();
	if (hero->canMove())
		viewManager->drawHero(hero);
}

void Game::stopHero()
{
	// stop the move of hero
	dataManager->stopHero();
	// if the hero can move, redraw the hero
	Hero *hero = dataManager->getHero();
	if (hero->canMove())
		viewManager->drawHero(hero);
}

void Game::drawCell(Cell *cell)
{
	viewManager->drawCell(cell);
}

void Game::drawScene(Map *map)
{
	viewManager->drawScene(dataManager->getMap());
	viewManager->drawHero(dataManager->getHero());
}

void Game::printStatus(string message)
{
	// print status
	viewManager->printStatus(message);
	// reset the timer to show the message
	Status_Timer->reset();
}

void Game::startAnime()
{
	Anime_Timer->start();
}

void Game::stopAnime()
{
	Anime_Timer->stop();
}

void Game::talkToNPC()
{
	if (viewManager->isTalking())
		stopTalking();
	else
	{
		TalkingUI *ui = dataManager->talkToNPC();
		viewManager->showTalkingUI(ui);
	}
}

void Game::stopTalking()
{
	if (viewManager->isTalking())
	{
		viewManager->removeTalkingUI();
		dataManager->stopTalking();
	}
}

void Game::updateInfo()
{
	// update hero info
	viewManager->updateHeroInfo(dataManager->getHero());
	// update tower level
	viewManager->updateTowerLevel(dataManager->getTowerLevel());
	// update key number
	int red = dataManager->getRedKeys();
	int blue = dataManager->getBlueKeys();
	int yellow = dataManager->getYellowKeys();
	viewManager->updateKeys(red, blue, yellow);
}

void Game::handleAnime(void *data)
{
	// get timer
	Timer *timer = (Timer*)data;
	// get game
	Game *game = ResourceManager::game;

	// get enemies
	LinkedList<Cell*> animeCells = game->dataManager->getAnimeCells();
	// draw every enemy
	Cell* cell;
	for (Node<Cell*> *p = animeCells.begin(); p; p = p->getNext())
	{
		cell = p->getValue();
		game->drawCell(cell);
		cell->changePhoto();
	}

	// repeat Timer event
	Fl::repeat_timeout(ANIME_CLK, Game::handleAnime, timer);
}

void Game::handleFight(void *data)
{
	// get timer
	Timer *timer = (Timer*)data;
	// get game
	Game *game = ResourceManager::game;

	// get hero info
	Hero *hero = game->dataManager->getHero();
	Hero::FightState state = hero->getFightState();

	// check whether the timer will continue
	bool wantRepeat = true;
	// modify the fight state of hero
	if (state == Hero::WILL_FIGHT)
	{
		game->dataManager->HeroBeginFight();
	}
	else if (state == Hero::FIGHTING)
	{
		game->dataManager->HeroStopFight();
		// if hero has stopped fight, then stop the timer
		if (hero->getFightState() == Hero::NO_FIGHT)
		{
			timer->stop();
			delete timer;
			// don't want repeat Timer event
			wantRepeat = false;
		}
	}
	// get the cell that hero is in
	int x = hero->getCurrentX();
	int y = hero->getCurrentY();
	Cell *cell = game->dataManager->getCellAt(x, y);
	// redraw the cell that hero is in
	game->drawCell(cell);
	// update the info panel
	game->updateInfo();
	// redraw the hero
	game->viewManager->drawHero(hero);

	// repeat Timer event
	if(wantRepeat)
		Fl::repeat_timeout(FIGHT_CLK, Game::handleFight, timer);
}

void Game::handleDoorOpen(void *data)
{
	// get timer
	Timer *timer = (Timer*)data;
	// get game
	Game *game = ResourceManager::game;

	// get the door
	Door *door = game->dataManager->getOpeningDoor();
	// redraw the door
	game->drawCell(door);
	// redraw the hero
	game->viewManager->drawHero(game->dataManager->getHero());
	// change the photo of the door
	if (!door->shownAllPhotos())
	{
		door->changePhoto();
		// repeat Timer event
		Fl::repeat_timeout(DOOR_CLK, Game::handleDoorOpen, timer);
	}
	else 
	{
		// if all the photos have shown, stop the timer
		timer->stop();
		delete timer;
		// get the position of the door
		int x = door->getCurrentX();
		int y = door->getCurrentY();
		// remove the door in the map
		game->dataManager->removeDoor(door);
		// redraw the removed cell
		game->drawCell(game->dataManager->getCellAt(x, y));
	}
}
void Game::handleStatus(void *data)
{
	// get timer
	Timer *timer = (Timer*)data;
	// get game
	Game *game = ResourceManager::game;

	// clear the status bar message
	game->viewManager->printStatus("");
	// stop the timer
	game->Status_Timer->stop();
}

void Game::transportTo(int dst)
{
	dataManager->transportTo(dst);
}

int Game::getHighestLevel()
{
	return dataManager->getHighestLevel();
}

Hero* Game::getHero()
{
	return dataManager->getHero();
}

LinkedList<Cell*> Game::getEnemies()
{
	return dataManager->getEnemies();
}

ViewManager* Game::getMainWindow()
{
	return viewManager;
}

void Game::transaction(Fl_Widget *widget, void *data)
{
	// get the button and game
	TradeButton *button = (TradeButton*)widget;
	Game *game = ResourceManager::game;
	// get the transaction info
	TradeButton::Currency currency = button->getCurrency();
	TradeButton::Goods goods = button->getGoods();
	int cost = button->getCostAmount();
	int gain = button->getGainAmount();
	// modify the data
	game->dataManager->transaction(currency, goods, cost, gain);
	// update the infoPanel
	game->updateInfo();
	// print the status
	game->printStatus(button->getText());
}

void Game::startNewGame(Fl_Widget *widget, void *data)
{
	// get the game
	Game *game = ResourceManager::game;
	// start a new game
	if(game->state == MAIN_MENU && !game->viewManager->isUIShowing())
		game->newGame();
}

void Game::startLoadGame(Fl_Widget *widget, void *data)
{
	// get the game
	Game *game = ResourceManager::game;
	// start a load game
	if (game->state == MAIN_MENU && !game->viewManager->isUIShowing())
		game->loadGame();
}

void Game::musicControl(Fl_Widget *widget, void *data)
{
	// control signal
	static bool isPlaying = true;
	// store the control button
	static ControlButton *button = nullptr;

	// get the game
	Game *game = ResourceManager::game;
	// record the button for the first call
	if (!button)
	{
		button = (ControlButton*)widget;
		return;
	}

	if (isPlaying)
	{
		// stop the bgm
		isPlaying = false;
		ResourceManager::playBGM(STOP_MUSIC);
		// change the icon
		button->image(ResourceManager::MusicOff);
		button->redraw();
		// print the status
		game->printStatus("关闭音乐");
	}
	else
	{
		// start the bgm
		isPlaying = true;
		ResourceManager::playBGM(START_MUSIC);
		ResourceManager::playBGM(game->dataManager->getTowerLevel());
		// change the icon
		button->image(ResourceManager::MusicOn);
		button->redraw();
		// print the status
		game->printStatus("播放音乐");
	}
}

void Game::saveGame(Fl_Widget *widget, void *data)
{
	// get the game
	Game *game = ResourceManager::game;
	// save game data
	if(game->state == PLAYING
		&& game->dataManager->getHero()->canMove())
		game->dataManager->saveGameData();
}

void Game::goMainMenu(Fl_Widget *widget, void *data)
{
	// get the game
	Game *game = ResourceManager::game;
	// go to the main menu
	if (game->state == PLAYING && !game->viewManager->isUIShowing()
		&& game->dataManager->getHero()->canMove())
	{
		game->showMainMenu();
		// print the status
		game->printStatus("回到主菜单");
	}
	
}

void Game::openHelpDoc(Fl_Widget *widget, void *data)
{
	// store the UI
	static HelpPanel *help = nullptr;

	// get the game
	Game *game = ResourceManager::game;
	// check whether the ESC key is pressed
	bool ESC_Pressed = (Fl::event_key() == KEY_ESC);

	// if the ui is showing, close the help UI
	if (help != nullptr)
	{
		game->hideGivenUI(help);
		help = nullptr;
		game->printStatus("关闭帮助面板");
	}
	// if the ESC is not pressed 
	// and no UI is showing
	// open the UI
	else if (!ESC_Pressed && !game->viewManager->isUIShowing()
		&& game->dataManager->getHero()->canMove())
	{
		help = new HelpPanel();
		game->showGivenUI(help);
		game->printStatus("打开帮助面板");
	}
}

void Game::openTransportUI(Fl_Widget *widget, void *data)
{
	// store the UI
	static TransportPanel *ui = nullptr;

	// get the game
	Game *game = ResourceManager::game;
	// check whether the ESC key is pressed
	bool ESC_Pressed = Fl::event_key() == KEY_ESC;

	if (game->state == PLAYING)
	{
		// if the ui is showing, close the UI
		if (ui != nullptr)
		{
			game->hideGivenUI(ui);
			ui = nullptr;
			game->printStatus("关闭传送面板");
		}
		// if the ESC is not pressed 
		// and no UI is showing
		// open the UI
		else if (!ESC_Pressed && !game->viewManager->isUIShowing()
			&& game->dataManager->getHero()->canMove())
		{
			ui = new TransportPanel();
			game->showGivenUI(ui);
			game->printStatus("打开传送面板");
		}
	}
}

void Game::openWinUI(Fl_Widget *widget, void *data)
{
	// store the UI
	static WinUI *ui = nullptr;

	// get the game
	Game *game = ResourceManager::game;

	// if the ui is showing, close the UI
	if (ui != nullptr)
	{
		game->hideGivenUI(ui);
		ui = nullptr;
		Game::goMainMenu(nullptr, nullptr);
	}
	// else, open the UI
	else
	{
		ui = new WinUI();
		game->showGivenUI(ui);
		game->printStatus("游戏胜利");
	}
}

void Game::openMonsterBook(Fl_Widget *widget, void *data)
{
	// store the UI
	static BookPanel *book = nullptr;

	// get the game
	Game *game = ResourceManager::game;
	// check whether the ESC key is pressed
	bool ESC_Pressed = Fl::event_key() == KEY_ESC;

	if (game->state == PLAYING)
	{
		// if the ui is showing, close the UI
		if (book != nullptr)
		{
			game->hideGivenUI(book);
			book = nullptr;
			game->printStatus("关闭怪物图鉴");
		}
		// if the ESC is not pressed 
		// and no UI is showing
		// open the UI
		else if (!ESC_Pressed && !game->viewManager->isUIShowing()
			&& game->dataManager->getHero()->canMove())
		{
			book = new BookPanel(game->dataManager->getEnemies());
			game->showGivenUI(book);
			game->printStatus("打开怪物图鉴");
		}
	}
}

void Game::showGivenUI(Fl_Widget *ui)
{
	// add the ui into the window
	viewManager->add(ui);
	viewManager->setUIShowing(true);
	// stop the anime and hero
	if (state == PLAYING)
	{
		stopAnime();
		dataManager->getHero()->setWaiting(true);
	}
	// redraw the UI
	ui->redraw();
}

void Game::hideGivenUI(Fl_Widget *ui)
{
	// remove and free the ui
	viewManager->remove(ui);
	viewManager->setUIShowing(false);
	delete ui;
	// restart the anime and let the hero move
	if (state == PLAYING)
	{
		startAnime();
		dataManager->getHero()->setWaiting(false);
	}
	// redraw the window
	viewManager->redraw();
}

