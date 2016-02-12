#include <iostream>
#include <stdexcept>
#include "rtl_point.h"
#include "EC.h"
#include "boost/rational.hpp"

using std::cout;        using std::endl;
using boost::rational;

int main(){

    rational<int> A(-7);
    rational<int> B(15);

    rational<int> x1(1);
    rational<int> y1(3);
    rtl_point P1(x1, y1);

    rational<int> x2(2);
    rational<int> y2(3);
    rtl_point P2(x2, y2);

    rtl_point O(0,1,0);
    
    try{ 
        EC curve(A,B);
        cout << "On the curve " << curve << endl;
        cout << P1 << " + " << P2 << " = " << curve.add_points(P1,P2) << endl;
        cout << P1 << " + " << P1 << " = " << curve.add_points(P1,P1) << endl;
        cout << P1 << " + " << O << " = " << curve.add_points(P1,O) << endl;
    } catch(std::invalid_argument e) {
        cout << "Error: " << e.what();
    }

    return 0;
}
