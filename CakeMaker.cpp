#include "CakeMaker.h"
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

CakeMaker::CakeMaker() {

};

Cake CakeMaker::takeCommand(RecipeCake recipe)
{
	string s = recipe.getName();
	Cake cake = Cake(s);
	cout << endl << "Se pregateste prajitura " << s << endl;
	Sleep(5000);
	cout << "Prajitura "<<s<<" este gata!" <<"\n";
	return cake;
}