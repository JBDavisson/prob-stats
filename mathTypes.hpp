#include "mathTypes.h"
#include <cmath>

template <typename T>
Complex<T>::Complex()
{
	a = double_t();
	b = double_t();
	mag = double_t();
}

template <typename T>
Complex<T>::Complex(const Component re, const Component im)
{
	a = re;
	b = im;
	computePhase();
	computeMagnitude();
}

template <typename T>
void Complex<T>::computeMagnitude()
{
	mag = std::sqrt(std::pow(a, 2) + std::pow(b, 2));
}

template <typename T>
void Complex<T>::computePhase()
{
	ang = std::atan2(b, a);
}

template<typename T>
Magnitude Complex<T>::getMagnitude() const
{
	return (Magnitude)(mag);
}

template<typename T>
Phase Complex<T>::getPhase(bool rad) const
{	
	return ((rad == true) ? (Phase)(ang) : (Phase)((180/PI)*ang));
}

template <typename T>
void Complex<T>::setComponents(const Component re, const Component im)
{
	a = re;
	b = im;
	computePhase();
	computeMagnitude();
}

template <typename T>
Component Complex<T>::getRealPart() const
{
	return (Component)a;
}

template <typename T>
Component Complex<T>::getImaginaryPart() const
{
	return (Component)b;
}

//Begin operator overloads
template <typename T>
Complex<T> Complex<T>::operator + (Complex<T> com)
{
	Complex<T> c((this->a + com.a), (this->b + com.b));
	//c.setComponents((this->a + com.a), (this->b + com.b));
	return (Complex<T>)c;
}

template <typename T>
Complex<T> Complex<T>::operator * (Complex<T> com)
{
	Complex<T> c((this->a*com.a - this->b*com.b), (this->a*com.b + com.a*this->b));
	return (Complex<T>)c;
}

template <typename T>
void Complex<T>::complexConjugate()
{
	Component temp = -(this->b);
	this->setComponents(this->a, temp);
}

/*
template <typename T>
std::ostream& Complex<T>::operator << (std::ostream& os, const Complex<T>& com) 
*/


template <typename T>
Complex<T>::~Complex()
{
}
