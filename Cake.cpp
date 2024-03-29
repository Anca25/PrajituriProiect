#include "Cake.h"
#include <iostream>
#include <string>

using namespace std;

Cake::Cake() {
	;
};

Cake::Cake(string name)
{
	this->name = name;
}
string Cake::getName()
{
	return this->name;
}