#include <iostream>
// conteaza si ordinea in care includeti
#include "cls2.h"
#include "cls1.h"
using namespace std;

class cls1;

cls1 f(cls1 p) {
    p.vi++;
    return p;
}
int main()
{
    cls1 p;
    f(p);
    cout << endl << p.vi;
    cls2 r;
    f(r);
    cout << endl << r.vi;
    return 0;
}