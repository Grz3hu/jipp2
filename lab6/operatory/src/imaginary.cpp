#include <cmath>
#include <iostream>
#include "imaginary.h"
    
    void Imaginary::print() {
        std::cout << "x: " << x << " " << i  << "i" << std::endl;
    }
    
    Imaginary operator+(const Imaginary &lhs, const Imaginary &rhs){
        return Imaginary(lhs.x + rhs.x, lhs.i + rhs.i);
    }
    
    void operator+=(Imaginary &lhs, const Imaginary &rhs) {
        lhs.x = lhs.x + rhs.x;
        lhs.i = lhs.i + rhs.i;
    }

    Imaginary operator-(const Imaginary &lhs, const Imaginary &rhs) {
        return Imaginary(lhs.x - rhs.x, lhs.i - rhs.i);
    }

    Imaginary operator-(const Imaginary &rhs){
        return Imaginary(-rhs.x, -rhs.i);
    }
    
    void operator-=(Imaginary &lhs, const Imaginary &rhs) {
        lhs.x -= rhs.x;
        lhs.i -= rhs.i;
    }

    Imaginary operator*(const Imaginary &lhs, const Imaginary &rhs){
        Imaginary n;
        n.x=lhs.x*rhs.x - lhs.i*rhs.i;
        n.i=lhs.x*rhs.i - lhs.i*rhs.x;
        return n;
    }

    Imaginary operator*(const Imaginary &lhs, const double &rhs) {
        return Imaginary(lhs.x * rhs, lhs.i * rhs);
    }

    Imaginary operator*(const double &lhs , const Imaginary &rhs) {
        return Imaginary(rhs.x * lhs, rhs.i * lhs);
    }
    
    bool operator==(const Imaginary &lhs, const Imaginary &rhs){
        return (lhs.x==rhs.x && lhs.i==rhs.i);
    }