#include "ObslugaPlikow.h"

bool ObslugaPlikow::zapisBinarny(const DrzewoBST& drzewo, const string& nazwaPliku) const {
    ofstream plik(nazwaPliku, ios::binary);
    if (!plik.is_open()) {
        cout << "Blad: Nie mozna otworzyc pliku binarnego " << nazwaPliku << " do zapisu." << endl;
        return false;
    }

    // 1. Zapisujemy indeks korzenia
    plik.write(reinterpret_cast<const char*>(&drzewo.korzen), sizeof(drzewo.korzen));

    // 2. Zapisujemy rozmiar wektora wezlow
    size_t rozmiar = drzewo.wezly.size();
    plik.write(reinterpret_cast<const char*>(&rozmiar), sizeof(rozmiar));

    // 3. Zapisujemy cala zawartosc wektora (jesli nie jest pusty)
    if (rozmiar > 0) {
        plik.write(reinterpret_cast<const char*>(drzewo.wezly.data()), rozmiar * sizeof(Wezel));
    }

    plik.close();
    cout << "Pomyslnie zapisano drzewo binarnie do pliku: " << nazwaPliku << endl;
    return true;
}
#include "ObslugaPlikow.h"

bool ObslugaPlikow::odczytBinarny(DrzewoBST& drzewo, const string& nazwaPliku) const {
    ifstream plik(nazwaPliku, ios::binary);
    if (!plik.is_open()) {
        cout << "Blad: Nie mozna otworzyc pliku binarnego " << nazwaPliku << " do odczytu." << endl;
        return false;
    }

    // Czyscimy obecne drzewo przed odtworzeniem stanu z pliku binarnego
    drzewo.wezly.clear();
    drzewo.korzen = -1;

    // 1. Odczytujemy indeks korzenia
    plik.read(reinterpret_cast<char*>(&drzewo.korzen), sizeof(drzewo.korzen));

    // 2. Odczytujemy rozmiar wektora
    size_t rozmiar = 0;
    plik.read(reinterpret_cast<char*>(&rozmiar), sizeof(rozmiar));

    // 3. Alokujemy miejsce w wektorze i wczytujemy surowe bajty wezlow
    if (rozmiar > 0) {
        drzewo.wezly.resize(rozmiar);
        plik.read(reinterpret_cast<char*>(drzewo.wezly.data()), rozmiar * sizeof(Wezel));
    }

    plik.close();
    cout << "Pomyslnie odtworzono drzewo z pliku binarnego: " << nazwaPliku << endl;
    return true;
}

bool ObslugaPlikow::wczytajLiczbyZPliku(DrzewoBST& drzewo, const string& nazwaPliku, bool wyczyscIstniejace) const {
    ifstream plik(nazwaPliku);
    if (!plik.is_open()) {
        cout << "Blad: Nie mozna otworzyc pliku tekstowego " << nazwaPliku << "." << endl;
        return false;
    }

    if (wyczyscIstniejace) {
        drzewo.usunCaleDrzewo();
    }

    int liczba;
    int licznik = 0;
    while (plik >> liczba) {
        drzewo.dodajElement(liczba);
        licznik++;
    }

    plik.close();
    cout << "Wczytano " << licznik << " liczb z pliku tekstowego: " << nazwaPliku << endl;
    return true;
}