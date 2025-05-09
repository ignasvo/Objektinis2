#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../studentas.h"


TEST_CASE("Kopijavimo konstruktorius veikia teisingai") {
    Studentas s1("Jonas", "Jonaitis", {10, 9, 8}, 10);
    Studentas s2(s1);

    CHECK(s2.vardas() == "Jonas");
    CHECK(s2.pavarde() == "Jonaitis");
    CHECK(s2.nd().size() == 3);
    CHECK(s2.egzaminas() == 10);
}

TEST_CASE("Perkelimo konstruktorius veikia") {
    Studentas s1("Petras", "Petraitis", {7, 6, 5}, 9);
    Studentas s2(std::move(s1));

    CHECK(s2.vardas() == "Petras");
    CHECK(s2.pavarde() == "Petraitis");
    CHECK(s2.nd().size() == 3);
}

TEST_CASE("Kopijavimo priskyrimo operatorius") {
    Studentas s1("Aiste", "Aistiene", {9, 9, 9}, 10);
    Studentas s2;
    s2 = s1;

    CHECK(s2.vardas() == "Aiste");
    CHECK(s2.pavarde() == "Aistiene");
    CHECK(s2.nd()[0] == 9);
}

TEST_CASE("Perkelimo priskyrimo operatorius") {
    Studentas s1("Tomas", "Tomaitis", {6, 6, 6}, 6);
    Studentas s2;
    s2 = std::move(s1);

    CHECK(s2.vardas() == "Tomas");
    CHECK(s2.nd().size() == 3);
}

TEST_CASE("Destruktorius iskvieciamas (netiesiogiai)") {
    Studentas* s = new Studentas("Test", "Destrukcija", {5}, 5);
    delete s;
    CHECK(true); // jei nesulužo – destruktorius veikia
}