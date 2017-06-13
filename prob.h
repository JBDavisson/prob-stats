#ifndef __PROB__H__
#define __PROB__H__

#include "utils.h"

#include <cmath>
#include <cstdio>


template <typename T = int, typename S = double>
S binomialDist(T n, T k, S c)
{
	T bin = binomCoeff(n, k);
	return T();

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


#endif
