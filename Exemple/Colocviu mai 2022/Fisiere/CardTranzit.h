//
// Created by Oana on 23-May-22.
//

#ifndef COLOCVIU_IUNIE2022_CARDTRANZIT_H
#define COLOCVIU_IUNIE2022_CARDTRANZIT_H

class CardTranzit : public Card {

public:
    CardTranzit() {}

    CardTranzit(const std::vector<Bilet *> &bilete) : Card(bilete) {}

    CardTranzit(const CardTranzit &ob) {
        this->bilete = ob.bilete;
    }

    CardTranzit &operator=(const CardTranzit &ob) {
        if (this == &ob)
            return *this;

        this->bilete = ob.bilete;
        return *this;
    }

    ~CardTranzit() {}

};

#endif //COLOCVIU_IUNIE2022_CARDTRANZIT_H
