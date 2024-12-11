// Harjoitustyö.cpp
//Tomi Alkava

#include <iostream> 
#include <ctime>  // Tätä käytetään satunnaislukujen alustamiseen.
#include <cstdlib> // Sattunnaislukujen generointi.
#include <vector> // Tätä tarvitaan dynaamiseen tietorakenteeseen.
#include <algorithm> // Find komennon luomiseen.
#include <string> // Tekstin lisäämiseen.
#include <locale> // Tätä tarvitaan ääkkösiin.

using namespace std;

// Luodaan aliohjelma, joka arpoo huoneen numeron. Lisätään funktio joka estää aikaisemman numeron arpomisen.
int huoneennumero(int min, int max, vector<int>& varatut) {
    int satunnainennumero;
    do {
        satunnainennumero = rand() % 70 + 1;
    } while (find(varatut.begin(), varatut.end(), satunnainennumero) != varatut.end());
    varatut.push_back(satunnainennumero);
    return satunnainennumero;
}


int main()
{
    setlocale(LC_ALL, "fi_FI.UTF-8"); //Ääkköset
    srand(time(0));

    // Suoritetaan satunnaislukujen arvonta huoneiden määrälle
    int min = 30, max = 70;

    int maara = min + rand() % 41;
    vector<int> varatuthuoneet; 
    
    char vastaus;

    cout << "Aloittaaksesi varauksen paina k\n"; 
    cin >> vastaus;
    string Etunimi;
    string Sukunimi;
  
   // Aloitetaan varaus
    if (vastaus == 'k') {
        cout << "Tervetuloa hotellin varaus jarjestelmään. Anna varaajan etunimi" << endl;
    }

    else {
        cout << "varaus peruutettu";
        return 0;
    } 

     
    cin >> Etunimi;
    cout << "Anna sukunimi\n";
    cin >> Sukunimi;
   
    cout << "Hei " << Etunimi << " " << Sukunimi << ". ";

    // Määritetään hinta arpomalla.
    int hinta = 80 + rand() % 21;

    // Luodaan while komento jolla voidaan kierrättää varausprosessia, mikäli käyttäjä haluaa varata lisää huoneita.
    while (vastaus == 'k') {

        int numero = huoneennumero(min, max, varatuthuoneet);

        maara--;
        if (maara <= 0) {
            cout << "Valitettavasti huoneita ei ole vapaana.\n";
        }
        else {
            cout << "Huoneita on " << maara << " vapaana. \n";
            cout << "Yhden yön hinta on " << hinta << " euroa. Montako yöta haluat varata?\n";
        }

        int yo, varaus;

        cin >> yo;

        if (yo <= 0) {
            cout << "Luvun on oltava positiivinen\n";
        }
       
        else {
            varaus = yo * hinta;
            cout << "Varaus onnistui.\n";
            cout << "Varaajan nimi: " << Etunimi <<" "<< Sukunimi << "\n";
            cout << "Huoneen numero: " << numero << "\n";
            cout << "Hinta: " << varaus << " euroa.\n";
        }

        cout << "Haluatko varata lisaa huoneita (k/e).\n";
        cin >> vastaus;
    }
    // Loppukiitos ohjelman päätteeksi, kun käyttäjä ei halua varata enempää huoneita.
    cout << "Varaus päättynyt. Toivottavasti viihdytte kanssamme. Alkava hotels Oy kiittää.";
    
        return 0;
}