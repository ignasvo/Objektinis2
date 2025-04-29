#include "testavimas.h"

// Funkcija skaitymui
template <typename Container>
void nuskaitytiIsFailo(Container& studentai, const std::string& failoVardas) {
    std::ifstream in(failoVardas);
    if (!in) {
        throw std::runtime_error("Nepavyko atidaryti failo.");
    }

    std::string eilute;
    getline(in, eilute); // praleidžiam antraštę

    while (getline(in, eilute)) {
        std::istringstream iss(eilute);
        Studentas s;
        s.read(iss);  // Naudojam klasės read metodą
        studentai.push_back(s);
    }
}

template <typename Container>
void rikiuotiStudentus(Container&, char) {
    static_assert(sizeof(Container) == 0, "rikiuotiStudentus: nepalaikomas konteinerio tipas. Palaikomi: vector, list, deque.");
}

// VECTOR
template <>
void rikiuotiStudentus(std::vector<Studentas>& studentai, char kriterijus) {
    switch (std::tolower(kriterijus)) {
        case 'v':
            std::sort(studentai.begin(), studentai.end(), compareVardas);
            break;
        case 'p':
            std::sort(studentai.begin(), studentai.end(), comparePavarde);
            break;
        case 'g':
            std::sort(studentai.begin(), studentai.end(), compareGalutinis);
            break;
        default:
            std::cout << "Neteisingas rikiavimo kriterijus.\n";
    }
}

// LIST
template <>
void rikiuotiStudentus(std::list<Studentas>& studentai, char kriterijus) {
    switch (std::tolower(kriterijus)) {
        case 'v':
            studentai.sort(compareVardas);
            break;
        case 'p':
            studentai.sort(comparePavarde);
            break;
        case 'g':
            studentai.sort(compareGalutinis);
            break;
        default:
            std::cout << "Neteisingas rikiavimo kriterijus.\n";
    }
}

// DEQUE
template <>
void rikiuotiStudentus(std::deque<Studentas>& studentai, char kriterijus) {
    switch (std::tolower(kriterijus)) {
        case 'v':
            std::sort(studentai.begin(), studentai.end(), compareVardas);
            break;
        case 'p':
            std::sort(studentai.begin(), studentai.end(), comparePavarde);
            break;
        case 'g':
            std::sort(studentai.begin(), studentai.end(), compareGalutinis);
            break;
        default:
            std::cout << "Neteisingas rikiavimo kriterijus.\n";
    }
}

// Strategija 1: dvi naujos kolekcijos
template <typename Container>
void padalintiStudentus1(const Container& studentai, Container& vargsai, Container& kietiakai) {
    for (const auto& s : studentai) {
        if (s.galutinis() < 5.0) vargsai.push_back(s);
        else kietiakai.push_back(s);
    }
}

// Strategija 2: perkopijuojant kietiakius, po to pašalinant vargšus
template <typename Container>
void padalintiStudentus2(Container& studentai, Container& kietiakai) {
    std::copy_if(studentai.begin(), studentai.end(), std::back_inserter(kietiakai),
                 [](const Studentas& s) { return s.galutinis() >= 5.0; });

    studentai.erase(std::remove_if(studentai.begin(), studentai.end(),
                   [](const Studentas& s) { return s.galutinis() >= 5.0; }),
                   studentai.end());
}

// Strategija 3: iš karto skaidant į vietą
template <typename Container>
void padalintiStudentus3(Container& studentai, Container& vargsai) {
    auto it = std::stable_partition(studentai.begin(), studentai.end(),
                [](const Studentas& s) { return s.galutinis() < 5.0; });

    vargsai.insert(vargsai.end(), studentai.begin(), it);
    studentai.erase(studentai.begin(), it);
}

// Laiko matavimas
template <typename Container>
void testuoti(const std::string& failas, int strategija) {
    Container studentai, vargsai, kietiakai;

    auto start = std::chrono::high_resolution_clock::now();
    nuskaitytiIsFailo(studentai, failas);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Nuskaitymas uztruko: "
              << std::chrono::duration<double>(end - start).count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    rikiuotiStudentus(studentai, 'v');
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Rikiavimas uztruko: "
              << std::chrono::duration<double>(end - start).count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    if (strategija == 1) padalintiStudentus1(studentai, vargsai, kietiakai);
    else if (strategija == 2) padalintiStudentus2(studentai, kietiakai);
    else if (strategija == 3) padalintiStudentus3(studentai, vargsai);
    else std::cout << "Neteisinga strategija\n";
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Skaidymas uztruko: "
              << std::chrono::duration<double>(end - start).count() << " s\n";
}

// Explicit instancijos
template void testuoti<std::vector<Studentas>>(const std::string&, int);
template void testuoti<std::list<Studentas>>(const std::string&, int);
template void testuoti<std::deque<Studentas>>(const std::string&, int);
