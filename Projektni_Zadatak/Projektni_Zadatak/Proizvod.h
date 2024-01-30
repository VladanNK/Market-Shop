#pragma once
#include <iostream>
#include <string>
using namespace std;

class Proizvod
{
private:
	string naziv_proizvoda;
	double cena_proizvoda;
public:
	Proizvod(const string& naziv, double cena);
	string GetNazivProizvoda() const;
	double GetCenaProizvoda() const;
};

