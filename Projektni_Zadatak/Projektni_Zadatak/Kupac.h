#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename X>
class Kupac
{
private:
	X ime;
	X prezime;
	X adresa;
public:
	Kupac(X& ime, X& prezime, X& adresa);
	void IspisiPodatkeKupca();
};

template<typename X>
Kupac<X>::Kupac(X& ime, X& prezime, X& adresa)
{
	this->ime = ime;
	this->prezime = prezime;
	this->adresa = adresa;
}

template<typename X>
void Kupac<X>::IspisiPodatkeKupca()
{
	cout << "Podaci kupca: " << endl;
	cout << "***********************" << endl;
	cout << "Ime: " << ime << endl;
	cout << "Prezime: " << prezime << endl;
	cout << "Adresa: " << adresa << endl;
}
