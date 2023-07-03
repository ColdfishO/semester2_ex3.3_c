#include <iostream>
#include<locale.h>
#include "klasa.h"
using namespace std;
void autor(void) {
    cout << endl;
    for (int i = 1; i <= 120; i++) cout << "*";
    cout << "Autor programu: Simon Dudek\n\n";
    for (int i = 1; i <= 120; i++) cout << "*";
    cout << "\n\n";
}
int main() {
    int d;
    double x, y, p;
    setlocale(LC_ALL, "");
    autor();
    cout << "Wpisz pierwsza liczbę zepoloną(część rzeczywista): ";
    cin >> x;
    cout << "(Część urojona): ";
    cin >> y;
    Tzespol pierwsza(x, y);
    Tzespol kopia(x, y);
    cout << "Wpisz drugą liczbę zepoloną(część rzeczywista): ";
    cin >> x;
    cout << "(Część urojona): ";
    cin >> y;
    Tzespol druga(x, y);
    pierwsza.dodaj(druga);
    cout << "Wynik dodawania: ";
    pierwsza.wyświetl();
    pierwsza = kopia;
    pierwsza.odej(druga);
    cout << "Wynik odejmowania: ";
    pierwsza.wyświetl();
    pierwsza = kopia;
    pierwsza.mnoz(druga);
    cout << "Wynik mnożenia: ";
    pierwsza.wyświetl();
    pierwsza = kopia;
    pierwsza.dziel(druga);
    cout << "Wynik dzielenia: ";
    pierwsza.wyświetl();
    pierwsza = kopia;
    pierwsza.mod();
    pierwsza.arg();
    pierwsza.wyniki();
    cout << "Do której potęgi podnieść pierwszą liczbę zepoloną? ";
    cin >> d;
    p = pierwsza.potęga(d);
    cout << "Potęga " << d << " pierwszej liczby zespolonej wynosi " << p << endl;
    system("pause");
    return 0;
}