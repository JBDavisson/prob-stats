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

template<typename T>
Magnitude Complex<T>::getMagnitude() const
{
	return (Magnitude)(0);
}

template<typename T>
Phase Complex<T>::getPhase() const
{
	return (Phase)(0);
}

template <typename T>
Complex<T>::~Complex()
{
}
