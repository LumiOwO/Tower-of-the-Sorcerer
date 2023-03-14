#ifndef _BARRIER_H_
#define _BARRIER_H_

#include "../cell/cell.h"

class Barrier: public Cell
{
private:
	bool canPass;
public:
	// constructor and destructor
	Barrier(ID id, Type type, bool canPass);
	~Barrier();
	// getters
	bool canPassIt();
	// if it's a door, try to open the door
	void tryToOpen(int& redKeys, int& blueKeys, int& yellowKeys);
};

// rename for the door
typedef Barrier Door;

#endif