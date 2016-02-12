/*******************************************************************************
 *
 *  EC.cpp
 *
 *  This file defines a class to represent elliptic curves with the 
 *  purpose of using the abelian group structure of an elliptic curve
 *  to find the sum of two points.
 *  Curves are given as being defined by a Weierstrass form
 *          y^2 = x^3 + Ax + B
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
#include <stdexcept>
#include "rtl_point.h"
#include "boost/rational.hpp"

using boost::rational;

class EC {
    rational<int> A, B;
  public:
    EC(rational<int>, rational<int>);
    rational<int> getA();
    rational<int> getB();
    void setA(rational<int>);
    void setB(rational<int>);
    bool on_curve(rtl_point);
    bool is_singular(rational<int>, rational<int>);
    rtl_point add_points(rtl_point, rtl_point);
};

rtl_point infinity(0, 1, 0);

std::ostream& operator<< (std::ostream& os, EC curve){
    os << "y^2 = x^3 + (";
    if(curve.getA().denominator() == 1){
        os << curve.getA().numerator();
    } else {
        os << curve.getA();
    }
    os << ")x + (";
    if(curve.getB().denominator() == 1){
        os << curve.getB().numerator();
    } else {
        os << curve.getB();
    }
    os << ")";
    return os;
}

EC::EC(rational<int> a, rational<int> b){
    if(EC::is_singular(a,b)){
        throw std::invalid_argument("Must be a nonsingular elliptic curve.");
    } else {
        A = a;
        B = b;
    }
}

rational<int> EC::getA(){
    return A;
}

rational<int> EC::getB(){
    return B;
}

void EC::setA(rational<int> a){
    A = a;
}

void EC::setB(rational<int> b){
    B = b;
}

bool EC::on_curve(rtl_point P){
    return (P.getY()*P.getY() == P.getX()*P.getX()*P.getX() + A*P.getX() + B ||
            P == infinity);
}

bool EC::is_singular(rational<int> a, rational<int> b){
    if(4*a*a*a + 27*b*b == 0){
        return 1;
    } 
    return 0;
}

rtl_point EC::add_points(rtl_point P1, rtl_point P2){

    rtl_point ret = infinity;
    rational<int> m(0);

    if(!EC::on_curve(P1) || !EC::on_curve(P1)){
        throw std::invalid_argument("Both points must be on the curve.");
    } else if(P1 == infinity){
        return P2;
    } else if(P2 == infinity){
        return P1;
    } else if(P1 == P2 && P1.getY() != 0){
        m = (3*P1.getX()*P1.getX() + A)/(2*P1.getY());
        ret.setZ(1);
        ret.setX(m*m - 2*P1.getX());
        ret.setY((-1)*m*(ret.getX() - P1.getX()) - P1.getY());
    } else if(P1.getX() != P2.getX()){
        m = (P2.getY() - P1.getY()) / (P2.getX() - P1.getX());
        ret.setZ(1);
        ret.setX(m*m - P1.getX() - P2.getX());
        ret.setY((-1)*m*(ret.getX() - P1.getX()) - P1.getY());
    }
    return ret;
}
