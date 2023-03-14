#include "tradeButton.h"
#include "../../../resourceManager/resourceManager.h"
#include "../../../dataManager/dataManager.h"

TradeButton::TradeButton(
	Currency currency, Goods goods,
	int cost, int gain, Fl_Callback callback):
	Fl_Button(100, 100, 100, 100),
	currency(currency), goods(goods),
	cost(cost), gain(gain)
{
	// set style
	this->box(FL_FLAT_BOX);
	this->color(ResourceManager::GREEN);
	this->clear_visible_focus();
	// font
	this->labelfont(ResourceManager::HeiTi);
	this->labelcolor(FL_WHITE);
	this->labelsize(TEXTSIZE);
	// set callback and when the button is clicked, callback will do
	this->callback(callback);
	// set the label of the button
	this->copy_label(getText().data());
}

TradeButton::~TradeButton()
{

}

string TradeButton::getText()
{
	// get the text of currency
	string currencyText;
	if (currency == MONEY)
		currencyText = "个金币";
	else if (currency == EXP)
		currencyText = "点经验";
	else if (currency == RED)
		currencyText = "把红色钥匙";
	else if (currency == BLUE)
		currencyText = "把蓝色钥匙";
	else if (currency == YELLOW)
		currencyText = "把黄色钥匙";


	// get the text of goods
	string goodsText;
	if (goods == HEALTH)
		goodsText = "点生命值";
	else if (goods == ATTACK)
		goodsText = "点攻击力";
	else if (goods == DEFENCE)
		goodsText = "点防御值";
	else if (goods == LEVEL)
		goodsText = "个等级";
	else if (goods == REDKEY)
		goodsText = "把红色钥匙";
	else if (goods == BLUEKEY)
		goodsText = "把蓝色钥匙";
	else if (goods == YELLOWKEY)
		goodsText = "把黄色钥匙";
	else if (goods == COIN)
		goodsText = "个金币";

	// get the text of button
	string text = 
		"花费" + to_string(cost) + currencyText +
		", 获得" + to_string(gain) + goodsText;
	return text;
}

TradeButton::Currency TradeButton::getCurrency()
{
	return currency;
}

TradeButton::Goods TradeButton::getGoods()
{
	return goods;
}

int TradeButton::getCostAmount()
{
	return cost;
}

int TradeButton::getGainAmount()
{
	return gain;
}