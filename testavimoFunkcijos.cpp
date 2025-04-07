#include "testavimas.h"

template<typename Container>
void nuskaitytiIsFailo(Container& studentai, const std::string& failoVardas) {
    std::ifstream failas(failoVardas);
    if (!failas) throw std::runtime_error("Failas nerastas: " + failoVardas);

    std::string eilute;
    std::getline(failas, eilute); // Praleidžiam antraštę

    while (std::getline(failas, eilute)) {
        std::istringstream iss(eilute);
        Studentas s(iss);
        studentai.push_back(s);
    }
}

void testuotiStrategija3_Vector(const std::string& failoVardas) {
    std::vector<Studentas> studentai, vargsiai;

    nuskaitytiIsFailo(studentai, failoVardas);

    auto start = std::chrono::high_resolution_clock::now();

    auto it = std::partition(studentai.begin(), studentai.end(), [](const Studentas& s) {
        return s.galutinisBalas() >= 5.0;
    });
    vargsiai.assign(it, studentai.end());
    studentai.erase(it, studentai.end());

    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "\n=== Vector + Strategija3 ===\n"
              << "Trukme: " << std::chrono::duration<double>(end - start).count() << " s\n";
}

// Šablonų instancijavimas
template void nuskaitytiIsFailo<std::vector<Studentas>>(std::vector<Studentas>&, const std::string&);