#include "CommandTaker.h"
#include <iostream>
#include <string>
#include <array>
using namespace std;

CommandTaker::CommandTaker() {
	
};

CommandTaker::CommandTaker(CarouselOfCakes* c) {
	carousel = c;
};


int CommandTaker::getCarouselLoading() {
	return carousel->getCurrentCapacity();
}


Cake CommandTaker::takeCommand(RecipeCake r) {
	Cake* theCake = (*carousel).getCake(r.getName());
	if (theCake) {
		cout << "Am gasit pe carusel" << r.getName() << endl;
		refilCarousel();	//dupa fiecare comanda incercam sa il reumplem (daca e nevoie)
		return *theCake;
	}
	else {
		cout << "nu e pe carusel. trebuie sa fabric " << r.getName() << endl;
		return cakeMaker.takeCommand(r);
	}
	
}

array<Cake, 100> CommandTaker::takeCommand(RecipeCake r, int noOfCakes) {
	array<Cake, 100> v;
	for (int i = 1; i <= noOfCakes; i++) {
		v[i] = takeCommand(r);
	}  
	return v;
}

Cake* CommandTaker::getCakesFromCarousel() {
	return carousel->getCakeStorage();
}

void CommandTaker::refilCarousel() {
	if (carousel->getCurrentCapacity() < carousel->getMinLoading()){
		while (carousel->getCurrentCapacity() != carousel->getMaxCapacity()) {
			carousel->addCake(Cake("Prajitura fara nume"));
		}

	}
}