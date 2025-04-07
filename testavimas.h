#ifndef TESTAVIMAS_H
#define TESTAVIMAS_H

#include <vector>
#include <string>
#include <chrono>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <typeinfo>
#include "Studentas.h"

// Šabloninė nuskaitymo funkcija
template<typename Container>
void nuskaitytiIsFailo(Container& studentai, const std::string& failoVardas);

// Tik 3 strategija su vektoriumi
void testuotiStrategija3_Vector(const std::string& failoVardas);

#endif
