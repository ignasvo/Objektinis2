# Objektinis2 — Versija 1.1

## ✅ Pakeitimai nuo v1.0

- `struct Student` pakeistas į `class Studentas`
- Sukurtas `istream` konstruktorius ir `readStudent()` metodas
- Pridėtas `galutinisBalas()` getteris, kuris apskaičiuojamas klasės viduje
- Visos operacijos perkeltos prie klasės lygio (encapsulation)
- Palikta tik greičiausia strategija — `strategija3` (su `std::partition`)
- Naudojamas tik `std::vector<Studentas>` konteineris

---

## 🧪 Eksperimentinė analizė

### 🔹 Strategijų palyginimas (skirstymo laikas):

Testuota su 1 milijono studentų:

| Konteineris | Strategija1 | Strategija2 | Strategija3 |
|-------------|-------------|-------------|-------------|
| Vector      | 0.3004 s    | 0.2130 s    | **0.2053 s** |

> Todėl tolimesniems bandymams naudota tik `Strategija3`

---

### 🔹 Optimizavimo lygiai (Strategija3, Vector)

| Optimizavimas | 100k laikas | 1M laikas | .exe dydis |
|---------------|-------------|-----------|------------|
| `-O1`         | 0.0067 s    | 0.099 s   | 166 KB     |
| `-O2`         | 0.0066 s    | 0.081 s   | 164 KB     |
| `-O3`         | 0.0063 s    | 0.081 s   | 166 KB     |

---

## 📝 Išvados

- Strategija3 pasirodė greičiausiai iš visų, ypač su `std::vector`
- Optimizavimo lygiai `-O2` ir `-O3` davė pastebimai geresnį veikimo laiką nei neoptimizuotas kodas
- Galutinė realizacija yra stabili, greita ir tvarkinga pagal OOP principus

---
