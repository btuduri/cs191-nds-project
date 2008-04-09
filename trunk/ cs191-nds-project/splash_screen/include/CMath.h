#ifndef CMATH_H_
#define CMATH_H_

#include "ProjectLib.h"

#define PI (3.14159265358979323846264338327)

//usage:  MathVector2D<var_type> var_name;
template <class T>
struct MathVector2D {
    T x;
    T y;
};

class CMath
{
public:
	CMath();
	virtual ~CMath();

	int gcd(int a, int b);

};

#endif /*CMATH_H_*/
