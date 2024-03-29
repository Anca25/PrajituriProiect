#pragma once
#include <iostream>
#include <string>
#include "Exception.cpp"

using namespace std;
typedef enum {
	bomboane_martipan, bomboane_ciocolata_neagra, bomboane_ciocolata_alba
}Tip_Decoratiune;
string DecoractiuneToString(Tip_Decoratiune t);
Tip_Decoratiune StringToDecoratiune(string s);
class Decoration
{
	Tip_Decoratiune tip;
	int nr_bucati;
	double pret;
public:
	Decoration();
	Decoration(Tip_Decoratiune tip, int nr_bucati, double pret)throw(NegativeNumberException);
	Tip_Decoratiune getTip();
	int getNrBucati();
	double getPret();
	friend istream& operator>>(istream& in, Decoration &d)throw(NegativeNumberException);
	friend ostream& operator<<(ostream& out, Decoration d);
	Decoration citire_decoratiune();
};

