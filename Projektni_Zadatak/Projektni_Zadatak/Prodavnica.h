#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "Proizvod.h"
using namespace std;

class Prodavnica
{
private:
	string naziv;
	string adresa;
	vector<Proizvod> proizvodi;
public:
	Prodavnica(const string& naziv, const string& adresa);
	string GetNaziv() const;
	string GetAdresa() const;
	void Dodaj_Proizvod(const Proizvod& proizvod);
	void Prikazi_Proizvode() const;
	void Prikaz();
	vector<Proizvod> PretraziProizvode(const string& naziv) const;
	vector<Proizvod> GetProizvodi() const;
	void ispisi_ponudjene_proizvode() const {
		ofstream file("svi_proizvodi.txt");
		if (!file.is_open()) {
			cerr << "Greska pri otvaranju datoteke" << endl;
			return;
		}
		file << "Svi ponudjeni proizvodi:" << endl << endl;
		file << "*****************************************" << endl;
		for (const Proizvod& proizvod : proizvodi) {
			file << proizvod.GetNazivProizvoda() << " - " << proizvod.GetCenaProizvoda() << endl;
		}
		file << "*****************************************" << endl << endl;
		file.close();
	}
};

