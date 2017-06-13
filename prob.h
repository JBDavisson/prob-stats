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
	if(bin == 0 || q <= 0) 
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

#endif
