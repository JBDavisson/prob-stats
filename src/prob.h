/**
 * 	File:			prob.h
 *	Author:			Jacob B Davisson
 * 	Purpose:		Provides probability computing functionality
 *	Origination:	12 June 2017
 *	Last Modified:	08 July 2017
 *
 **/

#ifndef __PROB__H__
#define __PROB__H__

#include "utils.h"
#include <cmath>
#include <cstdio>

template <typename T = int, typename S = double>
S binomDist(T n, T k, S p)
{
	S q = (1 - p);
	T bin = binomCoeff(n, k);
	S temp = S();
	if(bin == 0 || q <= 0 || p <= 0 || p>=1)
	{
		temp = 0;
	}
	else
	{
		S success = std::pow(p, k);
		S failure = std::pow(q, (n-k));
		temp = bin*success*failure;
		/*printf("q: %f\n", q);
		printf("bin: %d\n", bin);
		printf("success: %f\n", success);
		printf("failure: %f\n", failure);
		printf("temp: %f\n", temp);*/
	}
	return temp;
}

template <typename T = int, typename S = double>
S poissonDist(S lambda, T x)
{
	S b = std::pow(lambda, x);
	T temp = factorial<T>(x);
	//printf("factorial<T>(x): %d\n", temp);
	S a = std::exp(-lambda);
	S p = (S)((a*b)/temp);
	//printf("a = %f\n", a);
	//printf("b = %f\n", b);
	return (S)p;
}

template <typename T = int, typename S = double>
S nrProbability(T n, T k, T t)
{
	S retVal = 0.0;
	T bin = binomCoeff(n, k);
	//printf("bin: %d\n", bin);
	if (bin <= retVal) { return retVal; }
	S num = nrDescent(t, k);
	S den = nrDescent(t, n);
	//printf("num = %f\n", num);
	//printf("den = %f\n", den);
	retVal = (bin*(num/den));
	return retVal;
}

template <typename T = int, typename S = double>
S geometricProb(T x, S p)
{
	if((x <= 0) || (p >= 1) || (p <= 0))
	{
		return (S)0;
	}
	S q = (1 - p);
	//S retVal = std::pow((1-p), (x-1))*(p);
	return (S)std::pow(q, (x-1))*(p);//retVal;
}

template <typename T = int, typename S = double>
S negBinomial(T n, T x, S p)
{
	if((x > n) || (p >= 1) || (p <= 0))
	{
		return (S)0;
	}
	S q = (1 - p);
	T a = (n - 1);
	T b = (x - 1);
	T coeff = binomCoeff(a, b);
	S temp = std::pow(p, b)*std::pow(q, (a-b));
	S retVal = coeff*temp;
	return retVal;
}

#endif
