#include "scene.h"
#include "../../../resourceManager/resourceManager.h"

Scene::Scene():
	Fl_Group(SCENE_X, SCENE_Y, SCENE_WIDTH, SCENE_HEIGHT)
{
	// init map
	// compute pixel width of a cell
	int matrixWidth = Map::getMatrixWidth();
	cell_width = SCENE_WIDTH / matrixWidth;
	cell_height = SCENE_HEIGHT / matrixWidth;
	// set scene style
	this->box(FL_NO_BOX);
	// begin to add empty cells
	this->begin();
	for (int i = 0; i < matrixWidth; i++)
		for (int j = 0; j < matrixWidth; j++)
		{
			Fl_Box *box = new Fl_Box(
				SCENE_X + i * cell_width,
				SCENE_Y + j * cell_height,
				cell_width,
				cell_height
			);
			box->box(FL_NO_BOX);
			this->add(box);
		}
	// init hero box
	heroBox = new Fl_Box(SCENE_X, SCENE_Y, cell_width, cell_height);
	// set the background transparent
	heroBox->box(FL_NO_BOX);
	this->add(heroBox);

	// finish adding widgets
	this->end();

	// when first create, it should not be shown
	this->hide();
}

Scene::~Scene()
{
	this->clear();
}

void Scene::drawCell(Cell *cell)
{
	// find the cell
	int x = cell->getCurrentX();
	int y = cell->getCurrentY();
	Fl_Box *box = (Fl_Box*)this->child(x*Map::getMatrixWidth() + y);
	// change the image
	box->image(cell->getPhoto());
	// redraw the cell
	box->redraw();
}

void Scene::drawHero(Hero *hero)
{
	// redraw the cell on the previous and current position of hero
	// in order to cover the invalid image
	// previous position
	int x = hero->getPreviousX();
	int y = hero->getPreviousY();
	Fl_Box *box = (Fl_Box*)this->child(x*Map::getMatrixWidth() + y);
	box->redraw();
	// current position
	x = hero->getCurrentX();
	y = hero->getCurrentY();
	box = (Fl_Box*)this->child(x*Map::getMatrixWidth() + y);
	box->redraw();

	// change the image
	heroBox->image(hero->getPhoto());
	// change the photo of the hero
	heroBox->position(
		SCENE_X + x * cell_width,
		SCENE_Y + y * cell_height
	);
	// redraw the hero
	heroBox->redraw();
	// if the hero is fighting, draw the fighting photo
	if (hero->getFightState() == Hero::FIGHTING)
	{
		heroBox->image(ResourceManager::Fighting);
		heroBox->redraw();
	}
}