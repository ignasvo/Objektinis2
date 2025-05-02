#include "studentas.h"
#include <iostream>
#include <sstream>

void testRuleOfFive() {
    std::cout << "Rule of Five testas\n";

    Studentas s1("Testas", "Testavicius", {9, 8, 10}, 10);
    Studentas s2 = s1;  // kopijavimo konstruktorius

    Studentas s3 = std::move(s1);  // perkėlimo konstruktorius

    Studentas s4;
    s4 = s2;  // kopijavimo priskyrimas

    Studentas s5;
    s5 = std::move(s3);  // perkėlimo priskyrimas

    std::cout << "\nObjektai sukurti kopijavimo ir perkelimo budu:\n";
    std::cout << "s2: " << s2 << "\n";
    std::cout << "s4: " << s4 << "\n";
    std::cout << "s5: " << s5 << "\n";
}

void testDestruktorius() {
    std::cout << "\nDestruktoriaus testas\n";
    {
        Studentas laikinas("Testas", "Testavicius", {5, 6, 7}, 8);
        std::cout << "Laikinas studentas sukurtas: " << laikinas << "\n";
    }
    std::cout << "Isejome is bloko, destruktorius turejo buti iskvieciamas.\n";
}

void testIO() {
    std::cout << "\nIvesties ir isvesties operatoriu testas";
    std::istringstream iss("Testas Testavicius 10 9 8 7");
    Studentas s;
    iss >> s; 

    std::cout << "\nNuskaitytas studentas:\n";
    std::cout << s << "\n";
}

int main() {
    testRuleOfFive();
    testDestruktorius();
    testIO();

    std::cout << "\nJei viskas isvedama tvarkingai ir programa neuzstrigo, testas sekmingas\n";
    return 0;
}