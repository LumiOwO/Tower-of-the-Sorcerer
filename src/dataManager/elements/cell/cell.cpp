#include "cell.h"

Cell::Cell(ID id, Type type)
{
	this->id = id;
	this->type = type;
	this->index = 0;
	this->photos = photos;
	this->viewedAllPhotos = false;
}

Cell::~Cell()
{

}

void Cell::setPhoto(Fl_Image *photo)
{
	this->photos = LinkedList<Fl_Image*>({ photo });
}

void Cell::setPhotos(LinkedList<Fl_Image*> photos)
{
	this->photos = photos;
}

Fl_Image* Cell::getPhoto()
{
	return photos[index];
}

bool Cell::shownAllPhotos()
{
	return viewedAllPhotos;
}

Cell::ID Cell::getCellID()
{
	return id;
}

Cell::Type Cell::getCellType()
{
	return type;
}

void Cell::changePhoto()
{
	// show next photo
	index++;
	// if shown all photos, show the first photo
	if (index == photos.size())
	{
		viewedAllPhotos = true;
		index = 0;
	}
}

void Cell::setIndex(int index)
{
	this->index = index;
}

int Cell::getIndex()
{
	return index;
}

bool Cell::isFinalPhoto()
{
	return index == photos.size() - 1;
}

int Cell::getCurrentX()
{
	return currentX;
}

int Cell::getCurrentY()
{
	return currentY;
}

void Cell::setPosition(int x, int y)
{
	currentX = x;
	currentY = y;
}

void Cell::setPosition(Cell *cell)
{
	currentX = cell->getCurrentX();
	currentY = cell->getCurrentY();
}
