/**
 * @file main.cpp
 * @brief Glowny plik programu wyswietlajacy menu i obslugujacy interakcje z uzytkownikiem.
 */

#include <iostream>
#include <string>
#include <clocale>
#include "DrzewoBST.h"
#include "ObslugaPlikow.h"

using namespace std;

/**
 * @brief Wyswietla dostepne opcje menu glownego.
 */
void wyswietlMenu() {
    cout << "\n================ MENU DRZEWA BST ================" << endl;
    cout << "1. Dodaj element do drzewa" << endl;
    cout << "2. Usun wybrany element z drzewa" << endl;
    cout << "3. Usun cale drzewo" << endl;
    cout << "4. Szukaj drogi do podanego elementu" << endl;
    cout << "5. Wyswietl drzewo (graficznie + preorder/inorder/postorder)" << endl;
    cout << "6. Zapisz wygenerowane drzewo do pliku tekstowego" << endl;
    cout << "7. Zapisz drzewo do pliku binarnego" << endl;
    cout << "8. Odczytaj drzewo z pliku binarnego" << endl;
    cout << "9. Wczytaj liczby z pliku tekstowego (zbuduj/rozbuduj drzewo)" << endl;
    cout << "0. Wyjscie z programu" << endl;
    cout << "=================================================" << endl;
    cout << "Wybierz opcje: ";
}

/**
 * @brief Glowna funkcja programu.
 * @return Kod zakonczenia programu (0).
 */
int main() {
    setlocale(LC_ALL, "");

    DrzewoBST drzewo;
    ObslugaPlikow pliki;
    int opcja = -1;

    while (opcja != 0) {
        wyswietlMenu();
        if (!(cin >> opcja)) {
            // Zabezpieczenie przed wpisaniem litery zamiast liczby w menu
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Blad: Prosze podac poprawny numer opcji." << endl;
            opcja = -1;
            continue;
        }

        int wartosc;
        string nazwaPliku;

        switch (opcja) {
        case 1:
            cout << "Podaj liczbe calkowita do dodania: ";
            cin >> wartosc;
            drzewo.dodajElement(wartosc);
            break;

        case 2:
            cout << "Podaj liczbe calkowita do usuniecia: ";
            cin >> wartosc;
            drzewo.usunElement(wartosc);
            break;

        case 3:
            drzewo.usunCaleDrzewo();
            break;

        case 4:
            cout << "Podaj element, do ktorego chcesz znalezc droge: ";
            cin >> wartosc;
            drzewo.szukajDrogi(wartosc);

        case 5:
            drzewo.wyswietlDrzewo();
            break;

        case 6:
            cout << "Podaj nazwe pliku tekstowego do zapisu (np. drzewo.txt): ";
            cin >> nazwaPliku;
            drzewo.zapisTekstowy(nazwaPliku);
            break;

        case 7:
            cout << "Podaj nazwe pliku binarnego do zapisu (np. drzewo.bin): ";
            cin >> nazwaPliku;
            break;

        case 8:
            cout << "Podaj nazwe pliku binarnego do odczytu (np. drzewo.bin): ";
            cin >> nazwaPliku;
            pliki.odczytBinarny(drzewo, nazwaPliku);
            break;

        case 9: {
            cout << "Podaj nazwe pliku tekstowego z liczbami (np. liczby.txt): ";
            cin >> nazwaPliku;
            cout << "Czy chcesz wyczyscic obecne drzewo przed wczytaniem? (1 - Tak / 0 - Nie, dopisz do istniejacego): ";
            
        }

        case 0:
            cout << "Zamykanie programu..." << endl;
            break;

        default:
            cout << "Nieznana opcja. Wybierz numer od 0 do 9." << endl;
            break;
        }
    }

    return 0;
}