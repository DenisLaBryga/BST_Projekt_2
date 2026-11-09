/**
 * @file ObslugaPlikow.h
 * @brief Plik naglowkowy klasy ObslugaPlikow odpowiadajacej za operacje plikowe (binarne i tekstowe).
 */

#pragma once
#include "DrzewoBST.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * @class ObslugaPlikow
 * @brief Klasa realizujaca zapis i odczyt binarny drzewa BST oraz wczytywanie liczb z pliku tekstowego.
 */
class ObslugaPlikow {
public:
    /**
     * @brief Zapisuje stan drzewa BST (kontener STL) do pliku binarnego.
     * @param drzewo Referencja do obiektu drzewa BST.
     * @param nazwaPliku Nazwa pliku binarnego do zapisu.
     * @return true jesli zapis sie powiodl, false w przypadku bledu.
     */
    bool zapisBinarny(const DrzewoBST& drzewo, const string& nazwaPliku) const;

    /**
     * @brief Odtwarza stan drzewa BST z pliku binarnego.
     * @param drzewo Referencja do obiektu drzewa BST, do ktorego zostana wczytane dane.
     * @param nazwaPliku Nazwa pliku binarnego do odczytu.
     * @return true jesli odczyt sie powiodl, false w przypadku bledu.
     */
    bool odczytBinarny(DrzewoBST& drzewo, const string& nazwaPliku) const;

    /**
     * @brief Wczytuje liczby calkowite z pliku tekstowego i buduje drzewo BST.
     * @param drzewo Referencja do obiektu drzewa BST.
     * @param nazwaPliku Nazwa pliku tekstowego z liczbami.
     * @param wyczyscIstniejace Flaga okreslajaca, czy wczytac do pustego drzewa (true), czy dopisac do istniejacego (false).
     * @return true jesli wczytanie sie powiodlo, false w przypadku bledu.
     */
    bool wczytajLiczbyZPliku(DrzewoBST& drzewo, const string& nazwaPliku, bool wyczyscIstniejace) const;
};
