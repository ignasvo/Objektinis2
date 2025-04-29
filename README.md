## v1.1 - "Class" ir "Struct" našumo palyginimas naudojant vektorių ir 3 strategiją

Šioje versijoje atliktas struktūros (`struct`) ir klasės (`class`) taikymo efektyvumo palyginimas apdorojant studentų duomenis. Tyrimo metu buvo naudojamas tik `std::vector` konteineris ir 3-ioji skaidymo strategija, paremta `std::stable_partition`, kaip greičiausia bei atminties požiūriu efektyviausia.

Testai vykdyti su dviem studentų kiekiais (100 000 ir 1 000 000), su skirtingomis optimizavimo vėliavomis, matuojant:
- programos veikimo laiką,
- vykdomojo `.exe` failo dydį.

Tikslas — įvertinti, ar perėjimas nuo struktūros prie klasės daro įtaką veikimui bei kompiliuojamo kodo apimčiai.

### "Class" ir "Struct" tyrimo rezultatai

| Programos veikimo laikas su CLASS | Programos veikimo laikas su STRUCT | Studentų kiekis | Optimizavimo vėliava | .exe failo dydis su CLASS (KB) | .exe failo dydis su STRUCT (KB) |
|:----------------------------------|:-----------------------------------|:-------------------|:-------------------------|:-----------------------------|:------------------------------|
|               0.27                |                0.21               | 100 000             | -O3                      |            252               |              259              |
|               0.24                |                0.18               | 100 000             | -O2                      |            253               |              254              |
|               0.28                |                0.18               | 100 000             | -O1                      |            285               |              275              |
|               0.53                |                0.43               | 100 000             | -                        |            564               |              468              |
|               2.41                |                2.32               | 1 000 000           | -O3                      |            252               |              259              |
|               2.28                |                2.13               | 1 000 000           | -O2                      |            253               |              254              |
|               2.55                |                2.41               | 1 000 000           | -O1                      |            285               |              275              |
|               5.77                |                4.70               | 1 000 000           | -                        |            564               |              468              |

### Išvados

Remiantis atliktu tyrimu, kuriame naudotas `std::vector` konteineris bei 3-ioji (partition) skaidymo strategija, galima teigti:

- `struct` pagrindu veikianti versija dažniausiai veikia kiek greičiau nei `class`.
- Tarp `class` ir `struct` versijų .exe failo dydis skiriasi nežymiai, tačiau optimizavimo vėliavos (`-O1`, `-O2`, `-O3`) daro ženklią įtaką tiek laikui, tiek failo dydžiui.
