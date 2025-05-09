#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>


/**
 * @class Zmogus
 * @brief Abstrakti bazinė klasė, aprašanti bendrus žmogaus bruožus.
 */

class Zmogus {
protected:
    std::string vardas_; ///< Žmogaus vardas
    std::string pavarde_; ///< Žmogaus pavardė

public:

    /// Default konstruktorius
    Zmogus() = default;

    /**
     * @brief Pilnas konstruktorius.
     * @param vardas Vardas
     * @param pavarde Pavardė
     */

    Zmogus(const std::string& vardas, const std::string& pavarde)
        : vardas_(vardas), pavarde_(pavarde) {}


    /// Destruktorius (virtualus)
    virtual ~Zmogus() = default;

    /**
     * @brief Getteris vardui
     * @return vardas kaip string
     */
    std::string vardas() const { return vardas_; }

    /**
     * @brief Getteris pavardei
     * @return pavarde kaip string
     */
    std::string pavarde() const { return pavarde_; }

    void setVardas(const std::string& vardas) { vardas_ = vardas; }
    void setPavarde(const std::string& pavarde) { pavarde_ = pavarde; }

    /**
     * @brief Virtuali spausdinimo funkcija (abstrakti).
     */
    virtual std::ostream& spausdinti(std::ostream& os) const = 0;
};

#endif // ZMOGUS_H