#pragma once
#include <iostream>
#include <string>
#include "RecipeCake.h"

using namespace std;

class CakeMaker
{
public:
	CakeMaker();
	Cake takeCommand(RecipeCake recipe);
};

