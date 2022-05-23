//
// Created by Oana on 23-May-22.
//

#ifndef COLOCVIU_IUNIE2022_BILETSUPRAFATA_H
#define COLOCVIU_IUNIE2022_BILETSUPRAFATA_H

class BiletSuprafata : public Bilet {
public:
    BiletSuprafata() {
        this->taxa = 2.0;
        this->tip_transport.push_back('T');
        this->tip_transport.push_back('A');
    }

    BiletSuprafata &operator=(const BiletSuprafata &ob) {
        if (this == &ob)
            return *this;

        this->taxa = ob.taxa;
        this->tip_transport = ob.tip_transport;
        return *this;
    }

    BiletSuprafata(const BiletSuprafata &ob) {
        this->taxa = ob.taxa;
        this->tip_transport = ob.tip_transport;
    }

    ~BiletSuprafata() {

    }
};

#endif //COLOCVIU_IUNIE2022_BILETSUPRAFATA_H
