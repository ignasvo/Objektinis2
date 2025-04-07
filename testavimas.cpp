#include "testavimas.h"

int main() {
    std::string failoVardas;
    std::cout << "Iveskite testo failo pavadinima: ";
    std::getline(std::cin, failoVardas);

    testuotiStrategija3_Vector(failoVardas);
    return 0;
}
