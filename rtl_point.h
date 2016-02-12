#ifndef RTL_POINT_H
#define RTL_POINT_H
/*******************************************************************************
 *
 *  rtl_point.h
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

#include "boost/rational.hpp"

class rtl_point {
    boost::rational<int> x,y;
    bool z;
  public:
    rtl_point(boost::rational<int>, boost::rational<int>);
    rtl_point(boost::rational<int>, boost::rational<int>, bool);
    void setX(boost::rational<int>);
    void setY(boost::rational<int>);
    void setZ(bool);
    boost::rational<int> getX();
    boost::rational<int> getY();
    bool getZ();
    bool operator==(rtl_point&);
};

std::ostream& operator<< (std::ostream&, rtl_point);

#endif
