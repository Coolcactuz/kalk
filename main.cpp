#include <iostream>
#include "Raz.h"
using namespace std;

int main() {
    //cout << "Hello, World!" << endl;
    Raz a(5);
    Raz b(5);
    Raz c(-254.55556);
    cout<<b.radice_cubica()<<endl;
    cout<<c.getNum()<<"/"<<c.getDen()<<endl;
    cout<<double(c)<<endl;
    //cout<<c.getMCD(c.getNum(),c.getDen())<<endl;
    return 0;
}