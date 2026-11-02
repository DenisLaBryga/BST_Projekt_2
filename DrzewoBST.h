/**
 * @file DrzewoBST.h
 * @brief Plik naglowkowy klasy DrzewoBST implementujacej drzewo binarne poszukiwan w kontenerze STL.
 */

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

/**
 * @struct Wezel
 * @brief Struktura reprezentujaca pojedynczy wezel drzewa BST.
 */
struct Wezel {
    int wartosc; ///< Wartosc liczbowo przechowywana w wezle
    int lewy;    ///< Indeks lewego potomka w wektorze (-1 oznacza brak)
    int prawy;   ///< Indeks prawego potomka w wektorze (-1 oznacza brak)

    /**
     * @brief Konstruktor tworzacy nowy wezel.
     * @param w Wartosc przypisywana do wezla.
     */
    Wezel(int w = 0) : wartosc(w), lewy(-1), prawy(-1) {}
};

/**
 * @class DrzewoBST
 * @brief Klasa zarzadzajaca struktura drzewa BST oparta o kontener std::vector.
 */
class DrzewoBST {
private:
    vector<Wezel> wezly; ///< Kontener STL przechowujacy wszystkie wezly drzewa
    int korzen;          ///< Indeks korzenia drzewa (-1 gdy drzewo jest puste)

    /**
     * @brief Rekurencyjna metoda pomocnicza usuwajaca wybrany element z poddrzewa.
     * @param indeks Aktualny indeks rozpatrywanego wezla.
     * @param wartosc Wartosc do usuniecia.
     * @return Nowy indeks korzenia zmodyfikowanego poddrzewa.
     */
    int usunWezelRekurencyjnie(int indeks, int wartosc);

    /**
     * @brief Znajduje wezel o najmniejszej wartosci w danym poddrzewie.
     * @param indeks Indeks korzenia badanego poddrzewa.
     * @return Indeks wezla z minimalna wartoscia.
     */
    int znajdzMinimum(int indeks) const;

    /**
     * @brief Rekurencyjnie wypisuje elementy metoda Preorder (Korzen -> Lewy -> Prawy).
     * @param indeks Aktualny indeks wezla.
     * @param strumien Strumien wyjsciowy (ekran lub plik).
     */
    void preorder(int indeks, ostream& strumien) const;

    /**
     * @brief Rekurencyjnie wypisuje elementy metoda Inorder (Lewy -> Korzen -> Prawy).
     * @param indeks Aktualny indeks wezla.
     * @param strumien Strumien wyjsciowy (ekran lub plik).
     */
    void inorder(int indeks, ostream& strumien) const;

    /**
     * @brief Rekurencyjnie wypisuje elementy metoda Postorder (Lewy -> Prawy -> Korzen).
     * @param indeks Aktualny indeks wezla.
     * @param strumien Strumien wyjsciowy (ekran lub plik).
     */
    void postorder(int indeks, ostream& strumien) const;

    /**
     * @brief Rekurencyjnie rysuje graficzna strukture drzewa w konsoli lub pliku.
     * @param indeks Aktualny indeks wezla.
     * @param wciecie Aktualny poziom wciecia tekstu.
     * @param strumien Strumien wyjsciowy (ekran lub plik).
     */
    void rysujDrzewo(int indeks, int wciecie, ostream& strumien) const;

public:
    /**
     * @brief Konstruktor domyslny inicjalizujacy puste drzewo BST.
     */
    DrzewoBST();

    /**
     * @brief Wstawia nowa liczbe calkowita we wlasciwe miejsce drzewa BST.
     * @param wartosc Liczba calkowita do dodania.
     */
    void dodajElement(int wartosc);

    /**
     * @brief Usuwa wybrany wezel z zachowaniem wlasnosci drzewa BST.
     * @param wartosc Liczba calkowita do usuniecia.
     */
    void usunElement(int wartosc);

    /**
     * @brief Zwalnia wszystkie elementy z kontenera STL, czyniac drzewo pustym.
     */
    void usunCaleDrzewo();

    /**
     * @brief Wyswietla kolejne wezly na drodze od korzenia do szukanego elementu.
     * @param wartosc Szukana liczba calkowita.
     */
    void szukajDrogi(int wartosc) const;

    /**
     * @brief Prezentuje drzewo graficznie na ekranie oraz wypisuje je wybrana metoda (preorder, inorder, postorder).
     */
    void wyswietlDrzewo() const;

    /**
     * @brief Zapisuje strukture wygenerowanego drzewa do pliku tekstowego.
     * @param nazwaPliku Sciezka lub nazwa pliku tekstowego.
     */
    void zapisTekstowy(const string& nazwaPliku) const;

    /**
     * @brief Sprawdza, czy drzewo jest puste.
     * @return true jesli drzewo nie zawiera elementow, false w przeciwnym razie.
     */
    bool czyPuste() const;

    // Deklaracja przyjazni, aby klasa ObslugaPlikow miala bezposredni dostep do wektora przy zapisie binarnym
    friend class ObslugaPlikow;
};
