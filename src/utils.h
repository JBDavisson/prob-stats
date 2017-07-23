/**
 * 	File:			utils.h
 *	Author:			Jacob B Davisson
 * 	Purpose:		Provides functionalities needed for computing probailities
 *	Origination:	12 June 2017
 *	Last Modified:	08 July 2017
 *
 **/
 
#include <cstdint>
#include "mathTypes.h"

#ifndef __UTILS_HPP__
#define __UTILS_HPP__


/**
 * 	Name:			Factorial
 * 	Purpose:		To recursively compute the factorial for the integer
 * 					value passed in as a parameter: n.
 *	Method:			T factorial(T n)
 * 	Arguments:		n = value to compute factorial for.
 * 	Returns:		0 if n < 0
 *
 **/
template <typename T = int>
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
 * 	Returns:		0 if the count is greater than the initial value
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

/**
 * 	Name:			Binomial Coefficient
 * 	Purpose:		To compute appropriate binomial coefficients for
 *					values entered as arguments.
 *	Method:			T binomCoeff(T n, T k)
 * 	Arguments:		n = Top Value; k = Bottom value
 * 	Returns:		0 if the count is greater than the initial value
 * 					Appropriate value otherwise
 *
 **/
template <typename T>
T binomCoeff(T n, T k)
{
	if((k > n) || (n < 0 || k < 0)) { return 0; }
	T num = factorial<T>(n);
	T den = (factorial<T>(k)*factorial<T>(n-k));
	return (T)(num/den);
}

#endif
