# Elliptic Curve Addition
##

In the test file, I define an elliptic curve and two points, then find various sums.
```
    rational<int> A(-7);
    rational<int> B(15);

    rational<int> x1(1);
    rational<int> y1(3);
    rtl_point P1(x1, y1);

    rational<int> x2(2);
    rational<int> y2(3);
    rtl_point P2(x2, y2);

    rtl_point O(0,1,0);
```
```
    EC curve(A,B);
    cout << "On the curve " << curve << endl;
    cout << P1 << " + " << P2 << " = " << curve.add_points(P1,P2) << endl;
    cout << P1 << " + " << P1 << " = " << curve.add_points(P1,P1) << endl;
    cout << P1 << " + " << O << " = " << curve.add_points(P1,O) << endl;
```
Below is the output of the program.
```
On the curve y^2 = x^3 + (-7)x + (15)
[ 1 : 3 : 1 ] + [ 2 : 3 : 1 ] = [ -3 : -3 : 1 ]
[ 1 : 3 : 1 ] + [ 1 : 3 : 1 ] = [ -14/9 : -127/27 : 1 ]
[ 1 : 3 : 1 ] + [ 0 : 1 : 0 ] = [ 1 : 3 : 1 ]
```

Compare to the output from sage.
```
R.<x,y> = QQ[]
A = -7
B = 15
E = EllipticCurve(-y^2 + x^3 + A*x + B)
P1 = E(1,3)
P2 = E(2,3)

P1 + P2
    (-3 : -3 : 1)
P1 + P2
    (-14/9 : -127/27 : 1)
```

# Required Library
##

This program uses the rational number header file from the Boost C++ library which can be found at http://www.boost.org/

# Problems
##

> - The rational numbers overflow easily. With the arithmetic used, the size of the integers in the 
numerator and denominator grow quickly.
> - It is almost certain that the arithmetic used in the addition is not the optimal way to write it.

