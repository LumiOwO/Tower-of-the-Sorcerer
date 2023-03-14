#include "barrier.h"

Barrier::Barrier(ID id, Type type, bool canPass):
	Cell(id, type), canPass(canPass)
{

}

Barrier::~Barrier()
{

}

bool Barrier::canPassIt()
{
	return canPass;
}

void Barrier::tryToOpen(int& redKeys, int& blueKeys, int& yellowKeys)
{
	// auto door will open automatically
	if (getCellID() == ID::AUTO_DOOR)
		canPass = true;
	// consume one red key to open the red door
	else if (getCellID() == ID::RED_DOOR && redKeys > 0)
	{
		redKeys--;
		canPass = true;
	}
	// consume one blue key to open the blue door
	else if (getCellID() == ID::BLUE_DOOR && blueKeys > 0)
	{
		blueKeys--;
		canPass = true;
	}
	// consume one yellow key to open the yellow door
	else if (getCellID() == ID::YELLOW_DOOR && yellowKeys > 0)
	{
		yellowKeys--;
		canPass = true;
	}
}

