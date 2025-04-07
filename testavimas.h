#ifndef TESTAVIMAS_H
#define TESTAVIMAS_H

#include <vector>
#include <list>
#include <deque>
#include <string>
#include <chrono>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <typeinfo>

#include "Studentas.h" // nauja klasė vietoj struct

// ==================== Šabloninės funkcijos ====================

template<typename Container>
void nuskaitytiIsFailo(Container& studentai, const std::string& failoVardas);

template<typename Container>
void rikiuotiStudentus(Container& studentai, char kriterijus);

template<typename Container>
void strategija1(const Container& studentai, Container& vargsiai, Container& kietiakai);

template<typename Container>
void strategija2(Container& studentai, Container& vargsiai);

template<typename Container>
void strategija3(Container& studentai, Container& vargsiai);

template<typename Container>
void testuotiStrategijas(const std::string& failoVardas);

void testuotiVisusKonteinerius(const std::string& failoVardas);

// ==================== Konteinerio pavadinimas ====================

template<typename Container>
struct ContainerName {
    static std::string name() { return typeid(Container).name(); }
};

// Specializacijos
template<>
struct ContainerName<std::vector<Studentas>> {
    static std::string name() { return "Vector"; }
};

template<>
struct ContainerName<std::list<Studentas>> {
    static std::string name() { return "List"; }
};

template<>
struct ContainerName<std::deque<Studentas>> {
    static std::string name() { return "Deque"; }
};

#endif
