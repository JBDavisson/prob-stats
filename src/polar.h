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
#include <iostream>


#ifndef __POLAR__H__
#define __POLAR__H__

#include "mathDefs.h"
#include "rect.h"

namespace Math
{
	static const char* unicodeAngle = "\u2220";

	template <typename T = double>
	class Polar
	{
		private:
			Magnitude mag;
			Phase ang;
		public:
			//Constructors:
			Polar();
			Polar(Magnitude m, Phase p);
			Polar(const class Rect<T>& r);		//Construct polar form number from Rectangular.
											//Unsure as to exactly why this doesn't work each way.
			
			//Accessor methods:
			Magnitude getMagnitude(void) const;
			Phase	  getPhase(void) const;
			Component getReal(void) const;
			Component getImaginary(void) const;

			//Operator Overloads:
			Polar<T> operator + (const Polar<T> p);
			Polar<T> operator - (const Polar<T> p);
			Polar<T> operator * (const Polar<T> p);
			Polar<T> operator / (const Polar<T> p);

			friend std::ostream& operator << (std::ostream& os, Polar<T>& p)
			{
				os << p.getMagnitude() << unicodeAngle << p.getPhase();
				return os;
			}

			//Destructor:
			~Polar();
	};

	#include "polar.hpp"
}
#endif