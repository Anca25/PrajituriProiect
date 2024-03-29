#include <iostream>
#include <string>
#include "Cake.h"
#include "RecipeCake.h"
#include "CakeMaker.h"
#include "CarouselOfCakes.h"
#include "CommandTaker.h"
#include "CommandPanel.h"
#include <array>
#include <Windows.h>
#include "Decoration.h"

using namespace std;

int main()
{
	CarouselOfCakes carousel = CarouselOfCakes();
	CommandTaker cmdTaker = CommandTaker(&carousel);
	CommandPanel cmdPannel = CommandPanel(&cmdTaker, &carousel);
	
	int opt;
	while (1)
	{
		
		cout << "\n1.Afisati produsele:\n";
		cout << "\n2.Comanda o prajitura:\n";
		cout << "\n3.Comanda mai multe prajituri:\n";
		cout << "\n4.Produse disponibile:\n";
		cout << "\n5.Iesire:\n";
		cout << "\nOptiunea dvs: ";
		cin >> opt;
		switch (opt)
		{
		case 1:
		{
			cmdPannel.showProducts();
			getchar(); getchar();
			system("CLS");
			break;
		}
		case 2:
		{
			cmdPannel.showProducts();
			string numeCake;
			cout << "\nCe prajitura doriti?\n";
			cin >> numeCake;
			cout << "\nSe pregateste prajitura!\n"<<numeCake<<endl;
			cmdPannel.selectProduct(numeCake);
			cout << "\nVa rugam asteptati!Se va afisa meniul principal!\n";
			Sleep(1000);
			system("CLS");
			break;
		}
		case 3:
		{
			cmdPannel.showProducts();
			cout << "\nCe prajitura doriti?\n";
			string numeCake;
			cin >> numeCake;
			int cate;
			try {
				cout << "Cate bucati ";
				cin >> cate;
				if (cate < 1 ) {
					throw NegativeNumberException();
				}
			}
			catch (NegativeNumberException e) {
				cout << "Ati comandat prea putine prajituri";
			}
			cmdPannel.selectProduct(numeCake, cate);
			cout << "\nVa rugam asteptati!Se va afisa meniul principal!\n";
			Sleep(1000);
			system("CLS");
			break;
		}
		case 4:
		{
			cout << "\nPrajiturile disponbile pe carusel sunt:\n";
			cmdPannel.showProductsInCarousel();
			getchar(); getchar();
			system("CLS");
			break;
		}	
		case 5:
			exit(0);
		default:
			cout << "\nOptiune gresita!\n";
			break;
		}
	}

	//Cake ck1 = Cake("prj1");
	//Cake ck2 = Cake("prj2");
	//Cake ck3 = Cake("prj3");
	//Cake ck4 = Cake("prj4");
	
	//CakeMaker ckmk1 = CakeMaker();
	//ckmk1.takeCommand(rck1);
	
	/*
	CarouselOfCakes cck1 = CarouselOfCakes();
	if (cck1.addCake(ck1)) {
		cout << "Adaugat " << ck1.getName() << endl;
	}
	if (cck1.addCake(ck2)) {
		cout << "Adaugat " << ck2.getName() << endl;
	}
	if (cck1.addCake(ck3)) {
		cout << "Adaugat " << ck3.getName() << endl;
	}
	if (cck1.addCake(ck4)) {
		cout << "Adaugat " << ck4.getName() << endl;
	}

	cck1.printCakes();

	Cake* testCake = cck1.getCake("prj432533");
	if (testCake) {
		cout << "Am gasit " << testCake->getName() << endl;
	}
	else {
		cout << "Nu e acolo";
	}
	*/
	
	/*
	CarouselOfCakes carousel = CarouselOfCakes();
	CommandTaker ctk1 = CommandTaker(&carousel);

	RecipeCake rck1 = RecipeCake("prajitura1", 5);
	RecipeCake rck2 = RecipeCake("prajitura2", 5);
	RecipeCake rckMulte = RecipeCake("comanda mare", 5);

	carousel.addCake(Cake(rck1.getName()));
	
	carousel.printCakes();

	ctk1.takeCommand(rck1);
	ctk1.takeCommand(rck2);

	int n = 5;
	array<Cake, 100>v = ctk1.takeCommand(rckMulte, n);
	for (int i = 0; i < n; i++) {
		cout << "Gasit prajitura facuta la gramada "<<v[i].getName()<<endl;
	}

	Cake* cakesFromStorage = ctk1.getCakesFromCarousel();

	ctk1.refilCarousel();
	*/

	
	

	//carousel.addCake(Cake("pr1"));
	//carousel.addCake(Cake("pr2"));
	//carousel.addCake(Cake("pr3"));


	//char nume[100];
	//cout << "Numele produsluoi este ";
	//cin.get(nume,100);
	//string numeDorit = nume;
	

	

	return 0;
}