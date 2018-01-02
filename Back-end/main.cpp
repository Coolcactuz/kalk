#include <iostream>
#include "Raz.h"
#include "C_cartesiano.h"


using namespace std;

int main() {
    C_cartesiano*a=new C_cartesiano(7,4);
    C_cartesiano*b=new C_cartesiano(7,4);
    C_cartesiano*c=new C_cartesiano(*(*a+*b));
    delete a;
    delete b;
    Complesso*d=c->converti();
    delete c;
    C_polare*f=new C_polare(5,-45);
    C_polare*g=new C_polare(*(*f-*d));
    cout<<*g<<endl;

    return 0;
}