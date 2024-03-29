#include <iostream>
#include <string>
#include "Decoration.h"

using namespace std;
string DecoractiuneToString(Tip_Decoratiune t)
{
	switch (t)
	{
	case bomboane_martipan:
		return string("bomboane_martipan");
	case bomboane_ciocolata_neagra:
		return string("bomboane_ciocolata_neagra");
	case bomboane_ciocolata_alba:
		return string("bomboane_ciocolata_alba");
	}
}
Tip_Decoratiune StringToDecoratiune(string s)
{
	if (s == "bomboane_martipan")
		return bomboane_martipan;
	else if (s == "bomboane_ciocolata_neagra")
		return bomboane_ciocolata_neagra;
	else if (s == "bomboane_ciocolata_alba")
		return bomboane_ciocolata_alba;
}
Decoration::Decoration() {};
Decoration::Decoration(Tip_Decoratiune tip, int nr_bucati, double pret)throw(NegativeNumberException)
{
	this->tip = tip;
	this->nr_bucati = nr_bucati;
	if (pret < 0)
	{
		NegativeNumberException e;
		throw e;
		this->pret = 10;
		return;
	}
	this->pret = pret;
}
Tip_Decoratiune Decoration::getTip()
{
	return this->tip;
}
int Decoration::getNrBucati()
{
	return this->nr_bucati;
}
double Decoration::getPret()
{
	return this->pret;
}
istream& operator>>(istream& in, Decoration &d)
{
	cout << "\nDati tipul de decoratiune:\n";
	string tt;
	in >> tt;
	d.tip = StringToDecoratiune(tt);
	cout << "\nDati nr de bucati pt decoratiunea selectata!\n";
	in >> d.nr_bucati;
	cout << "\nDati pretul:\n";
	int pr;
	in >> pr;
	if (pr < 0)
	{
		NegativeNumberException e;
		throw e;
		d.pret = 10;
		return in;
	}
	else
		d.pret = pr;
	return in;
}
ostream& operator<<(ostream& out, Decoration d)
{
	out<<"\nTipul decoratiunii este:\n"<< DecoractiuneToString(d.tip);
	out << "\nNr de bucati pt decoratiune este:\n" << d.nr_bucati;
	out << "\nPretul decoratiunii este:\n" << d.pret;
	return out;
}
Decoration citire_decoratiune()
{
	Decoration* d = new Decoration;
eticheta1:
	try {
		cin >> *d;
	}
	catch (NegativeNumberException e) {
		cout << e.what();
		goto eticheta1;
	}
	return *d;
}