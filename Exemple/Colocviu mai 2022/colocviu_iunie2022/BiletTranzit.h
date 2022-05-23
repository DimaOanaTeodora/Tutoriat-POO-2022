//
// Created by Oana on 23-May-22.
//

#ifndef COLOCVIU_IUNIE2022_BILETTRANZIT_H
#define COLOCVIU_IUNIE2022_BILETTRANZIT_H

class BiletTranzit : public Bilet {
    int ora;
    int minutul;
public:
    BiletTranzit(int ora, int minutul) {
        this->taxa = 3.0;
        this->tip_transport.push_back('T');
        this->tip_transport.push_back('A');
        this->tip_transport.push_back('M');
        this->ora = ora;
        this->minutul = minutul;
    }

    BiletTranzit(const BiletTranzit &ob) {
        this->taxa = ob.taxa;
        this->tip_transport = ob.tip_transport;
        this->ora = ob.ora;
        this->minutul = ob.minutul;
    }

    bool verificareExpirare(int ora_curenta, int minutul_curent) {
        if (ora_curenta * 60 + minutul_curent - this->ora * 60 + this->minutul > 90) {
            return true;
        }
        return false;
    }

    int getOra() const {
        return ora;
    }

    void setOra(int ora) {
        BiletTranzit::ora = ora;
    }

    int getMinutul() const {
        return minutul;
    }

    void setMinutul(int minutul) {
        BiletTranzit::minutul = minutul;
    }

    BiletTranzit &operator=(const BiletTranzit &ob) {
        if (this == &ob)
            return *this;

        this->taxa = ob.taxa;
        this->tip_transport = ob.tip_transport;
        this->ora = ob.ora;
        this->minutul = ob.minutul;
        return *this;
    }

    ~BiletTranzit() {

    }
};

#endif //COLOCVIU_IUNIE2022_BILETTRANZIT_H
