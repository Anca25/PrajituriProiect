#pragma once
#include <iostream>
#include <string>
#include "RecipeCake.h"
#include "CakeMaker.h"
#include "CarouselOfCakes.h"

using namespace std;

class CommandTaker
{
	RecipeCake cakeReceipe;
	CakeMaker cakeMaker;
	CarouselOfCakes* carousel;

public:
	CommandTaker();
	CommandTaker(CarouselOfCakes* carousel);
	Cake takeCommand(RecipeCake r);
	array<Cake, 100>takeCommand(RecipeCake r, int noOfCakes); 
	Cake* getCakesFromCarousel();
	int getCarouselLoading();
	void refilCarousel();
};