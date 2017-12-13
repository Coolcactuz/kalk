#include <iostream>
#include "Raz.h"
using namespace std;


int main() {
    //cout << "Hello, World!" << endl;
    Raz a(5);
    Raz b(7,8);
    Raz c(1.66);
    //c.semplifica();
    cout<<c.getNum()<<"/"<<c.getDen()<<endl;
    cout<<double(c)<<endl;
    //cout<<c.getMCD(c.getNum(),c.getDen())<<endl;
    return 0;
}