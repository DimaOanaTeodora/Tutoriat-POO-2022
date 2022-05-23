//
// Created by Oana on 23-May-22.
//

#ifndef COLOCVIU_IUNIE2022_BILET_H
#define COLOCVIU_IUNIE2022_BILET_H

class Bilet {
protected:
    float taxa;
    std::vector<char> tip_transport;
public:
    Bilet() {}

    Bilet(float taxa, const std::vector<char> &tipTransport) : taxa(taxa), tip_transport(tipTransport) {}

    Bilet(const Bilet &ob) {
        this->taxa = ob.taxa;
        this->tip_transport = ob.tip_transport;
    }

    float getTaxa() const {
        return taxa;
    }

    void setTaxa(float taxa) {
        Bilet::taxa = taxa;
    }

    const std::vector<char> &getTipTransport() const {
        return tip_transport;
    }

    void setTipTransport(const std::vector<char> &tipTransport) {
        tip_transport = tipTransport;
    }

    Bilet &operator=(const Bilet &ob) {
        if (this == &ob)
            return *this;

        this->taxa = ob.taxa;
        this->tip_transport = ob.tip_transport;
        return *this;
    }

    bool operator==(const Bilet &rhs) const {
        return taxa == rhs.taxa &&
               tip_transport == rhs.tip_transport;
    }

    bool operator!=(const Bilet &rhs) const {
        return !(rhs == *this);
    }

    virtual ~Bilet() {}

};

#endif //COLOCVIU_IUNIE2022_BILET_H
