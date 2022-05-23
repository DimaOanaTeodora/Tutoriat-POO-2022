//
// Created by Oana on 23-May-22.
//

#ifndef COLOCVIU_IUNIE2022_BILETMETROU_H
#define COLOCVIU_IUNIE2022_BILETMETROU_H

class BiletMetrou : public Bilet {
public:
    BiletMetrou() {
        this->taxa = 2.5;
        this->tip_transport.push_back('M');
    }

    BiletMetrou(const BiletMetrou &ob) {
        this->taxa = ob.taxa;
        this->tip_transport = ob.tip_transport;
    }

    BiletMetrou &operator=(const BiletMetrou &ob) {
        if (this == &ob)
            return *this;

        this->taxa = ob.taxa;
        this->tip_transport = ob.tip_transport;
        return *this;
    }


    ~BiletMetrou() {

    }

};

#endif //COLOCVIU_IUNIE2022_BILETMETROU_H
