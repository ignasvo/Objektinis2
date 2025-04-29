#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

class Studentas {
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> nd_;
    int egzaminas_;
    double galutinisBalas_;

public:
    Studentas(); // tuščias konstruktorius
    Studentas(std::istream& is); // konstruktorius iš srauto
    ~Studentas(); // Destruktoriaus deklaracija

    // Getteriai
    std::string vardas() const;
    std::string pavarde() const;
    int egzaminas() const;
    double galutinis() const;
    const std::vector<int>& nd() const;

    // Setteriai
    void setVardas(const std::string& vardas);
    void setPavarde(const std::string& pavarde);
    void setEgzaminas(int egzaminas);
    void pridetiND(int pazymys);

    // Metodai
    void skaiciuotiGalutini(char metodas);
    void generuotiPazymius(int kiek);
    std::istream& read(std::istream& is);

    // Friend funkcijos palyginimui
    friend bool compareVardas(const Studentas& a, const Studentas& b);
    friend bool comparePavarde(const Studentas& a, const Studentas& b);
    friend bool compareGalutinis(const Studentas& a, const Studentas& b);
};

// Deklaracijos palyginimui
bool compareVardas(const Studentas& a, const Studentas& b);
bool comparePavarde(const Studentas& a, const Studentas& b);
bool compareGalutinis(const Studentas& a, const Studentas& b);
#endif
