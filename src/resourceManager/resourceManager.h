#ifndef _RESOURCEMANAGER_H_
#define _RESOURCEMANAGER_H_

#include <FL/Fl.H>
#include <iostream>
using namespace std;

#include "../linkedlist/linkedlist.h"

#define TOTAL_MAPS		25

#define STOP_MUSIC		-2
#define START_MUSIC		-1

// we need the name of the music to play it
typedef string Music;

// declare class
class Map;
class Game;

// static class
class ResourceManager
{
public:
	// register the running game
	static void registerGame(Game *game);
	// load resources when the game start
	static void loadResources();
	// free resources when the game quit
	static void freeResources();
	// play the background music
	static void playBGM(int index = 0);

	// game
	static Game *game;

	// text
	static string helpText;

	// colors
	static Fl_Color BackgroundColor;
	static Fl_Color HelpPanelColor;
	static Fl_Color GREEN;

	// fonts
	static Fl_Font HeiTi;

	// bgm
	static LinkedList<Music> bgm;
	
	// images
	// icons
	static Fl_Image *WindowIcon;

	static Fl_Image *MusicOn;
	static Fl_Image *MusicOff;
	static Fl_Image *SaveGame;
	static Fl_Image *HomePage;
	static Fl_Image *Help;
	static Fl_Image *Transport;
	static Fl_Image *Book;
	// ui
	static Fl_Image *MainMenu;
	static Fl_Image *WinUI;

	// barrier
	static Fl_Image* ground;
	static Fl_Image* brick_wall;
	static LinkedList<Fl_Image*> star;
	static LinkedList<Fl_Image*> lava;

	static LinkedList<Fl_Image*> stone_left;
	static LinkedList<Fl_Image*> stone_right;

	static LinkedList<Fl_Image*> dragon_nw;
	static LinkedList<Fl_Image*> dragon_n;
	static LinkedList<Fl_Image*> dragon_ne;
	static LinkedList<Fl_Image*> dragon_w;
	static LinkedList<Fl_Image*> dragon_m;
	static LinkedList<Fl_Image*> dragon_e;
	static LinkedList<Fl_Image*> dragon_sw;
	static LinkedList<Fl_Image*> dragon_se;

	// doors
	static LinkedList<Fl_Image*> auto_door;
	static LinkedList<Fl_Image*> red_door;
	static LinkedList<Fl_Image*> blue_door;
	static LinkedList<Fl_Image*> yellow_door;

	// items
	static Fl_Image* red_key;
	static Fl_Image* blue_key;
	static Fl_Image* yellow_key;
	static Fl_Image* super_key;

	static Fl_Image* RedKeyTrans;
	static Fl_Image* BlueKeyTrans;
	static Fl_Image* YellowKeyTrans;

	static Fl_Image* red_potion;
	static Fl_Image* blue_potion;
	static Fl_Image* super_potion;

	static Fl_Image* red_crystal;
	static Fl_Image* blue_crystal;

	static Fl_Image* sword_primary;
	static Fl_Image* sword_medium;
	static Fl_Image* sword_super;

	static Fl_Image* shield_primary;
	static Fl_Image* shield_medium;
	static Fl_Image* shield_super;

	static Fl_Image* coin;
	static Fl_Image* level_up;

	// special
	static Fl_Image* cross;
	static Fl_Image* fire_wand;
	static Fl_Image* ice_wand;
	static Fl_Image* earth_wand;

	// stairs
	static Fl_Image* upstairs;
	static Fl_Image* downstairs;

	// enemy
	static LinkedList<Fl_Image*> green_slime;
	static LinkedList<Fl_Image*> red_slime;
	static LinkedList<Fl_Image*> ghost_slime;
	static LinkedList<Fl_Image*> big_slime;

	static LinkedList<Fl_Image*> small_bat;
	static LinkedList<Fl_Image*> big_bat;
	static LinkedList<Fl_Image*> red_bat;

	static LinkedList<Fl_Image*> skeleton;
	static LinkedList<Fl_Image*> skeleton_warrior;
	static LinkedList<Fl_Image*> skeleton_captain;
	static LinkedList<Fl_Image*> skeleton_armored;

	static LinkedList<Fl_Image*> orc;
	static LinkedList<Fl_Image*> orc_warrior;

	static LinkedList<Fl_Image*> wizard;
	static LinkedList<Fl_Image*> red_wizard;

	static LinkedList<Fl_Image*> mage;
	static LinkedList<Fl_Image*> red_mage;

	static LinkedList<Fl_Image*> head_monster;

	static LinkedList<Fl_Image*> dual_blade;

	static LinkedList<Fl_Image*> golden_guard;
	static LinkedList<Fl_Image*> blue_guard;
	static LinkedList<Fl_Image*> red_guard;

	static LinkedList<Fl_Image*> red_knight;
	static LinkedList<Fl_Image*> yellow_knight;
	static LinkedList<Fl_Image*> blue_knight;
	static LinkedList<Fl_Image*> armored_knight;
	static LinkedList<Fl_Image*> ghost_knight;
	static LinkedList<Fl_Image*> ghost_knight_captain;

	static LinkedList<Fl_Image*> green_ghost;

	static LinkedList<Fl_Image*> red_lord;
	static LinkedList<Fl_Image*> ghost_lord;
	static LinkedList<Fl_Image*> dragon;

	// NPC
	static LinkedList<Fl_Image*> fairy;
	static LinkedList<Fl_Image*> princess;
	static LinkedList<Fl_Image*> old_man;
	static LinkedList<Fl_Image*> stone;
	static LinkedList<Fl_Image*> merchant;

	// hero
	static LinkedList<Fl_Image*> HeroPhotos;
	static Fl_Image *Fighting;

	// maps
	static LinkedList<Map*> New_Maps;
	static LinkedList<Map*> Saved_Maps;
};

#endif
