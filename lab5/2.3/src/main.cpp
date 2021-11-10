#include <iostream>
#include "auto.h"

using namespace std;

class TestClass
{
private:
    const int t = 0;

public:
    /* TestClass(const int t) { */
    /*     this->t = t; */
    /* } */
    TestClass(const int t) : t(t) {}

    void print() const
    {
        cout << t << endl;
    }
};

int main()
{
    const int k = 0;
    cout << k << endl;

    /* const int * k; */
    /* int *const k1; */

    int cVal = 314;
    int *const p = &cVal;

    *p = 628;

    const int cVal2 = 666;
    /* p = &cVal2; */

    const int *const youCantModifyMe = &cVal;

    /* int cVal = 314; */
    /* const int &k = cVal; */

    /* const int k1; //błąd kompilacji error: uninitialized const */
    /* k = 10;       //błąd kompilacji error: assignment of read-only variable */
    
    Auto auto1("SC5512", "Fiesta", 5, "Ford", "Osobowe");
    auto1.printSoft();
    auto1.updateSoft();
    auto1.printSoft();
    auto1.opublikujNoweOprogramowanie("v1.2");
    auto1.updateSoft();
    auto1.printSoft();

    return 0;
}