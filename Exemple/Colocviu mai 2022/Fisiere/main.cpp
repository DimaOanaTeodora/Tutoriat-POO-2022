/*
 * Incercare de rezolvare in 90 min a subiectelor din mai 2022
 * Are buguri si lipsuri
 * Rezolvare orientativa => se putea aborda in mai multe feluri
 * Nu este rezolvare de nota 10 (probabil, cred, ar fi trebuit sa fie folosite toate conceptele de POO - putin cam greu in 90 min)
 * Este rezolvare de nota 5? Eu zic ca da, chiar peste maybe e de un 7-8
 * Compileaza? Da
 * */
#include <iostream>
#include <string>
#include <vector>
#include "Bilet.h"
#include "BiletSuprafata.h"
#include "BiletMetrou.h"
#include "BiletTranzit.h"
#include "Card.h"
#include "CardSuprafata.h"
#include "CardSubteran.h"
#include "CardTranzit.h"
#include "Validator.h"

using namespace std;

std::ostream &operator<<(std::ostream &out, Card *card) {
    out << " Afisare card ";
    if (dynamic_cast<CardSubteran *>(card)) {
        out << " subteran" << endl;
    } else if (dynamic_cast<CardSuprafata *>(card)) {
        out << " suprafata" << endl;
    } else {
        out << " tranzit" << endl;
    }
    out << "Minutul de validare: " << card->getMinutValidare() << endl << "Ora de validare " << card->getOraValidare()
        << endl;
    out << "Suma totala " << card->sumaBileteNeutilizate() << " lei" << endl;
    // ??
    return out;
}

std::ostream &operator<<(std::ostream &out, Validator *validator) {
    out << " Afisare validator " << endl;
    out << "Nr scanari " << validator->getNrScanari() << endl;
    out << " Locatie " << validator->getLocatie() << endl;
    return out;
}


int main() {

    // ilustrare cu demo cerinta: crearea unui card
    BiletMetrou *biletMetrou = new BiletMetrou();
    vector<Bilet *> bilete;
    bilete.push_back(biletMetrou);
    CardSubteran *cardSubteran = new CardSubteran(bilete);

    // ilustrarea cu demo cerinta: crearea unui aparat de validare
    Validator *validator = new Validator("subterana", 10, 23);

    // ilustrarea cu demo cerinta: adaugare bilet la un card
    BiletSuprafata *biletSuprafata = new BiletSuprafata();
    CardSuprafata *cardSuprafata = new CardSuprafata();
    (*cardSuprafata) = (*cardSuprafata) + biletSuprafata;

    // ilustrarea cu demo cerinta: validarea unui card
    BiletTranzit *biletTranzit = new BiletTranzit(10, 40);
    vector<Bilet *> bileteTranzit;
    bileteTranzit.push_back(biletTranzit);
    CardTranzit *cardTranzit = new CardTranzit(bileteTranzit);
    cout << validator->validare(cardTranzit) << endl;

    // ilustrarea cu demo cerinta: modificarea minutului curent
    Validator::modificareMinutCurent(10);

    // ilustrarea cu demo cerinta: afisarea detaliilor unui card
    cout << cardTranzit;

    // ilustrarea cu demo cerinta: afisarea detaliilor unui aparat
    cout << validator;
}