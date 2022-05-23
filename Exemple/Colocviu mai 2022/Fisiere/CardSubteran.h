//
// Created by Oana on 23-May-22.
//

#ifndef COLOCVIU_IUNIE2022_CARDSUBTERAN_H
#define COLOCVIU_IUNIE2022_CARDSUBTERAN_H

class CardSubteran : public Card {

public:
    CardSubteran() {}

    CardSubteran(const std::vector<Bilet *> &bilete) : Card(bilete) {}

    CardSubteran(const CardSubteran &ob) {
        this->bilete = ob.bilete;
    }

    CardSubteran &operator=(const CardSubteran &ob) {
        if (this == &ob)
            return *this;

        this->bilete = ob.bilete;
        return *this;
    }

    ~CardSubteran() {}

};

#endif //COLOCVIU_IUNIE2022_CARDSUBTERAN_H
