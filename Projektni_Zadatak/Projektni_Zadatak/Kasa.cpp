#include "Kasa.h"
#include "Racun.h"
#include "Korpa.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

Kasa::Kasa(const vector<Proizvod>& proizvodi, double Ukupna_cena): Racun(proizvodi, Ukupna_cena)
{
}

void Kasa::Prikazi_Racun() const
{
	cout << "******************************************" << endl;
	cout << "Ukupna cena: " << GetUkupnaCena() << " RSD." << endl;
	cout << "Datum i vreme: " << __DATE__ << " " << __TIME__ << endl;
	cout << "Hvala na poseti." << endl;
	cout << "******************************************" << endl;
}
