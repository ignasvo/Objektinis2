# Studentų apdorojimo sistema 2.0

Ši programa skirta apdoroti studentų duomenis: skaičiuoti galutinį pažymį pagal namų darbus ir egzaminą, rikiuoti, filtruoti bei dirbti su įvairiomis strategijomis.

Projektas išskaidytas į kelias versijas, palaikantis modernius OOP principus, unit testavimą bei dokumentaciją su Doxygen.

---

## Versijos

### v1.0
- Naudojama `struct Student`
- Bazinė logika: skaitymas, skaičiavimai, spausdinimas

### v1.1
- `struct` pakeistas į `class Studentas`
- Įgyvendinti getteriai, setteriai, konstruktoriai

### v1.2
- Pilnai realizuota **Rule of Five**:
  - kopijavimo/perkėlimo konstruktoriai ir operatoriai
  - destruktorius
- Įvesties/išvesties operatoriai

### v1.5
- Sukurta abstrakti bazinė klasė `Zmogus`
- `Studentas` paveldi iš `Zmogus`
- Naudojamas polimorfizmas (virtuali funkcija `spausdinti`)

### v2.0
- Sukurti unit testai su [doctest](https://github.com/doctest/doctest)
- Sugeneruota Doxygen dokumentacija (HTML ir PDF)
- Naudojamas `Makefile` projekto valdymui
- README papildytas instrukcijomis ir rezultatais

---

## Diegimo instrukcija

### Reikalavimai:
- MinGW arba GCC
- `mingw32-make`
- Papildomai testams: `doctest.h` (yra `tests/` aplanke)

---

## Naudojimas

### Paleisti programą:
```bash
mingw32-make run
```
### Paleisti testus:
```bash
mingw32-make tests
```

## Unit testai

Testai išdėstyti failuose:

- `tests/RO5testas.cpp` – testuoja **Rule of Five** metodus
- `tests/PapildomiTestai.cpp` – testuoja **loginę funkcijų veikimą**

Testuojami metodai:

- ✅ Kopijavimo konstruktorius
- ✅ Perkėlimo konstruktorius
- ✅ Kopijavimo priskyrimo operatorius
- ✅ Perkėlimo priskyrimo operatorius
- ✅ Galutinio balo skaičiavimas (vidurkis ir mediana)
- ✅ Įvestis per `read()` funkciją

---

## Dokumentacija

Doxygen dokumentacija yra sugeneruota ir prieinama:

- `docs/html/index.html` – HTML versija
- `docs/latex/refman.pdf` – PDF versija (kompiliuota per Overleaf)
