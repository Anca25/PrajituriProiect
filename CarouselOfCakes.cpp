#include "CarouselOfCakes.h"
#include "Cake.h"
#include <iostream>
#include <string>

using namespace std;

CarouselOfCakes::CarouselOfCakes() {};

int CarouselOfCakes::getMaxCapacity() {
	return maxCapacity;
}

int CarouselOfCakes::getCurrentCapacity() {
	return currentLoading;
}

int CarouselOfCakes::getMinLoading() {
	return lowLimit;
}

bool CarouselOfCakes::addCake(Cake cake) {
	if (currentLoading < MAX_CAPACITY) {
		storage[currentLoading] = cake;
		currentLoading++;
		cout << "Am bagat " << cake.getName() << endl;
		return true;
	}
	else {
		return false;
	}
}

void CarouselOfCakes::printCakes() {
	for (unsigned i = 0; i < currentLoading; i++) {
		cout << i<<" "<<storage[i].getName() << endl;
	}
}

Cake* CarouselOfCakes::getCake(string name) {
	for (unsigned i = 0; i < currentLoading; i++) {
		if (name==storage[i].getName()){
			for (int j = i; j < currentLoading - 1; j++) {
				storage[j] = storage[j + 1];
			}
			currentLoading--;
			return &storage[i];
		}
	}
	return nullptr;
}

Cake* CarouselOfCakes::getCakeStorage() {
	return storage;
}