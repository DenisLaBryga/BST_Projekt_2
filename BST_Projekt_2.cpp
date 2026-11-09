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