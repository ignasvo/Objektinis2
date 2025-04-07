#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>
#include <numeric>

class Studentas {
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> namuDarbai_;
    int egzaminas_;
    double galutinisBalas_;

public:
    Studentas();  // default konstruktorius
    Studentas(std::istream& is);  // konstruktorius su stream
    ~Studentas(); // destruktorius

    std::string vardas() const;
    std::string pavarde() const;
    int egzaminas() const;
    double galutinisBalas() const;

    std::istream& readStudent(std::istream& is);
    void apskaiciuotiGalutini();
};

#endif