#include "Racun.h"
#include <iostream>
#include <vector>
using namespace std;

Racun::Racun(const vector<Proizvod>& proizvodi, double Ukupna_Cena): kupljeni_proizvodi(proizvodi), ukupna_cena(Ukupna_Cena)
{}

void Racun::Prikazi_Racun() const
{
	for (const auto& proizvod : kupljeni_proizvodi) {
		cout << proizvod.GetNazivProizvoda() << " - " << proizvod.GetCenaProizvoda() << endl;
	}
	cout << "Ukupna cena iznosi: " << ukupna_cena << " RSD." << endl;
}

double Racun::GetUkupnaCena() const
{
	return ukupna_cena;
}