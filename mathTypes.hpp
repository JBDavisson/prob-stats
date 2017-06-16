#include "mathTypes.h"

template <typename T>
Complex<T>::Complex()
{
	a = double_t();
	b = double_t();
	mag = double_t();
}

template <typename T>
Complex<T>::Complex(const Component a, const Component b)
{
	this->a = a;
	this->b = b;
}

template <typename T>
void Complex<T>::computeMagnitude()
{
	this->mag = std::sqrt(std::pow(a, 2) + std::pow(b, 2));
}

template <typename T>
void Complex<T>::computePhase()
{
	this->ang = std::atan2(b, a);
}

template<typename T>
Magnitude Complex<T>::getMagnitude() const
{
	computeMagnitude();
	return (Magnitude)(mag);
}

template<typename T>
Phase Complex<T>::getPhase() const
{
	computePhase();
	return (Phase)(ang);
}

template <typename T>
Component Complex<T>::getRealPart() const
{
	return (Component)this->a;
}

template <typename T>
Component Complex<T>::getImaginaryPart() const
{
	return (Component)this->b;
}

//Begin operator overloads
template <typename T>
std::ostream& Complex<T>::operator << (std::ostream& os/*, const Complex<T>& c*/) 
{
	os << "(" << this->getRealPart() << ", j" << this->getImaginaryPart() << ")";
	return os;
}

template <typename T>
Complex<T>::~Complex()
{
}
