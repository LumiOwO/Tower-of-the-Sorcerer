#ifndef _TRADEBUTTON_H_
#define _TRADEBUTTON_H_

#include <FL/Fl_Button.H>
#include <string>
using namespace std;

class TradeButton: public Fl_Button
{
public:
	enum Currency {
		MONEY, EXP,
		RED, BLUE, YELLOW
	};
	enum Goods {
		HEALTH, ATTACK, DEFENCE, LEVEL,
		REDKEY, BLUEKEY, YELLOWKEY,
		COIN
	};
private:
	// store the type of trade item
	Currency currency;
	Goods goods;
	// the amount of cost in a trade
	int cost;
	// the amount of gain in a trade
	int gain;
public:
	TradeButton(
		Currency currency,
		Goods goods,
		int cost, int gain,
		Fl_Callback callback
	);
	~TradeButton();

	// get the text of button
	string getText();
	// get the currency
	Currency getCurrency();
	// get the goods
	Goods getGoods();
	// get the amount of cost in a trade
	int getCostAmount();
	// get the amount of gain in a trade
	int getGainAmount();
};

#endif
