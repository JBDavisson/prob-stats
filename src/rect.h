/**
 *	File:			complex.h
 *	Author:			Jacob B Davisson
 *	Class:			Complex
 *	Purpose:		Header file for class providing implementation of Complex number
 *	Origination:
 *	Last Modified:	08 July 2017
 *
 */

#include <cmath>
#include <iostream>

#ifndef __RECT__HH__
#define __RECT__HH__

#include "mathDefs.h"
#include "polar.h"

namespace Math
{
	template <typename T = double>
	class Rect
	{
		private:
			Component 	a;
			Component 	b;
			Magnitude 	mag;
			Phase 		ang;
			void 		computeMagnitude();
			void 		computePhase();

		public:
			//Constructor methods.
			Rect<T>();
			Rect<T>(const Component a, const Component b);

			//Begin non-constructor methods.
			Component		getRealPart() const;
			Component		getImaginaryPart() const;
			Magnitude 		getMagnitude() const;
			Phase 			getPhase(bool rad) const;
			void			setComponents(const Component a, const Component b);
			void	 		complexConjugate();
			void			setPolarComponents(Magnitude mag, Phase angle, bool rad);
			//Operator Overloads
			Rect<T> operator + (Rect<T> com);
			Rect<T> operator * (Rect<T> com);
			friend std::ostream& operator << (std::ostream& os, Rect<T> com)
			{
				if (com.getImaginaryPart() < 0)
				{
					os << "(" << com.getRealPart() << ", -j" << std::abs(com.getImaginaryPart()) << ")";
				}
				else
				{
					os << "(" << com.getRealPart() << ", j" << com.getImaginaryPart() << ")";
				}
				return os;
			}

			//Class object destructor
			~Rect();
	};

	#include "rect.hpp"
}
#endif
