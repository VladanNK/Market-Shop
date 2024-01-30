#pragma once
#include <iostream>
#include <vector>
#include "Proizvod.h"
using namespace std;

class Racun
{
private:
	vector<Proizvod> kupljeni_proizvodi;
	double ukupna_cena;
public:
	Racun(const vector<Proizvod>& proizvodi, double Ukupna_Cena);
	void Prikazi_Racun() const;
	double GetUkupnaCena() const;
};

