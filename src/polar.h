/**
 *	File:			polar.h
 *	Author:			Jacob B Davisson
 *	Class:			Polar
 *	Purpose:		Header file for class providing implementation of Complex number
 *					in Polar form.
 *	Origination:	22 July 2017
 *	Last Modified:	22 July 2017
 *
 */

#include <cmath>

#ifndef __POLAR__H__
#define __POLAR__H__

static const char* unicodeAngle = "\u2220";
typedef double_t Magnitude;
typedef double_t Phase;

template <typename T = double>
class Polar
{
	private:
		Magnitude mag;
		Phase ang;
	public:
		Polar();
		Polar(Magnitude m, Phase p);
		~Polar();
};

#include "polar.hpp"
#endif