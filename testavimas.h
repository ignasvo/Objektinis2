#ifndef TESTAVIMAS_H
#define TESTAVIMAS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <chrono>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <stdexcept>
#include "Studentas.h"

void generuotiFaila(const std::string& pavadinimas, int n, int ndSk);

void nuskaitytiIsFailo(const std::string& failoVardas, std::vector<Studentas>& studentai);
void nuskaitytiIsFailo(const std::string& failoVardas, std::list<Studentas>& studentai);
void nuskaitytiIsFailo(const std::string& failoVardas, std::deque<Studentas>& studentai);

void padalintiStudentusStrategija1(std::vector<Studentas>& studentai, std::vector<Studentas>& vargsai);
void padalintiStudentusStrategija1(std::list<Studentas>& studentai, std::list<Studentas>& vargsai);
void padalintiStudentusStrategija1(std::deque<Studentas>& studentai, std::deque<Studentas>& vargsai);

void padalintiStudentusStrategija2(std::vector<Studentas>& studentai, std::vector<Studentas>& vargsai);
void padalintiStudentusStrategija2(std::list<Studentas>& studentai, std::list<Studentas>& vargsai);
void padalintiStudentusStrategija2(std::deque<Studentas>& studentai, std::deque<Studentas>& vargsai);

void padalintiStudentusStrategija3(std::vector<Studentas>& studentai, std::vector<Studentas>& vargsai);
void padalintiStudentusStrategija3(std::list<Studentas>& studentai, std::list<Studentas>& vargsai);
void padalintiStudentusStrategija3(std::deque<Studentas>& studentai, std::deque<Studentas>& vargsai);

template <typename Container>
void testuoti(const std::string& failoVardas, int strategija);

#endif
