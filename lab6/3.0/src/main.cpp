#include "vector.h"
#include "imaginary.h"
#include "triangle.h"
#include <iostream>

using namespace std;

int main()
{
    /* Vector v1(1,1), v2(5,10); */
    /* Vector v3 = v1 + v2; */
    /* v3.print(); */
    /* Vector v4 = v1 - v2; */
    /* v4.print(); */
    /* Vector v5 = -v1; */
    /* v5.print(); */

    /* cout << (-v1==v5) << endl; */
    /* cout << (v1*v2) << endl; */
    /* cout << (v2*v1) << endl; */
    /* (v1*2.0).print(); */
    /* (2.0*v1).print(); */

    /* cout << "\n\n" << v1 << endl; */

    /* Imaginary a(1,-2); */
    /* a.print(); */

    Triangle t1(Node(0, 0), Node(0, 2), Node(1, 0), "First Triangle");
    t1.display();
    cout << endl
         << t1;
    cout << "Distance between first and second point is " << t1.distance(0, 1) << endl;

    return 0;
}