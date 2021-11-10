#include <cmath>
#include <iostream>

class Vector {
private:
    double x, y;
    
public:
    Vector() {};
    
    Vector(double x, double y) : x(x), y(y) {}
    
    double length() {
        return sqrt(x * x + y * y);
    }
    
    void print() {
        std::cout << "x: " << x << " y: " << y << std::endl;
    }
    
    Vector operator+(const Vector &rhs) const {
        return {x + rhs.x, y + rhs.y};
    }
    
    Vector &operator+=(const Vector &rhs) {
        this->x = this->x + rhs.x;
        this->y = this->y + rhs.y;
        return *this;
    }

    Vector operator-(const Vector &rhs) const {
        return {x - rhs.x, y - rhs.y};
    }

    Vector operator-() const {
        return {-x, -y};
    }
    
    Vector &operator-=(const Vector &rhs) {
        this->x = this->x - rhs.x;
        this->y = this->y - rhs.y;
        return *this;
    }

    double operator*(const Vector &rhs) const {
        return (x * rhs.x) + (y * rhs.y);
    }

    Vector operator*(const double a) const {
        return {x*a, y*a};
    }
    
    bool operator==(const Vector &rhs) const {
        return (x==rhs.x && y==rhs.y);
    }
};