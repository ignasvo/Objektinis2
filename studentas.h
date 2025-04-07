#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <stdexcept>

class Studentas {
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> namuDarbai_;
    int egzaminas_;
    double galutinisBalas_;

public:
    Studentas();                 // Default konstruktorius
    Studentas(std::istream& is); // Konstruktorius su įvestimi
    ~Studentas();                // Destruktorius

    // Getteriai
    std::string vardas() const;
    std::string pavarde() const;
    int egzaminas() const;
    double galutinisBalas() const;

    // Metodai
    std::istream& readStudent(std::istream& is);
    void apskaiciuotiGalutini();
};

#endif