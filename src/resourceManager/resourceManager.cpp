#include "resourceManager.h"
#include "../dataManager/elements/map/map.h"
#include "../game/game.h"

#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <windows.h>
#include <mmsystem.h>
#include <fstream>

// variable declare
// game
Game *ResourceManager::game;

// text
string ResourceManager::helpText;

// colors
Fl_Color ResourceManager::BackgroundColor;
Fl_Color ResourceManager::HelpPanelColor;
Fl_Color ResourceManager::GREEN;
// fonts
Fl_Font ResourceManager::HeiTi;

// bgm
LinkedList<Music> ResourceManager::bgm;

// images
// icons
Fl_Image* ResourceManager::WindowIcon;

Fl_Image* ResourceManager::MusicOn;
Fl_Image* ResourceManager::MusicOff;
Fl_Image* ResourceManager::SaveGame;
Fl_Image* ResourceManager::HomePage;
Fl_Image* ResourceManager::Help;
Fl_Image* ResourceManager::Transport;
Fl_Image* ResourceManager::Book;
// ui
Fl_Image* ResourceManager::MainMenu;
Fl_Image* ResourceManager::WinUI;
// barrier
Fl_Image* ResourceManager::ground;
Fl_Image* ResourceManager::brick_wall;
LinkedList<Fl_Image*> ResourceManager::star;
LinkedList<Fl_Image*> ResourceManager::lava;

LinkedList<Fl_Image*> ResourceManager::stone_left;
LinkedList<Fl_Image*> ResourceManager::stone_right;

LinkedList<Fl_Image*> ResourceManager::dragon_nw;
LinkedList<Fl_Image*> ResourceManager::dragon_n;
LinkedList<Fl_Image*> ResourceManager::dragon_ne;
LinkedList<Fl_Image*> ResourceManager::dragon_w;
LinkedList<Fl_Image*> ResourceManager::dragon_m;
LinkedList<Fl_Image*> ResourceManager::dragon_e;
LinkedList<Fl_Image*> ResourceManager::dragon_sw;
LinkedList<Fl_Image*> ResourceManager::dragon_se;

// doors
LinkedList<Fl_Image*> ResourceManager::auto_door;
LinkedList<Fl_Image*> ResourceManager::red_door;
LinkedList<Fl_Image*> ResourceManager::blue_door;
LinkedList<Fl_Image*> ResourceManager::yellow_door;

// items
Fl_Image* ResourceManager::red_key;
Fl_Image* ResourceManager::blue_key;
Fl_Image* ResourceManager::yellow_key;
Fl_Image* ResourceManager::super_key;

Fl_Image* ResourceManager::RedKeyTrans;
Fl_Image* ResourceManager::BlueKeyTrans;
Fl_Image* ResourceManager::YellowKeyTrans;

Fl_Image* ResourceManager::red_potion;
Fl_Image* ResourceManager::blue_potion;
Fl_Image* ResourceManager::super_potion;

Fl_Image* ResourceManager::red_crystal;
Fl_Image* ResourceManager::blue_crystal;

Fl_Image* ResourceManager::sword_primary;
Fl_Image* ResourceManager::sword_medium;
Fl_Image* ResourceManager::sword_super;

Fl_Image* ResourceManager::shield_primary;
Fl_Image* ResourceManager::shield_medium;
Fl_Image* ResourceManager::shield_super;

Fl_Image* ResourceManager::coin;
Fl_Image* ResourceManager::level_up;

// special
Fl_Image* ResourceManager::cross;
Fl_Image* ResourceManager::fire_wand;
Fl_Image* ResourceManager::ice_wand;
Fl_Image* ResourceManager::earth_wand;

// stairs
Fl_Image* ResourceManager::upstairs;
Fl_Image* ResourceManager::downstairs;

// enemy
LinkedList<Fl_Image*> ResourceManager::green_slime;
LinkedList<Fl_Image*> ResourceManager::red_slime;
LinkedList<Fl_Image*> ResourceManager::ghost_slime;
LinkedList<Fl_Image*> ResourceManager::big_slime;

LinkedList<Fl_Image*> ResourceManager::small_bat;
LinkedList<Fl_Image*> ResourceManager::big_bat;
LinkedList<Fl_Image*> ResourceManager::red_bat;

LinkedList<Fl_Image*> ResourceManager::skeleton;
LinkedList<Fl_Image*> ResourceManager::skeleton_warrior;
LinkedList<Fl_Image*> ResourceManager::skeleton_captain;
LinkedList<Fl_Image*> ResourceManager::skeleton_armored;

LinkedList<Fl_Image*> ResourceManager::orc;
LinkedList<Fl_Image*> ResourceManager::orc_warrior;

LinkedList<Fl_Image*> ResourceManager::wizard;
LinkedList<Fl_Image*> ResourceManager::red_wizard;

LinkedList<Fl_Image*> ResourceManager::mage;
LinkedList<Fl_Image*> ResourceManager::red_mage;

LinkedList<Fl_Image*> ResourceManager::head_monster;

LinkedList<Fl_Image*> ResourceManager::dual_blade;

LinkedList<Fl_Image*> ResourceManager::golden_guard;
LinkedList<Fl_Image*> ResourceManager::blue_guard;
LinkedList<Fl_Image*> ResourceManager::red_guard;

LinkedList<Fl_Image*> ResourceManager::red_knight;
LinkedList<Fl_Image*> ResourceManager::yellow_knight;
LinkedList<Fl_Image*> ResourceManager::blue_knight;
LinkedList<Fl_Image*> ResourceManager::armored_knight;
LinkedList<Fl_Image*> ResourceManager::ghost_knight;
LinkedList<Fl_Image*> ResourceManager::ghost_knight_captain;

LinkedList<Fl_Image*> ResourceManager::green_ghost;

LinkedList<Fl_Image*> ResourceManager::red_lord;
LinkedList<Fl_Image*> ResourceManager::ghost_lord;
LinkedList<Fl_Image*> ResourceManager::dragon;

// NPC
LinkedList<Fl_Image*> ResourceManager::fairy;
LinkedList<Fl_Image*> ResourceManager::princess;
LinkedList<Fl_Image*> ResourceManager::old_man;
LinkedList<Fl_Image*> ResourceManager::stone;
LinkedList<Fl_Image*> ResourceManager::merchant;

// hero
LinkedList<Fl_Image*> ResourceManager::HeroPhotos;
Fl_Image* ResourceManager::Fighting;

// maps
LinkedList<Map*> ResourceManager::New_Maps;
LinkedList<Map*> ResourceManager::Saved_Maps;

void ResourceManager::registerGame(Game *game)
{
	ResourceManager::game = game;
}

void ResourceManager::loadResources()
{
	// text
	ifstream in("./res/text/help.txt");
	char buffer;
	while (in.get(buffer))
		helpText += buffer;
	
	in.close();

	// colors
	BackgroundColor = fl_rgb_color(53, 56, 52);
	HelpPanelColor = fl_rgb_color(59, 61, 77);
	GREEN = fl_rgb_color(126, 157, 0);

	// fonts
	HeiTi = FL_FREE_FONT + 1;
	Fl::set_font(HeiTi, "黑体");

	// music
	bgm = LinkedList<Music>({ 
		"./res/bgm/0.wav",
		"./res/bgm/1.wav",
		"./res/bgm/2.wav",
		"./res/bgm/3.wav"
	});

	// images
	// icons
	WindowIcon = new Fl_PNG_Image("./res/icon/icon.png");

	MusicOn = new Fl_PNG_Image("./res/icon/MusicOn.png");
	MusicOff = new Fl_PNG_Image("./res/icon/MusicOff.png");
	SaveGame = new Fl_PNG_Image("./res/icon/SaveGame.png");
	HomePage = new Fl_PNG_Image("./res/icon/HomePage.png");
	Help = new Fl_PNG_Image("./res/icon/Help.png");
	Transport = new Fl_PNG_Image("./res/icon/Transport.png");
	Book = new Fl_PNG_Image("./res/icon/Book.png");
	// ui
	MainMenu = new Fl_JPEG_Image("./res/ui/MainMenu.jpg");
	WinUI = new Fl_PNG_Image("./res/ui/WinUI.png");

	// barrier
	ground = new Fl_JPEG_Image("./res/barrier/ground.jpg");
	brick_wall = new Fl_JPEG_Image("./res/barrier/brick_wall.jpg");
	star = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/barrier/star0.jpg"),
		new Fl_JPEG_Image("./res/barrier/star1.jpg"),
		});
	lava = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/barrier/lava0.jpg"),
		new Fl_JPEG_Image("./res/barrier/lava1.jpg"),
		});

	stone_left = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/barrier/stone_left0.jpg"),
		new Fl_JPEG_Image("./res/barrier/stone_left1.jpg"),
		});
	stone_right = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/barrier/stone_right0.jpg"),
		new Fl_JPEG_Image("./res/barrier/stone_right1.jpg"),
		});

	dragon_nw = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/barrier/dragon_nw0.jpg"),
		new Fl_JPEG_Image("./res/barrier/dragon_nw1.jpg"),
		});
	dragon_n = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/barrier/dragon_n0.jpg"),
		new Fl_JPEG_Image("./res/barrier/dragon_n1.jpg"),
		});
	dragon_ne = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/barrier/dragon_ne0.jpg"),
		new Fl_JPEG_Image("./res/barrier/dragon_ne1.jpg"),
		});
	dragon_w = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/barrier/dragon_w0.jpg"),
		new Fl_JPEG_Image("./res/barrier/dragon_w1.jpg"),
		});
	dragon_m = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/barrier/dragon_m0.jpg"),
		new Fl_JPEG_Image("./res/barrier/dragon_m1.jpg"),
		});
	dragon_e = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/barrier/dragon_e0.jpg"),
		new Fl_JPEG_Image("./res/barrier/dragon_e1.jpg"),
		});
	dragon_sw = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/barrier/dragon_sw0.jpg"),
		new Fl_JPEG_Image("./res/barrier/dragon_sw1.jpg"),
		});
	dragon_se = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/barrier/dragon_se0.jpg"),
		new Fl_JPEG_Image("./res/barrier/dragon_se1.jpg"),
		});

	// doors
	auto_door = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/barrier/auto_door0.jpg"),
		new Fl_JPEG_Image("./res/barrier/auto_door1.jpg"),
		new Fl_JPEG_Image("./res/barrier/auto_door2.jpg"),
		new Fl_JPEG_Image("./res/barrier/auto_door3.jpg"),
		});
	red_door = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/barrier/red_door0.jpg"),
		new Fl_JPEG_Image("./res/barrier/red_door1.jpg"),
		new Fl_JPEG_Image("./res/barrier/red_door2.jpg"),
		new Fl_JPEG_Image("./res/barrier/red_door3.jpg")
		});
	blue_door = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/barrier/blue_door0.jpg"),
		new Fl_JPEG_Image("./res/barrier/blue_door1.jpg"),
		new Fl_JPEG_Image("./res/barrier/blue_door2.jpg"),
		new Fl_JPEG_Image("./res/barrier/blue_door3.jpg")
		});
	yellow_door = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/barrier/yellow_door0.jpg"),
		new Fl_JPEG_Image("./res/barrier/yellow_door1.jpg"),
		new Fl_JPEG_Image("./res/barrier/yellow_door2.jpg"),
		new Fl_JPEG_Image("./res/barrier/yellow_door3.jpg")
		});

	// items
	red_key = new Fl_JPEG_Image("./res/item/red_key.jpg");
	blue_key = new Fl_JPEG_Image("./res/item/blue_key.jpg");
	yellow_key = new Fl_JPEG_Image("./res/item/yellow_key.jpg");
	super_key = new Fl_JPEG_Image("./res/item/super_key.jpg");

	RedKeyTrans = new Fl_PNG_Image("./res/item/RedKeyTrans.png");
	BlueKeyTrans = new Fl_PNG_Image("./res/item/BlueKeyTrans.png");
	YellowKeyTrans = new Fl_PNG_Image("./res/item/YellowKeyTrans.png");

	red_potion = new Fl_JPEG_Image("./res/item/red_potion.jpg");
	blue_potion = new Fl_JPEG_Image("./res/item/blue_potion.jpg");
	super_potion = new Fl_JPEG_Image("./res/item/super_potion.jpg");

	red_crystal = new Fl_JPEG_Image("./res/item/red_crystal.jpg");
	blue_crystal = new Fl_JPEG_Image("./res/item/blue_crystal.jpg");

	sword_primary = new Fl_JPEG_Image("./res/item/sword_primary.jpg");
	sword_medium = new Fl_JPEG_Image("./res/item/sword_medium.jpg");
	sword_super = new Fl_JPEG_Image("./res/item/sword_super.jpg");

	shield_primary = new Fl_JPEG_Image("./res/item/shield_primary.jpg");
	shield_medium = new Fl_JPEG_Image("./res/item/shield_medium.jpg");
	shield_super = new Fl_JPEG_Image("./res/item/shield_super.jpg");

	coin = new Fl_JPEG_Image("./res/item/coin.jpg");
	level_up = new Fl_JPEG_Image("./res/item/level_up.jpg");

	// special
	cross = new Fl_JPEG_Image("./res/item/cross.jpg");
	fire_wand = new Fl_JPEG_Image("./res/item/fire_wand.jpg");
	ice_wand = new Fl_JPEG_Image("./res/item/ice_wand.jpg");
	earth_wand = new Fl_JPEG_Image("./res/item/earth_wand.jpg");

	// stairs
	upstairs = new Fl_JPEG_Image("./res/item/upstairs.jpg");
	downstairs = new Fl_JPEG_Image("./res/item/downstairs.jpg");

	// enemy
	green_slime = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/green_slime0.jpg"),
		new Fl_JPEG_Image("./res/enemy/green_slime1.jpg"),
		});
	red_slime = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/red_slime0.jpg"),
		new Fl_JPEG_Image("./res/enemy/red_slime1.jpg"),
		});
	ghost_slime = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/ghost_slime0.jpg"),
		new Fl_JPEG_Image("./res/enemy/ghost_slime1.jpg"),
		});
	big_slime = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/big_slime0.jpg"),
		new Fl_JPEG_Image("./res/enemy/big_slime1.jpg"),
		});

	small_bat = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/small_bat0.jpg"),
		new Fl_JPEG_Image("./res/enemy/small_bat1.jpg"),
		});
	big_bat = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/big_bat0.jpg"),
		new Fl_JPEG_Image("./res/enemy/big_bat1.jpg"),
		});
	red_bat = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/red_bat0.jpg"),
		new Fl_JPEG_Image("./res/enemy/red_bat1.jpg"),
		});

	skeleton = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/skeleton0.jpg"),
		new Fl_JPEG_Image("./res/enemy/skeleton1.jpg"),
		});
	skeleton_warrior = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/skeleton_warrior0.jpg"),
		new Fl_JPEG_Image("./res/enemy/skeleton_warrior1.jpg"),
		});
	skeleton_captain = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/skeleton_captain0.jpg"),
		new Fl_JPEG_Image("./res/enemy/skeleton_captain1.jpg"),
		});
	skeleton_armored = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/skeleton_armored0.jpg"),
		new Fl_JPEG_Image("./res/enemy/skeleton_armored1.jpg"),
		});

	orc = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/orc0.jpg"),
		new Fl_JPEG_Image("./res/enemy/orc1.jpg"),
		});
	orc_warrior = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/orc_warrior0.jpg"),
		new Fl_JPEG_Image("./res/enemy/orc_warrior1.jpg"),
		});

	wizard = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/wizard0.jpg"),
		new Fl_JPEG_Image("./res/enemy/wizard1.jpg"),
		});
	red_wizard = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/red_wizard0.jpg"),
		new Fl_JPEG_Image("./res/enemy/red_wizard1.jpg"),
		});

	mage = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/mage0.jpg"),
		new Fl_JPEG_Image("./res/enemy/mage1.jpg"),
		});
	red_mage = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/red_mage0.jpg"),
		new Fl_JPEG_Image("./res/enemy/red_mage1.jpg"),
		});

	head_monster = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/head_monster0.jpg"),
		new Fl_JPEG_Image("./res/enemy/head_monster1.jpg"),
		});

	dual_blade = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/dual_blade0.jpg"),
		new Fl_JPEG_Image("./res/enemy/dual_blade1.jpg"),
		});

	golden_guard = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/golden_guard0.jpg"),
		new Fl_JPEG_Image("./res/enemy/golden_guard1.jpg"),
		});
	blue_guard = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/blue_guard0.jpg"),
		new Fl_JPEG_Image("./res/enemy/blue_guard1.jpg"),
		});
	red_guard = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/red_guard0.jpg"),
		new Fl_JPEG_Image("./res/enemy/red_guard1.jpg"),
		});

	red_knight = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/red_knight0.jpg"),
		new Fl_JPEG_Image("./res/enemy/red_knight1.jpg"),
		});
	yellow_knight = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/yellow_knight0.jpg"),
		new Fl_JPEG_Image("./res/enemy/yellow_knight1.jpg"),
		});
	blue_knight = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/blue_knight0.jpg"),
		new Fl_JPEG_Image("./res/enemy/blue_knight1.jpg"),
		}); 
	armored_knight = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/armored_knight0.jpg"),
		new Fl_JPEG_Image("./res/enemy/armored_knight1.jpg"),
			});
	ghost_knight = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/ghost_knight0.jpg"),
		new Fl_JPEG_Image("./res/enemy/ghost_knight1.jpg"),
		});
	ghost_knight_captain = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/ghost_knight_captain0.jpg"),
		new Fl_JPEG_Image("./res/enemy/ghost_knight_captain1.jpg"),
		});

	green_ghost = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/green_ghost0.jpg"),
		new Fl_JPEG_Image("./res/enemy/green_ghost1.jpg"),
		});

	red_lord = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/red_lord0.jpg"),
		new Fl_JPEG_Image("./res/enemy/red_lord1.jpg"),
		});
	ghost_lord = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/ghost_lord0.jpg"),
		new Fl_JPEG_Image("./res/enemy/ghost_lord1.jpg"),
		});
	dragon = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/enemy/dragon0.jpg"),
		new Fl_JPEG_Image("./res/enemy/dragon1.jpg"),
		});

	// NPC
	fairy = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/npc/fairy0.jpg"),
		new Fl_JPEG_Image("./res/npc/fairy1.jpg"),
		});
	princess = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/npc/princess0.jpg"),
		new Fl_JPEG_Image("./res/npc/princess1.jpg"),
		});
	old_man = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/npc/old_man0.jpg"),
		new Fl_JPEG_Image("./res/npc/old_man1.jpg"),
		});
	stone = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/npc/stone0.jpg"),
		new Fl_JPEG_Image("./res/npc/stone1.jpg"),
		});
	merchant = LinkedList<Fl_Image*>({
		new Fl_JPEG_Image("./res/npc/merchant0.jpg"),
		new Fl_JPEG_Image("./res/npc/merchant1.jpg"),
		});

	// hero
	HeroPhotos = LinkedList<Fl_Image*>({
		new Fl_PNG_Image("./res/hero/HeroUp.png"),
		new Fl_PNG_Image("./res/hero/HeroDown.png"),
		new Fl_PNG_Image("./res/hero/HeroLeft.png"),
		new Fl_PNG_Image("./res/hero/HeroRight.png"),
		new Fl_PNG_Image("./res/hero/HeroUpMove.png"),
		new Fl_PNG_Image("./res/hero/HeroDownMove.png"),
		new Fl_PNG_Image("./res/hero/HeroLeftMove.png"),
		new Fl_PNG_Image("./res/hero/HeroRightMove.png")
		});
	Fighting = new Fl_PNG_Image("./res/hero/Fighting.png");

	// maps
	// new maps
	string NewMapTitle_prefix = "./res/map/map_";
	for (int i = 0; i < TOTAL_MAPS; i++)
	{
		Map *map = new Map(NewMapTitle_prefix + to_string(i));
		New_Maps.push_back(map);
	}
	// saved maps
	string SavedMapTitle_prefix = "./res/save/map_";
	for (int i = 0; i < TOTAL_MAPS; i++)
	{
		Map *map = new Map(SavedMapTitle_prefix + to_string(i));
		Saved_Maps.push_back(map);
	}
}

void ResourceManager::freeResources()
{
	// images
	// icons
	delete WindowIcon;

	delete MusicOn;
	delete MusicOff;
	delete SaveGame;
	delete HomePage;
	delete Help;
	delete Transport;
	delete Book;
	// ui
	delete MainMenu;
	delete WinUI;

	// barrier
	delete ground;
	delete brick_wall;
	for (Node<Fl_Image*> *p = star.begin(); p; p = p->getNext())
		delete p->getValue();
	star.clear();
	for (Node<Fl_Image*> *p = lava.begin(); p; p = p->getNext())
		delete p->getValue();
	lava.clear();

	for (Node<Fl_Image*> *p = stone_left.begin(); p; p = p->getNext())
		delete p->getValue();
	stone_left.clear();
	for (Node<Fl_Image*> *p = stone_right.begin(); p; p = p->getNext())
		delete p->getValue();
	stone_right.clear();

	for (Node<Fl_Image*> *p = dragon_nw.begin(); p; p = p->getNext())
		delete p->getValue();
	dragon_nw.clear();
	for (Node<Fl_Image*> *p = dragon_n.begin(); p; p = p->getNext())
		delete p->getValue();
	dragon_n.clear();
	for (Node<Fl_Image*> *p = dragon_ne.begin(); p; p = p->getNext())
		delete p->getValue();
	dragon_ne.clear();
	for (Node<Fl_Image*> *p = dragon_w.begin(); p; p = p->getNext())
		delete p->getValue();
	dragon_w.clear();
	for (Node<Fl_Image*> *p = dragon_m.begin(); p; p = p->getNext())
		delete p->getValue();
	dragon_m.clear();
	for (Node<Fl_Image*> *p = dragon_e.begin(); p; p = p->getNext())
		delete p->getValue();
	dragon_e.clear();
	for (Node<Fl_Image*> *p = dragon_sw.begin(); p; p = p->getNext())
		delete p->getValue();
	dragon_sw.clear();
	for (Node<Fl_Image*> *p = dragon_se.begin(); p; p = p->getNext())
		delete p->getValue();
	dragon_se.clear();

	// doors
	for (Node<Fl_Image*> *p = auto_door.begin(); p; p = p->getNext())
		delete p->getValue();
	auto_door.clear();
	for (Node<Fl_Image*> *p = red_door.begin(); p; p = p->getNext())
		delete p->getValue();
	red_door.clear();
	for (Node<Fl_Image*> *p = blue_door.begin(); p; p = p->getNext())
		delete p->getValue();
	blue_door.clear();
	for (Node<Fl_Image*> *p = yellow_door.begin(); p; p = p->getNext())
		delete p->getValue();
	yellow_door.clear();

	// items
	delete red_key;
	delete blue_key;
	delete yellow_key;
	delete super_key;

	delete RedKeyTrans;
	delete BlueKeyTrans;
	delete YellowKeyTrans;

	delete red_potion;
	delete blue_potion;
	delete super_potion;

	delete red_crystal;
	delete blue_crystal;

	delete sword_primary;
	delete sword_medium;
	delete sword_super;

	delete shield_primary;
	delete shield_medium;
	delete shield_super;

	delete coin;
	delete level_up;

	// special
	delete cross;
	delete fire_wand;
	delete ice_wand;
	delete earth_wand;

	// stairs
	delete upstairs;
	delete downstairs;

	// enemy
	for (Node<Fl_Image*> *p = green_slime.begin(); p; p = p->getNext())
		delete p->getValue();
	green_slime.clear();
	for (Node<Fl_Image*> *p = red_slime.begin(); p; p = p->getNext())
		delete p->getValue();
	red_slime.clear();
	for (Node<Fl_Image*> *p = ghost_slime.begin(); p; p = p->getNext())
		delete p->getValue();
	ghost_slime.clear();
	for (Node<Fl_Image*> *p = big_slime.begin(); p; p = p->getNext())
		delete p->getValue();
	big_slime.clear();

	for (Node<Fl_Image*> *p = small_bat.begin(); p; p = p->getNext())
		delete p->getValue();
	small_bat.clear();
	for (Node<Fl_Image*> *p = big_bat.begin(); p; p = p->getNext())
		delete p->getValue();
	big_bat.clear();
	for (Node<Fl_Image*> *p = red_bat.begin(); p; p = p->getNext())
		delete p->getValue();
	red_bat.clear();

	for (Node<Fl_Image*> *p = skeleton.begin(); p; p = p->getNext())
		delete p->getValue();
	skeleton.clear();
	for (Node<Fl_Image*> *p = skeleton_warrior.begin(); p; p = p->getNext())
		delete p->getValue();
	skeleton_warrior.clear();
	for (Node<Fl_Image*> *p = skeleton_captain.begin(); p; p = p->getNext())
		delete p->getValue();
	skeleton_captain.clear();
	for (Node<Fl_Image*> *p = skeleton_armored.begin(); p; p = p->getNext())
		delete p->getValue();
	skeleton_armored.clear();

	for (Node<Fl_Image*> *p = orc.begin(); p; p = p->getNext())
		delete p->getValue();
	orc.clear();
	for (Node<Fl_Image*> *p = orc_warrior.begin(); p; p = p->getNext())
		delete p->getValue();
	orc_warrior.clear();

	for (Node<Fl_Image*> *p = wizard.begin(); p; p = p->getNext())
		delete p->getValue();
	wizard.clear();
	for (Node<Fl_Image*> *p = red_wizard.begin(); p; p = p->getNext())
		delete p->getValue();
	red_wizard.clear();

	for (Node<Fl_Image*> *p = mage.begin(); p; p = p->getNext())
		delete p->getValue();
	mage.clear();
	for (Node<Fl_Image*> *p = red_mage.begin(); p; p = p->getNext())
		delete p->getValue();
	red_mage.clear();

	for (Node<Fl_Image*> *p = head_monster.begin(); p; p = p->getNext())
		delete p->getValue();
	head_monster.clear();

	for (Node<Fl_Image*> *p = dual_blade.begin(); p; p = p->getNext())
		delete p->getValue();
	dual_blade.clear();

	for (Node<Fl_Image*> *p = golden_guard.begin(); p; p = p->getNext())
		delete p->getValue();
	golden_guard.clear();
	for (Node<Fl_Image*> *p = blue_guard.begin(); p; p = p->getNext())
		delete p->getValue();
	blue_guard.clear();
	for (Node<Fl_Image*> *p = red_guard.begin(); p; p = p->getNext())
		delete p->getValue();
	red_guard.clear();

	for (Node<Fl_Image*> *p = red_knight.begin(); p; p = p->getNext())
		delete p->getValue();
	red_knight.clear();
	for (Node<Fl_Image*> *p = yellow_knight.begin(); p; p = p->getNext())
		delete p->getValue();
	yellow_knight.clear();
	for (Node<Fl_Image*> *p = blue_knight.begin(); p; p = p->getNext())
		delete p->getValue();
	blue_knight.clear();
	for (Node<Fl_Image*> *p = armored_knight.begin(); p; p = p->getNext())
		delete p->getValue();
	armored_knight.clear();
	for (Node<Fl_Image*> *p = ghost_knight.begin(); p; p = p->getNext())
		delete p->getValue();
	ghost_knight.clear();
	for (Node<Fl_Image*> *p = ghost_knight_captain.begin(); p; p = p->getNext())
		delete p->getValue();
	ghost_knight_captain.clear();

	for (Node<Fl_Image*> *p = green_ghost.begin(); p; p = p->getNext())
		delete p->getValue();
	green_ghost.clear();

	for (Node<Fl_Image*> *p = red_lord.begin(); p; p = p->getNext())
		delete p->getValue();
	red_lord.clear();
	for (Node<Fl_Image*> *p = ghost_lord.begin(); p; p = p->getNext())
		delete p->getValue();
	ghost_lord.clear();
	for (Node<Fl_Image*> *p = dragon.begin(); p; p = p->getNext())
		delete p->getValue();
	dragon.clear();

	// NPC
	for (Node<Fl_Image*> *p = fairy.begin(); p; p = p->getNext())
		delete p->getValue();
	fairy.clear();
	for (Node<Fl_Image*> *p = princess.begin(); p; p = p->getNext())
		delete p->getValue();
	princess.clear();
	for (Node<Fl_Image*> *p = old_man.begin(); p; p = p->getNext())
		delete p->getValue();
	old_man.clear();
	for (Node<Fl_Image*> *p = stone.begin(); p; p = p->getNext())
		delete p->getValue();
	stone.clear();
	for (Node<Fl_Image*> *p = merchant.begin(); p; p = p->getNext())
		delete p->getValue();
	merchant.clear();

	// hero
	for (Node<Fl_Image*> *p = HeroPhotos.begin(); p; p = p->getNext())
		delete p->getValue();
	HeroPhotos.clear();
	delete Fighting;

	// maps
	// new maps
	for (Node<Map*> *p = New_Maps.begin(); p; p = p->getNext())
		delete p->getValue();
	New_Maps.clear();
	// saved maps
	for (Node<Map*> *p = Saved_Maps.begin(); p; p = p->getNext())
		delete p->getValue();
	Saved_Maps.clear();
}

void ResourceManager::playBGM(int index)
{
	static bool isPlaying = false;
	static int playNum = 0;
	
	// change the playing state
	if (index == STOP_MUSIC)
		isPlaying = false;
	else if (index == START_MUSIC)
	{
		isPlaying = true;
		PlaySound(bgm[playNum].data(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}

	// find which music to play by index
	int wantPlay;
	if (game->getState() == Game::MAIN_MENU)
		wantPlay = 0;
	else if (index < 17)
		wantPlay = 1;
	else if (index < 24)
		wantPlay = 2;
	else
		wantPlay = 3;
	
	// update the playing music
	if (!isPlaying)
	{
		// change the play music number
		playNum = -1;
		// stop the background music
		PlaySound(NULL, NULL, NULL);
	}
	else if (playNum != wantPlay)
	{
		// change the play music number
		playNum = wantPlay;
		// play the background music
		PlaySound(bgm[wantPlay].data(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
	
}


