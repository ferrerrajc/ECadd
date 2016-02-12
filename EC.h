#ifndef EC_H
#define EC_H
/*******************************************************************************
 *
 *  EC.h
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

#include "rtl_point.h"
#include "boost/rational.hpp"

class EC {
    boost::rational<int> A, B;
  public:
    EC(boost::rational<int>, boost::rational<int>);
    boost::rational<int> getA();
    boost::rational<int> getB();
    void setA(boost::rational<int>);
    void setB(boost::rational<int>);
    bool on_curve(rtl_point);
    bool is_singular(boost::rational<int>, boost::rational<int>);
    rtl_point add_points(rtl_point, rtl_point);
};

std::ostream& operator<< (std::ostream& os, EC);

#endif
