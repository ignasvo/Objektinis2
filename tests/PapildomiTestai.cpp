#include "doctest.h"
#include "../studentas.h"
#include <sstream>

TEST_CASE("Galutinis rezultatas skaiciuojamas teisingai su vidurkiu") {
    Studentas s("Tomas", "Testinis", {8, 9, 10}, 10);
    s.skaiciuotiGalutini('v');

    // (8+9+10)/3 = 9 → 0.4*9 + 0.6*10 = 9.6
    CHECK(s.galutinis() == doctest::Approx(9.6));
}

TEST_CASE("Galutinis rezultatas skaiciuojamas su mediana") {
    Studentas s("Asta", "Medianiene", {5, 7, 9}, 8);
    s.skaiciuotiGalutini('m');

    // Mediana = 7 → 0.4*7 + 0.6*8 = 7.6
    CHECK(s.galutinis() == doctest::Approx(7.6));
}

TEST_CASE("Ivestis per read() veikia") {
    std::istringstream iss("Vardenis Pavardenis 10 9 8 7");
    Studentas s;
    s.read(iss);

    CHECK(s.vardas() == "Vardenis");
    CHECK(s.pavarde() == "Pavardenis");
    CHECK(s.nd().size() == 3);  // paskutinis eina kaip egzaminas
    CHECK(s.egzaminas() == 7);
}