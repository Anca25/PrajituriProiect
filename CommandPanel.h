#pragma once
#include <list>
#include <string>
#include "RecipeCake.h"
#include "CommandTaker.h"
class CommandPanel
{
	list<RecipeCake> menu;
	CommandTaker* ctk;
	//string products[5] ={ "Briosa","Ecler" ,"Savarina" ,"Amandina" ,"Dobos" };
	//int nProducts = sizeof(products) / sizeof(products[0]);
public:
	CommandPanel();
	CommandPanel(CommandTaker*, CarouselOfCakes*);
	void showProducts();
	void selectProduct(string name);
	void selectProduct(string name, int no);
	void showProductsInCarousel();

};

