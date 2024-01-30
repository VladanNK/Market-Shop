#include "Korpa.h"
#include "Proizvod.h"
#include "Prodavnica.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int Korpa::ukupan_broj_proizvoda = 0;
void Korpa::dodaj_proizvod(const Proizvod& proizvod)
{
	proizvodi.push_back(proizvod);
	ukupan_broj_proizvoda++;
}
void Korpa::ukloni_proizvod(string& NazivProizvoda)
{
	auto trazeni = find_if(proizvodi.begin(), proizvodi.end(), [&](const Proizvod& proizvodi) {
		return proizvodi.GetNazivProizvoda() == NazivProizvoda;
		});
	if (trazeni != proizvodi.end()) {
		proizvodi.erase(trazeni);
		cout << "Proizvod " << NazivProizvoda << " je uklonjen iz korpe." << endl;
		ukupan_broj_proizvoda--;
	}
	else {
		cout << "Proizvod " << NazivProizvoda << " nije pronadjen u korpi." << endl;
	}
}

double Korpa::operator+()
{
	double ukupna_cena = 0.0;

	for (const auto& proizvod : proizvodi) {
		ukupna_cena += proizvod.GetCenaProizvoda();
	}
	return ukupna_cena;
}

vector<Proizvod> Korpa::GetProizvodi() const
{
	return proizvodi;
}

int Korpa::GetUkupanBrojProizvoda()
{
	return ukupan_broj_proizvoda;
}

void Korpa::Sortiraj_Proizvode_Po_Ceni(bool opadajuce)
{
	if (opadajuce) {
		sort(proizvodi.begin(), proizvodi.end(), [](const Proizvod& proizvod1, const Proizvod& proizvod2) {
			return proizvod1.GetCenaProizvoda() > proizvod2.GetCenaProizvoda();
			});
	}
	else {
		sort(proizvodi.begin(), proizvodi.end(), [](const Proizvod& proizvod1, const Proizvod& proizvod2) {
			return proizvod1.GetCenaProizvoda() < proizvod2.GetCenaProizvoda();
			});
	}
}
