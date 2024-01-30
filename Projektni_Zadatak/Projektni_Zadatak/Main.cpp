#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <queue>
#include "Kasa.h"
#include "Korpa.h"
#include "Prodavnica.h"
#include "Proizvod.h"
#include "Racun.h"
#include "Kupac.h"
using namespace std;

int main()
{
    Prodavnica prodavnica("Market Shop", "Adresa 12b");
    prodavnica.Prikaz();
    string ime_kupca, prezime_kupca, adresa_kupca;

    queue<Kupac<string>> red_kupaca;
    Kupac<string> novi_kupac(ime_kupca, prezime_kupca, adresa_kupca);
    red_kupaca.push(novi_kupac);
    Kupac<string> trenutni_kupac = red_kupaca.front();
    red_kupaca.pop();

    bool ispravnoIme;
    do {
        ispravnoIme = true;
        cout << "Uneti ime kupca: ";
        getline(cin, ime_kupca);
        for (size_t i = 0; i < ime_kupca.length(); ++i) {
            if (!isalpha(ime_kupca[i])) {
                ispravnoIme = false;
                break;
            }
        }
        if (!ispravnoIme || ime_kupca.empty()) {
            cout << "Molimo unesite ispravno ime (samo slova).\n ";
            cin.clear();
            ispravnoIme = false;
        }
    } while (!ispravnoIme);

    bool ispravnoPrezime;
    do {
        ispravnoPrezime = true;
        cout << "Uneti prezime kupca: ";
        getline(cin, prezime_kupca);
        for (size_t i = 0; i < prezime_kupca.length(); ++i) {
            if (!isalpha(prezime_kupca[i])) {
                ispravnoPrezime = false;
                break;
            }
        }
        if (!ispravnoPrezime || prezime_kupca.empty()) {
            cout << "Molimo unesite ispravno prezime (samo slova).\n ";
            cin.clear();
            ispravnoIme = false;
        }
    } while (!ispravnoPrezime);

    bool ispravnaAdresa;
    do {
        ispravnaAdresa = true;
        cout << "Uneti adresu kupca: ";
        getline(cin, adresa_kupca);
        for (size_t i = 0; i < adresa_kupca.length(); ++i) {
            if (!isalnum(adresa_kupca[i]) && adresa_kupca[i] != ' ') {
                ispravnaAdresa = false;
                break;
            }
        }
        if (!ispravnaAdresa || adresa_kupca.empty()) {
            cout << "Molimo unesite ispravnu adresu (samo slova).\n ";
            cin.clear();
            ispravnoIme = false;
        }
    } while (!ispravnaAdresa);
    cout << "**************************************" << endl;

    prodavnica.Dodaj_Proizvod(Proizvod("Mleko", 250.00));
    prodavnica.Dodaj_Proizvod(Proizvod("Hleb", 75.00));
    prodavnica.Dodaj_Proizvod(Proizvod("Jogurt", 40.00));
    prodavnica.Dodaj_Proizvod(Proizvod("Jaja", 150.00));
    prodavnica.Dodaj_Proizvod(Proizvod("Pavlaka", 65.00));
    prodavnica.Dodaj_Proizvod(Proizvod("Kecap", 80.00));
    prodavnica.Dodaj_Proizvod(Proizvod("So", 25.00));
    prodavnica.Dodaj_Proizvod(Proizvod("Biber", 35.00));
    prodavnica.Dodaj_Proizvod(Proizvod("Beli Luk", 45.00));
    prodavnica.Dodaj_Proizvod(Proizvod("Kromir", 160.00));
    prodavnica.Dodaj_Proizvod(Proizvod("Paradajz", 130.00));
    prodavnica.Dodaj_Proizvod(Proizvod("Banana", 80.00));
    prodavnica.Dodaj_Proizvod(Proizvod("Zelena salata", 90.00));

    prodavnica.ispisi_ponudjene_proizvode();

    Korpa korpa;
    char izbor;
    do {
    cout << "Izaberite neke od ponudjenih proizvoda" << endl;
    cout << "--------------------------------------" << endl;
    const vector<Proizvod>& proizvodi = prodavnica.GetProizvodi();
    for (size_t i = 0; i < proizvodi.size(); i++) {
        cout << i + 1 << ". " << proizvodi[i].GetNazivProizvoda() << " - " << proizvodi[i].GetCenaProizvoda() << " din." << endl;

    }
            int broj_izbora;
            do {
                cout << "Kako biste izabrali proizvod morate uneti njegov broj: ";
                cin >> broj_izbora;
                if (broj_izbora >= 1 && broj_izbora <= proizvodi.size()) {
                    const Proizvod& izabrani_proizvod = proizvodi[broj_izbora - 1];
                    korpa.dodaj_proizvod(izabrani_proizvod);
                    cout << "Proizvod: " << izabrani_proizvod.GetNazivProizvoda() << " dodat/a u korpu." << endl << endl;
                    cout << "Ako zelite da uklonite izabrani proizvod unesite -1." << endl;
                }
                else if (broj_izbora == -1) {
                    string naziv_za_uklanjanje;
                    cout << "Uneti naziv proizvoda za uklanjanje: ";
                    cin.ignore();
                    getline(cin, naziv_za_uklanjanje);
                    korpa.ukloni_proizvod(naziv_za_uklanjanje);
                }
        } while (broj_izbora != -1 && (broj_izbora < 1 || broj_izbora > proizvodi.size()));

        cout << "Da li nastavljate sa kupovinom (D/N): ";
        do {
            cin >> izbor;
            izbor = tolower(izbor);

            if (izbor != 'n' && izbor != 'd') {
                cout << "Niste uneli odgovarajucu opciju, molimo unesite 'D' ili 'N'." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (izbor != 'n' && izbor != 'd');
    }while (izbor != 'n');
    char izbor_za_sortiranje;

    cout << "Da li zelite da sortirate izabrane proizvode po ceni (D/N): ";
    cin >> izbor_za_sortiranje;
    if (izbor_za_sortiranje == 'D' || izbor_za_sortiranje == 'd') {
        char redosled_izbora;
        cout << "Izaberite redosled sortiranja (R - rastuci, O - opadajuci): ";
        cin >> redosled_izbora;
        bool opadajuce = (redosled_izbora == 'O' || redosled_izbora == 'o');
        korpa.Sortiraj_Proizvode_Po_Ceni(opadajuce);
    }
    double ukupna_cena = korpa.operator+();
    cout << "**************************************************" << endl;
    cout << "U korpi se nalaze sledeci proizvodi: " << endl;
    cout << "Ukupan broj izabranih proizvoda: " << Korpa::GetUkupanBrojProizvoda() << endl;
    const vector<Proizvod>& izabrani_proizvodi = korpa.GetProizvodi();
    for (const auto& proizvod : izabrani_proizvodi) {
        cout << proizvod.GetNazivProizvoda() << " - " << proizvod.GetCenaProizvoda() << endl;
    }

    Kupac<string> kupac(ime_kupca, prezime_kupca, adresa_kupca);
    Kasa kasa(korpa.GetProizvodi(), ukupna_cena);
    kupac.IspisiPodatkeKupca();
    kasa.Prikazi_Racun();
    korpa.ispisi_racun_u_fajl();

    system("pause");
    return 0;
}
