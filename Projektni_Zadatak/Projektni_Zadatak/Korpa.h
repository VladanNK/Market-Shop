#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Proizvod.h"
#include "Prodavnica.h"
using namespace std;

class Korpa
{
private:
	vector<Proizvod> proizvodi;
	static int ukupan_broj_proizvoda;
public:
	void dodaj_proizvod(const Proizvod& proizvod);
	void ukloni_proizvod(string& NazivProizvoda);
	double operator+();
	vector<Proizvod> GetProizvodi() const;
	static int GetUkupanBrojProizvoda();
	void Sortiraj_Proizvode_Po_Ceni(bool opadajuce);
	void ispisi_racun_u_fajl() const {
		ofstream file("racun.txt");
		if (!file.is_open()) {
			cerr << "Greska pri otvaranju datoteke za pisanje" << endl;
			return;
		}
		file << "RACUN: " << endl;
		file << "------------------------------------" << endl << endl;
		double Ukupna_Cena = 0.0;
		for (const Proizvod& proizvod : proizvodi) {
			file << proizvod.GetNazivProizvoda() << " - " << proizvod.GetCenaProizvoda() << endl;
			Ukupna_Cena += proizvod.GetCenaProizvoda();
		}
		file << "------------------------------------" << endl;
		file << "UKUPNO: " << Ukupna_Cena << " din." << endl;

		file.close();
	}
};