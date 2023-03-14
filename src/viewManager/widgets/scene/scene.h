#ifndef _SCENE_H_
#define _SCENE_H_

#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>

#include "../../../dataManager/elements/elements.h"

#define SCENE_X			212
#define SCENE_Y			25
#define SCENE_WIDTH		836
#define SCENE_HEIGHT	671

class Scene: public Fl_Group
{
private:
	int cell_width;
	int cell_height;
	Fl_Box *heroBox;
public:
	// constructor and destructor
	Scene();
	~Scene();

	// draw a certain cell
	void drawCell(Cell *cell);
	// draw hero box
	void drawHero(Hero *hero);
};
#endif