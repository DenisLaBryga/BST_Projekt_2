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