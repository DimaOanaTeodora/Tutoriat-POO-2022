//
// Created by Oana on 23-May-22.
//

#ifndef COLOCVIU_IUNIE2022_VALIDATOR_H
#define COLOCVIU_IUNIE2022_VALIDATOR_H

class Validator {
    std::string locatie;
    int nr_scanari;
    static int minut_curent;
    static int ora_curenta;
public:
    Validator() {
        this->nr_scanari = 0;
        this->minut_curent = 0;
        this->ora_curenta = 0;
    }

    Validator(const std::string &locatie, int minutCurent, int oraCurenta, int nrScanari = 0) : locatie(locatie){
        this -> minut_curent = minutCurent;
        this -> ora_curenta = oraCurenta;
    }

    int getMinutCurent() const {
        return minut_curent;
    }

    void setMinutCurent(int minutCurent) {
        minut_curent = minutCurent;
    }

    int getOraCurenta() const {
        return ora_curenta;
    }

    void setOraCurenta(int oraCurenta) {
        ora_curenta = oraCurenta;
    }

    Validator(const Validator &ob) {
        this->locatie = ob.locatie;
        this->nr_scanari = ob.nr_scanari;
        this-> minut_curent = ob.minut_curent;
        this -> ora_curenta = ob.ora_curenta;
    }

    Validator &operator=(const Validator &ob) {
        if (this == &ob)
            return *this;

        this->locatie = ob.locatie;
        this->nr_scanari = ob.nr_scanari;
        this-> minut_curent = ob.minut_curent;
        this -> ora_curenta = ob.ora_curenta;
        return *this;
    }

    ~Validator() {

    }

    const std::string &getLocatie() const {
        return locatie;
    }

    void setLocatie(const std::string &locatie) {
        Validator::locatie = locatie;
    }

    int getNrScanari() const {
        return nr_scanari;
    }

    void setNrScanari(int nrScanari) {
        nr_scanari = nrScanari;
    }

    std::string validare(Card *card) {
        this->nr_scanari++;
        CardTranzit *c = dynamic_cast<CardTranzit *>(card);
        if (c) {
            std::vector<Bilet *> bileteTranzit = c->getBilete();
            BiletTranzit *biletTranzit = dynamic_cast<BiletTranzit *> (bileteTranzit[0]);

            if (biletTranzit->verificareExpirare(ora_curenta, minut_curent)) {
                return "expirat";
            }

        }
        std::vector<Bilet *> bilete = card->getBilete();
        card -> folosireBilet(bilete[0], ora_curenta, minut_curent);
        return "calatorie validata cu succes";
    }

    static void modificareMinutCurent(int minut_curent) {
        minut_curent = minut_curent;
    }

    friend std::ostream &operator<<(std::ostream &out, Validator *validator);
};

int Validator::minut_curent = 0;
int Validator::ora_curenta = 0;
#endif //COLOCVIU_IUNIE2022_VALIDATOR_H
