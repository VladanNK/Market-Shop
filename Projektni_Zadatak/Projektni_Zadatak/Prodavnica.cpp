#include "Prodavnica.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>
using namespace std;

Prodavnica::Prodavnica(const string& naziv, const string& adresa): naziv(naziv), adresa(adresa)
{
}

string Prodavnica::GetNaziv() const
{
	return naziv;
}

string Prodavnica::GetAdresa() const
{
	return adresa;
}

void Prodavnica::Dodaj_Proizvod(const Proizvod& proizvod)
{
	proizvodi.push_back(proizvod);
}

void Prodavnica::Prikazi_Proizvode() const
{
	cout << "Proizvodi u prodavnici" << endl << endl;
	for (const auto& proizvod : proizvodi) {
		cout << proizvod.GetNazivProizvoda() << " - " << proizvod.GetCenaProizvoda() << " RSD." << endl;
	}
	cout << "-----------------------------------------------" << endl;
}

void Prodavnica::Prikaz()
{
	cout << setw(15) << "Dobrodosli u " << naziv << endl;
	cout << setw(15) << "Na adresi: " << adresa << endl;
	cout << "******************************************" << endl << endl;
}

vector<Proizvod> Prodavnica::PretraziProizvode(const string& naziv) const
{
	vector<Proizvod> rezultat;
	for (const auto& proizvod : proizvodi) {
		if (proizvod.GetNazivProizvoda() == naziv) {
			rezultat.push_back(proizvod);
		}
	}
	return rezultat;
}

vector<Proizvod> Prodavnica::GetProizvodi() const
{
	return proizvodi;
}
