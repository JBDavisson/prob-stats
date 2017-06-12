#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <cstdint>

template <typename T>
T factorial(T n)
{
	if(n < 0) { return 0; }
	if(n == 0 || n == 1)
	{
		return 1;
	}
	return n*factorial(n - 1);
}


/**
 * 	Name:			Non Replacement Descent
 * 	Purpose:		To compute appropriate products for the computation
 * 					of discrete probabilities for the case under which
 * 					'objects' are not replaced prior to subsequent choices.
 *	Method:			T nrDescent(T i, T c) 
 * 	Arguments:		i = initial value; c = how far down to count from i
 * 	Returns:		-5 if the count is greater than the initial value
 * 					Appropriate value otherwise
 * 
 **/
template <typename T>
T nrDescent(T i, T c)
{
	if((c >= i) || (i < 0 || c < 0)) { return (T)0; }
	T temp = i;
	int j = 0;
	while(j < c)
	{
		i -= 1;
		temp *= (T)i;
		j++;
	} 
	return (T)temp;
}
template <typename T>
T binomCoeff(T n, T k)
{
	if((k > n) || (n < 0 || k < 0)) { return 0; }
	T num = factorial<T>(n);
	T den = (factorial<T>(k)*factorial<T>(n-k));
	return (T)(num/den);
}

#endif
