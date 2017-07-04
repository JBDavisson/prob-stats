#ifndef __MATH__TYPES__HH__
#define __MATH__TYPES__HH__

#include <cmath>
#include <iostream>

typedef double_t Component;
typedef double_t Magnitude;
typedef double_t Phase;

template <typename T>
class Complex
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
		Complex<T>();
		Complex<T>(const Component a, const Component b);
		
		//Begin non-constructor methods.
		Component		getRealPart() const;
		Component		getImaginaryPart() const;
		Magnitude 		getMagnitude() const;
		Phase 			getPhase() const;
		
		//Operator Overloads
		std::ostream& operator << (std::ostream& os/*, const Complex<T>& c*/);
		
		//Class object destructor
		~Complex();
};

#include "mathTypes.hpp"
#endif
