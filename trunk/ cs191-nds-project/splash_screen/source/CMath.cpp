#include "CMath.h"


/* function gcd (greatest common divisor)
 * Does a simple for loop starting at the lowest of the two inputs and goes down.
 * Once both inputs are divided by the common divisble, it returns the number.
 * By default, if no GCD is found, 1 is returned (all numbers can be divided by 1)
 * */
int CMath::gcd(int a, int b)
{
	if(a < b)
	{
		int swap = a;
		a = b;
		b = swap;
	}
	
	for(int i = b; i > 0; i--)
	{
		if( (a%i == 0) && (b%i == 0) )
			return i;
	}
	return 1;
}
