//
// Created by Oana on 09-Mar-22.
//

#ifndef TUTORIAT_POO_CLS1_H
#define TUTORIAT_POO_CLS1_H

class cls1 {
public:
    int vi;
    cls1(int v=30) {vi=v;}
    cls1(cls2 p) {vi=p.vi;}
};

#endif //TUTORIAT_POO_CLS1_H
