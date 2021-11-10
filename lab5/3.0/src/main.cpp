#include "vector.cpp"
#include <iostream>

using namespace std;

int main(){
    Vector v1(1,1), v2(5,10);
    Vector v3 = v1 + v2;
    v3.print();
    Vector v4 = v1 - v2;
    v4.print();
    Vector v5 = -v1;
    v5.print();
    
    cout << (-v1==v5) << endl;
    cout << (v1*v2) << endl;
    (v1*2.0).print(); 

    return 0;
}