#include "node.h"

double Node::getX() const{
    return x;
}

double Node::getY() const{
    return y;
}

void Node::setX(const double &x){
    this->x=x;
}

void Node::setY(const double &y){
    this->y=y;
}

std::ostream &operator<<(std::ostream &lhs, const Node &rhs){
    std::cout << "x:" << rhs.x << " y:" << rhs.y << std::endl;
}