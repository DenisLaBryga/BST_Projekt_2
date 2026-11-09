#include "DrzewoBST.h"

DrzewoBST::DrzewoBST() {
    korzen = -1;
}

bool DrzewoBST::czyPuste() const {
    return korzen == -1;
}

void DrzewoBST::dodajElement(int wartosc) {
    Wezel nowyWezel(wartosc);
    wezly.push_back(nowyWezel);
    int nowyIndeks = static_cast<int>(wezly.size()) - 1;

    if (korzen == -1) {
        korzen = nowyIndeks;
        return;
    }

    int aktualny = korzen;
    while (true) {
        if (wartosc < wezly[aktualny].wartosc) {
            if (wezly[aktualny].lewy == -1) {
                wezly[aktualny].lewy = nowyIndeks;
                break;
            }
            aktualny = wezly[aktualny].lewy;
        }
        else if (wartosc > wezly[aktualny].wartosc) {
            if (wezly[aktualny].prawy == -1) {
                wezly[aktualny].prawy = nowyIndeks;
                break;
            }
            aktualny = wezly[aktualny].prawy;
        }
        else {
            // Jesli wartosc juz istnieje, cofamy dodanie do wektora (brak duplikatow)
            wezly.pop_back();
            cout << "Element " << wartosc << " juz znajduje sie w drzewie." << endl;
            break;
        }
    }
}

int DrzewoBST::znajdzMinimum(int indeks) const {
    int aktualny = indeks;
    while (aktualny != -1 && wezly[aktualny].lewy != -1) {
        aktualny = wezly[aktualny].lewy;
    }
    return aktualny;
}

int DrzewoBST::usunWezelRekurencyjnie(int indeks, int wartosc) {
    if (indeks == -1) {
        cout << "Nie znaleziono elementu " << wartosc << " do usuniecia." << endl;
        return -1;
    }

    if (wartosc < wezly[indeks].wartosc) {
        wezly[indeks].lewy = usunWezelRekurencyjnie(wezly[indeks].lewy, wartosc);
    }
    else if (wartosc > wezly[indeks].wartosc) {
        wezly[indeks].prawy = usunWezelRekurencyjnie(wezly[indeks].prawy, wartosc);
    }
    else {
        // Znaleziono wezel do usuniecia
        // Przypadek 1 i 2: Wezel nie ma dzieci lub ma tylko jedno dziecko
        if (wezly[indeks].lewy == -1) {
            return wezly[indeks].prawy;
        }
        else if (wezly[indeks].prawy == -1) {
            return wezly[indeks].lewy;
        }

        // Przypadek 3: Wezel ma dwoje dzieci
        // Znajdujemy najmniejszy element w prawym poddrzewie (nastepnik inorder)
        int temp = znajdzMinimum(wezly[indeks].prawy);
        wezly[indeks].wartosc = wezly[temp].wartosc;
        wezly[indeks].prawy = usunWezelRekurencyjnie(wezly[indeks].prawy, wezly[temp].wartosc);
    }
    return indeks;
}

void DrzewoBST::usunElement(int wartosc) {
    if (czyPuste()) {
        cout << "Drzewo jest puste. Nie mozna usunac elementu." << endl;
        return;
    }
    korzen = usunWezelRekurencyjnie(korzen, wartosc);
}

void DrzewoBST::usunCaleDrzewo() {
    wezly.clear();
    korzen = -1;
    cout << "Cale drzewo zostalo usuniete (kontener STL wyczyszczony)." << endl;
}

void DrzewoBST::szukajDrogi(int wartosc) const {
    if (czyPuste()) {
        cout << "Drzewo jest puste." << endl;
        return;
    }

    vector<int> droga;
    int aktualny = korzen;
    bool znaleziono = false;

    while (aktualny != -1) {
        droga.push_back(wezly[aktualny].wartosc);
        if (wartosc == wezly[aktualny].wartosc) {
            znaleziono = true;
            break;
        }
        else if (wartosc < wezly[aktualny].wartosc) {
            aktualny = wezly[aktualny].lewy;
        }
        else {
            aktualny = wezly[aktualny].prawy;
        }
    }

    if (znaleziono) {
        cout << "Droga do elementu " << wartosc << ": ";
        for (size_t i = 0; i < droga.size(); i++) {
            cout << droga[i];
            if (i + 1 < droga.size()) cout << " -> ";
        }
        cout << endl;
    }
    else {
        cout << "Element " << wartosc << " nie istnieje w drzewie." << endl;
    }
}

void DrzewoBST::preorder(int indeks, ostream& strumien) const {
    if (indeks == -1) return;
    strumien << wezly[indeks].wartosc << " ";
    preorder(wezly[indeks].lewy, strumien);
    preorder(wezly[indeks].prawy, strumien);
}