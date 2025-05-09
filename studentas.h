#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <ostream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include "zmogus.h"


/**
 * @class Studentas
 * @brief Klasė, paveldinti Zmogus. Laiko studento pažymius ir skaičiuoja galutinį balą.
 */

class Studentas : public Zmogus {
private:
    std::vector<int> nd_; ///< Namų darbų pažymiai
    int egzaminas_; ///< Egzamino pažymys
    double galutinis_; ///< Galutinis balas

public:
    /// Default konstruktorius
    Studentas();

    /**
     * @brief Pilnas konstruktorius
     * @param vardas Studento vardas
     * @param pavarde Studento pavardė
     * @param nd Namų darbų pažymiai
     * @param egzaminas Egzamino rezultatas
     */
    Studentas(const std::string& vardas, const std::string& pavarde, const std::vector<int>& nd, int egzaminas);
    
    /// Copy konstruktorius
    Studentas(const Studentas& other);

    /// Move konstruktorius
    Studentas(Studentas&& other) noexcept;

    /// Destruktorius
    ~Studentas();

    /// Copy priskyrimo operatorius
    Studentas& operator=(const Studentas& other);

    /// Move priskyrimo operatorius
    Studentas& operator=(Studentas&& other) noexcept;


    /**
     * @brief Getteris egzamino pažymiui
     * @return egzamino pažymys
     */
    int egzaminas() const;
    /**
     * @brief Getteris galutiniam balui
     * @return galutinis balas
     */
    double galutinis() const;

    /**
     * @brief Getteris namų darbų pažymiams
     * @return pažymių vektorius
     */
    const std::vector<int>& nd() const;

    /// Setteris egzamino balui
    void setEgzaminas(int egzaminas);

    /// Prideda naują ND
    void pridetiND(int pazymys);

  /**
     * @brief Generuoja atsitiktinius pažymius
     * @param kiek Kiek pažymių generuoti
     */
    void generuotiPazymius(int kiek);

    /**
     * @brief Apskaičiuoja galutinį balą
     * @param metodas 'v' – vidurkis, 'm' – mediana
     */
    void skaiciuotiGalutini(char metodas);

    /**
     * @brief Nuskaitymas iš srauto
     * @param is Įvesties srautas
     * @return tas pats srautas
     */
    std::istream& read(std::istream& is);

    /**
     * @brief Realizuoja abstrakčią spausdinimo funkciją
     */
    std::ostream& spausdinti(std::ostream& os) const override;

    /// Output operatorius
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s);

    /// Input operatorius
    friend std::istream& operator>>(std::istream& is, Studentas& s);
};

/// Rikiavimo pagal vardą funkcija
bool compareVardas(const Studentas& a, const Studentas& b);

/// Rikiavimo pagal pavardę funkcija
bool comparePavarde(const Studentas& a, const Studentas& b);

/// Rikiavimo pagal galutinį balą funkcija
bool compareGalutinis(const Studentas& a, const Studentas& b);

#endif // STUDENTAS_H