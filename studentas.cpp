#include "Studentas.h"

// Tuščias konstruktorius
Studentas::Studentas() : egzaminas_(0), galutinisBalas_(0.0) {}

// Konstruktorius su nuskaitymu
Studentas::Studentas(std::istream& is) {
    read(is);
}

// Getteriai
std::string Studentas::vardas() const {
    return vardas_;
}

std::string Studentas::pavarde() const {
    return pavarde_;
}

int Studentas::egzaminas() const {
    return egzaminas_;
}

double Studentas::galutinis() const {
    return galutinisBalas_;
}

const std::vector<int>& Studentas::nd() const {
    return nd_;
}

// Setteriai
void Studentas::setVardas(const std::string& vardas) {
    vardas_ = vardas;
}

void Studentas::setPavarde(const std::string& pavarde) {
    pavarde_ = pavarde;
}

void Studentas::setEgzaminas(int egzaminas) {
    egzaminas_ = egzaminas;
}

void Studentas::pridetiND(int pazymys) {
    nd_.push_back(pazymys);
}

// Metodas galutinio balo skaiciavimui
void Studentas::skaiciuotiGalutini(char metodas) {
    if (nd_.empty()) {
        galutinisBalas_ = 0.0;
        return;
    }

    if (metodas == 'V' || metodas == 'v') {
        double suma = std::accumulate(nd_.begin(), nd_.end(), 0.0);
        galutinisBalas_ = 0.4 * (suma / nd_.size()) + 0.6 * egzaminas_;
    } else {
        std::sort(nd_.begin(), nd_.end());
        size_t dydis = nd_.size();
        double mediana;
        if (dydis % 2 == 0)
            mediana = (nd_[dydis/2 - 1] + nd_[dydis/2]) / 2.0;
        else
            mediana = nd_[dydis/2];
        galutinisBalas_ = 0.4 * mediana + 0.6 * egzaminas_;
    }
}

// Metodas pažymių generavimui
void Studentas::generuotiPazymius(int kiek) {
    nd_.clear();
    nd_.resize(kiek);
    for (int& paz : nd_) {
        paz = rand() % 10 + 1;
    }
    egzaminas_ = rand() % 10 + 1;
}

// Metodas duomenų nuskaitymui
std::istream& Studentas::read(std::istream& is) {
    is >> vardas_ >> pavarde_;
    int paz;
    while (is >> paz) {
        nd_.push_back(paz);
    }
    if (!nd_.empty()) {
        egzaminas_ = nd_.back();
        nd_.pop_back();
    }
    return is;
}

Studentas::~Studentas() {
    // Kadangi nenaudojam new ar failų, nieko nereikia sunaikinti.
}

// Draugai: palyginimo funkcijos
bool compareVardas(const Studentas& a, const Studentas& b) {
    return a.vardas_ < b.vardas_;
}

bool comparePavarde(const Studentas& a, const Studentas& b) {
    return a.pavarde_ < b.pavarde_;
}

bool compareGalutinis(const Studentas& a, const Studentas& b) {
    return a.galutinisBalas_ > b.galutinisBalas_;
}
