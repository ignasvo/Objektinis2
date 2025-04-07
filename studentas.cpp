#include "Studentas.h"

Studentas::Studentas() : egzaminas_(0), galutinisBalas_(0.0) {}

Studentas::Studentas(std::istream& is) {
    readStudent(is);
    apskaiciuotiGalutini();
}

Studentas::~Studentas() {}

std::string Studentas::vardas() const {
    return vardas_;
}

std::string Studentas::pavarde() const {
    return pavarde_;
}

int Studentas::egzaminas() const {
    return egzaminas_;
}

double Studentas::galutinisBalas() const {
    return galutinisBalas_;
}

std::istream& Studentas::readStudent(std::istream& is) {
    is >> vardas_ >> pavarde_;
    namuDarbai_.clear();

    int pazymys;
    while (is >> pazymys) namuDarbai_.push_back(pazymys);

    if (namuDarbai_.empty()) throw std::runtime_error("Trūksta pažymių");

    egzaminas_ = namuDarbai_.back();
    namuDarbai_.pop_back();

    apskaiciuotiGalutini();
    return is;
}

void Studentas::apskaiciuotiGalutini() {
    if (namuDarbai_.empty()) {
        galutinisBalas_ = 0;
        return;
    }

    double vidurkis = std::accumulate(namuDarbai_.begin(), namuDarbai_.end(), 0.0) / namuDarbai_.size();
    galutinisBalas_ = 0.4 * vidurkis + 0.6 * egzaminas_;
}
