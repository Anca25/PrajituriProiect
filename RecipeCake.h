#pragma once
#include <iostream>
#include <string>
#include "Cake.h"

using namespace std;

class RecipeCake
{
	string name;
	int time;
public:
	RecipeCake(string name, int time);
	RecipeCake();
	string getName();
	int getTime();
};

