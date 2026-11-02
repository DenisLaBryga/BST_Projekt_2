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

