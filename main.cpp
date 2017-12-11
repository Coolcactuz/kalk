#include <iostream>

#include "Raz.h"
using namespace std;

int main() {
    //cout << "Hello, World!" << endl;
    Raz a(5);
    Raz b(3,8);
    Raz c((a+b)^(-2));
    cout<<c.getNum()<<"/"<<c.getDen()<<endl;
    cout<<c.converti();

    return 0;
}