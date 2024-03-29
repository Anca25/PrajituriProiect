#pragma once
#include "CakeMaker.h"
#include "Cake.h"
#define MAX_CAPACITY 12
class CarouselOfCakes{


	Cake storage[MAX_CAPACITY];
	 int maxCapacity = 12, lowLimit = 3;
	unsigned currentLoading = 0;  

public:
	CarouselOfCakes();
	bool addCake(Cake cake);
	Cake* getCake(string name);
	int getCurrentCapacity();
	void printCakes();
	Cake* getCakeStorage();
	int getMinLoading();
	int getMaxCapacity();
};

