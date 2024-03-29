#include "CommandPanel.h"
#include <array>
#include <fstream>

using namespace std;

CommandPanel::CommandPanel(){
		
};

CommandPanel::CommandPanel(CommandTaker* cmdTaker, CarouselOfCakes* carousel) {		
	ctk = cmdTaker;
	ifstream f("reteta.txt");
	if (!f) {
		cout << "Nu am reusit sa deschid fisierul ";
		return;
	}
	string name;
	int time;
	int onCarousel;

	while (f >> name >> time>>onCarousel)
	{
		RecipeCake recipe = RecipeCake(name, time);
		if (onCarousel) {
			carousel->addCake(Cake(name));
		}
		menu.push_back(recipe);
	}
	ctk->refilCarousel();	
	f.close();
};

void CommandPanel::showProducts() {
	cout << "Puteti alege dintre cele de mai jos:" << endl;
	for (list<RecipeCake>::iterator it=menu.begin(); it!=menu.end(); ++it){
		cout << it->getName()<<endl;
	}
};

void CommandPanel::selectProduct(string name) {
	int gasit = 0;
	for (list<RecipeCake>::iterator it = menu.begin(); it != menu.end(); ++it) {
		if (name == it->getName()) {
			RecipeCake  rc = RecipeCake(it->getName(), it->getTime());
			ctk->takeCommand(rc);
			gasit = 1;
		}
	}
	if (!gasit) {
		cout << "Numele respectiv nu se gaseste in lista" << endl;
	}
}

void CommandPanel::selectProduct(string name, int no) {
	cout << "Caut dupa " << name << endl;
	int gasit = 0;
	for (list<RecipeCake>::iterator it = menu.begin(); it != menu.end(); ++it) {
		if (name == it->getName()) {
			RecipeCake  rc = RecipeCake(it->getName(), it->getTime());
			ctk->takeCommand(rc, no);	//returneaza un array cu prajiturile facute
			gasit = 1;
		}
	}
	if (!gasit) {
		cout << "Numele respectiv nu se gaseste in lista" << endl;
	}
}

void CommandPanel::showProductsInCarousel() {
	Cake* cakes = ctk->getCakesFromCarousel();
	for (int i = 0; i < ctk->getCarouselLoading(); i++) {
		cout << i << " : " << cakes[i].getName()<<endl;
	}
}