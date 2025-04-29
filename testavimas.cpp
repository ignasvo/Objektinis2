#include "testavimas.h"
#include <iostream>
#include <string>

int main() {
    std::string failoVardas;
    int strategija;

    std::cout << "Iveskite failo pavadinima: ";
    std::cin >> failoVardas;

    std::cout << "Pasirinkite strategija (1, 2, 3): ";
    std::cin >> strategija;

    std::cout << "\nTestuojame su std::vector<Studentas>:\n";
    testuoti<std::vector<Studentas>>(failoVardas, strategija);

    std::cout << "\nTestuojame su std::list<Studentas>:\n";
    testuoti<std::list<Studentas>>(failoVardas, strategija);

    std::cout << "\nTestuojame su std::deque<Studentas>:\n";
    testuoti<std::deque<Studentas>>(failoVardas, strategija);

    return 0;
}