#ifndef __MATH__TYPES__HH__
#define __MATH__TYPES__HH__

#include <math.h>

typedef double_t Component;
typedef double_t Magnitude;
typedef double_t Phase;

template <typename T = double>
class Complex
{
	private:
		Component 	a;
		Component 	b;
		Magnitude 	mag;
		Phase 		ang;
		void computeMagnitude();
		void computePhase();
	
	public:
		Complex();
		Complex(Component a, Component b);
		Magnitude getMagnitude() const;
		Phase getPhase() const;
		~Complex();
};


#endif
