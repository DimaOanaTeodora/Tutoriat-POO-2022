//
// Created by Oana on 23-May-22.
//

#ifndef COLOCVIU_IUNIE2022_CARDSUPRAFATA_H
#define COLOCVIU_IUNIE2022_CARDSUPRAFATA_H

class CardSuprafata : public Card {

public:
    CardSuprafata() {}

    CardSuprafata(const std::vector<Bilet *> &bilete) : Card(bilete) {}

    CardSuprafata(const CardSuprafata &ob) {
        this->bilete = ob.bilete;
    }

    CardSuprafata &operator=(const CardSuprafata &ob) {
        if (this == &ob)
            return *this;

        this->bilete = ob.bilete;
        return *this;
    }

    CardSuprafata &operator+(Bilet *biletNou) {
        this->bilete.push_back(biletNou);
        return *this;
    }

    ~CardSuprafata() {}

};

#endif //COLOCVIU_IUNIE2022_CARDSUPRAFATA_H
