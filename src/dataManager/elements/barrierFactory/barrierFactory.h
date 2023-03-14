#ifndef _BARRIERFACTORY_H_
#define _BARRIERFACTORY_H_

#include "../barrier/barrier.h"

// static class
class BarrierFactory
{
private:
	// make a private constructor 
	// to forbid others to create instance
	BarrierFactory() {}
public:
	// barriers
	static Barrier* getground(int x, int y);
	static Barrier* getbrick_wall(int x, int y);
	static Barrier* getstar(int x, int y);
	static Barrier* getlava(int x, int y);

	static Barrier* getstone_left(int x, int y);
	static Barrier* getstone_right(int x, int y);

	static Barrier* getdragon_nw(int x, int y);
	static Barrier* getdragon_n(int x, int y);
	static Barrier* getdragon_ne(int x, int y);
	static Barrier* getdragon_w(int x, int y);
	static Barrier* getdragon_m(int x, int y);
	static Barrier* getdragon_e(int x, int y);
	static Barrier* getdragon_sw(int x, int y);
	static Barrier* getdragon_se(int x, int y);

	// doors
	static Door* getauto_door(int x, int y);
	static Door* getred_door(int x, int y);
	static Door* getblue_door(int x, int y);
	static Door* getyellow_door(int x, int y);
};

#endif
