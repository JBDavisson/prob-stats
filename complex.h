#ifndef __COMPLEX__HH__
#define __COMPLEX__HH__

#include <cmath>
#include <iostream>

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825

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
		Phase 			getPhase(bool rad) const;
		void			setComponents(const Component a, const Component b);
		void	 		complexConjugate();
		//Operator Overloads
		Complex<T> operator + (Complex<T> com);
		Complex<T> operator * (Complex<T> com);
		friend std::ostream& operator << (std::ostream& os, Complex<T> com)
		{
			if(com.getImaginaryPart() >= 0)
			{
				os << "(" << com.getRealPart() << ", j" << com.getImaginaryPart() << ")";
			}
			else if (com.getImaginaryPart() < 0)
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
		~Complex();
};

#include "complex.hpp"
#endif
