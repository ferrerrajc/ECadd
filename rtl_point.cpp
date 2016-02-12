/*******************************************************************************
 *
 *  rtl_point.cpp
 *
 *  This file defines a class to represent points in P^2(Q) of the form
 *  [x:y:1] or [x:y:0]. For points of the latter form, the program currently
 *  does not enforce the condition that x or y must be nonzero.
 *
 *  This has been written as part of an assignment for MATH 788 Spring 2016
 *  at the University of South Carolina
 *
 *  Author: Josh Ferrerra
 *  Email: joshua.ferrerra@gmail.com
 *  Date Created: 10 Feb, 2016
 *
 *  Last Modified: 12 Feb, 2016
 *  By: Josh Ferrerra
 *
 ******************************************************************************/
#include <iostream>
#include "boost/rational.hpp"

using boost::rational;

class rtl_point {
    rational<int> x,y;
    bool z;
  public:
    rtl_point(rational<int>, rational<int>);
    rtl_point(rational<int>, rational<int>, bool);
    void setX(rational<int>);
    void setY(rational<int>);
    void setZ(bool);
    rational<int> getX();
    rational<int> getY();
    bool getZ();
    bool operator==(rtl_point&);
};

std::ostream& operator<< (std::ostream& os, rtl_point P){
    os << "[ ";
    if(P.getX().denominator() == 1){
        os << P.getX().numerator();
    } else {
        os << P.getX();
    }
    os << " : ";
    if(P.getY().denominator() == 1){
        os << P.getY().numerator();
    } else {
        os << P.getY();
    }
    os << " : " << P.getZ() << " ]";
    return os;
}

rtl_point::rtl_point(rational<int> X, rational<int> Y){
    x = X;
    y = Y;
    z = 1;
}

rtl_point::rtl_point(rational<int> X, rational<int> Y, bool Z){
    x = X;
    y = Y;
    z = Z;
}

void rtl_point::setX(rational<int> X){
    x = X;
}

void rtl_point::setY(rational<int> Y){
    y = Y;
}

void rtl_point::setZ(bool Z){
    z = Z;
}

rational<int> rtl_point::getX(){
    return x;
}

rational<int> rtl_point::getY(){
    return y;
}

bool rtl_point::getZ(){
    return z;
}

bool rtl_point::operator==(rtl_point& right){
    return (x == right.getX() &&
            y == right.getY() &&
            z == right.getZ());
}
