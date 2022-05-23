//
// Created by Oana on 23-May-22.
//

#ifndef COLOCVIU_IUNIE2022_CARD_H
#define COLOCVIU_IUNIE2022_CARD_H

class Card {
protected:
    std::vector<Bilet *> bilete;
    Bilet *ultimulBiletFolosit;
    int ora_validare;
    int minut_validare;
public:
    Card() {
        this->ultimulBiletFolosit = nullptr;
        ora_validare = 0;
        minut_validare = 0;
    }

    Card(const std::vector<Bilet *> &bilete) : bilete(bilete) {
        this->ultimulBiletFolosit = nullptr;
        ora_validare = 0;
        minut_validare = 0;
    }

    Card(const Card &ob) {
        this->bilete = ob.bilete;
        this-> ora_validare = ob.ora_validare;
        this -> minut_validare = ob.minut_validare;
    }

    std::vector<Bilet *> getBilete() const {
        return bilete;
    }

    Card &operator=(const Card &ob) {
        if (this == &ob)
            return *this;

        this->bilete = ob.bilete;
        this-> ora_validare = ob.ora_validare;
        this -> minut_validare = ob.minut_validare;
        return *this;
    }

    virtual ~Card() {
        delete ultimulBiletFolosit;
    }

    void setBilete(const std::vector<Bilet *> &bilete) {
        Card::bilete = bilete;
    }

    Bilet *getUltimulBiletFolosit() const {
        return ultimulBiletFolosit;
    }

    void setUltimulBiletFolosit(Bilet *ultimulBiletFolosit) {
        Card::ultimulBiletFolosit = ultimulBiletFolosit;
    }

    int getOraValidare() const {
        return ora_validare;
    }

    void setOraValidare(int oraValidare) {
        ora_validare = oraValidare;
    }

    int getMinutValidare() const {
        return minut_validare;
    }

    void setMinutValidare(int minutValidare) {
        minut_validare = minutValidare;
    }

    float sumaBileteNeutilizate() {
        float sum = 0;
        for (int i = 0; i < bilete.size(); i++) {
            if (bilete[i] != ultimulBiletFolosit) {
                sum += bilete[i]->getTaxa();
            }
        }
        return sum;
    }

    void folosireBilet(Bilet *bilet, int ora, int minut) {
        if (ultimulBiletFolosit != nullptr) {
            this->bilete.pop_back();
        }
        this->ultimulBiletFolosit = bilet;
        this->ora_validare = ora;
        this->minut_validare = minut;
    }

    friend std::ostream &operator<<(std::ostream &out, Card *card);

};

#endif //COLOCVIU_IUNIE2022_CARD_H
