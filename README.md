## Versija v1.2 – Rule of Five ir įvesties/išvesties palaikymas

Šioje versijoje `Studentas` klasė praplėsta įgyvendinant visus 5 specialiuosius metodus pagal „Rule of Five“ principą:

- Kopijavimo konstruktorius
- Perkėlimo konstruktorius
- Kopijavimo priskyrimo operatorius
- Perkėlimo priskyrimo operatorius
- Destruktorius

Taip pat sukurti ir perdengti srautų operatoriai `>>` ir `<<`, leidžiantys patogiai naudoti objektus su `cin`, `cout`, `ifstream` ir `ofstream`.

---


### Įvestis ir išvestis

- Duomenis galima įvesti ranka per terminalą arba nuskaitant iš failo, pvz.:
  ```
  Jonas Jonaitis 10 9 8 7
  ```
- Išvestis atliekama per `operator<<` – išvedami vardas, pavardė ir galutinis balas:
  ```
  Jonas          Jonaitis       8.40
  ```

---

### Testavimas

Sukurtas testavimo failas `testas.cpp`, kuris patikrina visų metodų veikimą:  
kopijavimą, perkėlimą, įvestį/išvestį.  
Jei testas išsiveda be klaidų – visi metodai veikia teisingai.

![image](https://github.com/user-attachments/assets/819ffdc5-ddf9-49f4-b623-40cfb9bda8b4)
