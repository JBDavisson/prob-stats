
#include "mathTypes.h"
#include "prob.h"
#include "utils.h"

#include <cstdio>
#include <iostream>

int main(int argc, char** argv)
{
	printf("e = %f\n", Math::Consts::e);
	Math::Rect<double> cplx(1, 1);
	Math::Polar<> pol(2,30);
	std::cout << "Polar form:" << pol << std::endl;
	printf("Magnitude is: %f\n", cplx.getMagnitude());
	printf("Phase angle is: %f radians\n", cplx.getPhase(true));
	printf("Phase angle is: %f degrees\n", cplx.getPhase(false));
	cplx.setComponents(2, 1);
	printf("Magnitude is: %f\n", cplx.getMagnitude());
	printf("Phase angle is: %f radians\n", cplx.getPhase(true));
	printf("Phase angle is: %f degrees\n", cplx.getPhase(false));
	Math::Rect<double> a(1,1);
	Math::Rect<double> b(2,2);

	std::cout << a*b << std::endl;
	std::cout << (a - b) << std::endl;
	std::cout << (b/a) << std::endl;
	
	Math::Rect<double> d = a + b;
	printf("New complex number is: (%f, j%f)\n", d.getRealPart(), d.getImaginaryPart());
	Math::Rect<double> e = a*b;
	printf("New complex number is: (%f, j%f)\n", e.getRealPart(), e.getImaginaryPart());
	std::cout << cplx << std::endl;
	b.complexConjugate();
	std::cout << "Complex conjugate is: " << b << std::endl;
	Math::Rect<double> test;
	test.setPolarComponents(1.414, 45, false);
	std::cout << "After setting components in polar form: " << test << std::endl;
	
	
	 //
	 //		Testing the probability functionality
	 //
	printf("Factorial of 3 is: %d.\n", Utils::factorial<int>(3));
	printf("nrDescent(2,3) = %d\n", Utils::nrDescent<int>(2,3));
	printf("nrDescent(3,2) = %d\n", Utils::nrDescent<int>(3,2));
	printf("nrDescent(5,2) = %d\n", Utils::nrDescent<int>(5,2));
	printf("nrDescent(5,1) = %d\n", Utils::nrDescent<int>(5,1));
	printf("binomCoeff(3,1) = %d\n", Utils::binomCoeff<int>(3,1));
	printf("binomCoeff(3,2) = %d\n", Utils::binomCoeff<int>(3,2));
	printf("binomCoeff(3,3) = %d\n", Utils::binomCoeff<int>(3,3));
	printf("binomCoeff(3,4) = %d\n", Utils::binomCoeff<int>(3,4));
	printf("binomDist(3, 1, 0.5) = %f\n", Probability::binomDist(3,1,.5));
	printf("binomDist(10,2,0.5) = %f\n", Probability::binomDist(10,2,0.5));
	printf("binomDist(3,1,0.6) = %f\n", Probability::binomDist(3,1,0.6));
	printf("poissonDist(5, 0) = %f\n", Probability::poissonDist(5.0, 0));
	printf("nrProbability(3, 0, 52) = %f\n", Probability::nrProbability(4, 2, 52));
	printf("geometricProb(2,0.5) = %f\n", Probability::geometricProb(2, 0.5));
	printf("negBinomial(3,2,0.5) = %f\n", Probability::negBinomial(3,2,0.5));
	return 0;
}
