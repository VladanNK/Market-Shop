#include "Proizvod.h"
#include <iostream>
using namespace std;

Proizvod::Proizvod(const string& naziv, double cena)
{
	this->naziv_proizvoda = naziv;
	this->cena_proizvoda = cena;
}

string Proizvod::GetNazivProizvoda() const
{
	return naziv_proizvoda;
}

double Proizvod::GetCenaProizvoda() const
{
	return cena_proizvoda;
}