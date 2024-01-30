#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Racun.h"
using namespace std;
class Kasa : public Racun
{
private:
	string datum_i_vreme;
public:
	Kasa(const vector<Proizvod>& proizvodi, double Ukupna_cena);
	void Prikazi_Racun() const;
};

