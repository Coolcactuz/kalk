#include <iostream>
#include "Raz.h"
#include "C_cartesiano.h"


using namespace std;

int main() {
    C_cartesiano*a=new C_cartesiano(7,4);
    C_cartesiano*b=new C_cartesiano(7,4);
    C_cartesiano*c=new C_cartesiano(*(*a+*b));
    cout<<*c<<endl;

    return 0;
}