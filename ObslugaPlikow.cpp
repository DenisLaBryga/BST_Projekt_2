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