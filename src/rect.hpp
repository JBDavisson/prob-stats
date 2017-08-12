/**
 *	File:			rect.hpp
 *	Author:			Jacob B Davisson
 *	Class:			Rect
 *	Purpose:		Implementation file for class providing implementation of Complex number
 *					in rectangular form.
 *	Origination:
 *	Last Modified:	08 July 2017
 *
 */

//#include "mathTypes.h"
//#include <cmath>

/***
 *
 *		Begin Method definitions for class: Rect<T>
 *
 **/
template <typename T>
Rect<T>::Rect()
{
	a 		= double();
	b 		= double();
	mag 	= double();
}

template <typename T>
Rect<T>::Rect(const Component re, const Component im)
{
	a 		= re;
	b 		= im;
	computePhase();
	computeMagnitude();
}

template <typename T>
void Rect<T>::computeMagnitude()
{
	mag = std::sqrt(std::pow(a, 2) + std::pow(b, 2));
}

template <typename T>
void Rect<T>::computePhase()
{
	ang = std::atan2(b, a);
}

template<typename T>
Magnitude Rect<T>::getMagnitude() const
{
	return (Magnitude)(mag);
}

template<typename T>
Phase Rect<T>::getPhase(bool rad) const
{
	return ((rad == true) ? (Phase)(ang) : (Phase)((180/Math::Consts::PI)*ang));
}

template <typename T>
void Rect<T>::setComponents(const Component re, const Component im)
{
	a = re;
	b = im;
	computePhase();
	computeMagnitude();
}

template <typename T>
void Rect<T>::setPolarComponents(Magnitude mag, Phase angle, bool rad)
{
	if(rad == true)
	{
		setComponents((mag*std::cos(angle)), (mag*std::sin((180/Math::Consts::PI)*angle)));
	}
	else
	{
		setComponents((mag*std::cos(angle)), (mag*std::sin(angle)));
	}
}

template <typename T>
Component Rect<T>::getRealPart() const
{
	return (Component)a;
}

template <typename T>
Component Rect<T>::getImaginaryPart() const
{
	return (Component)b;
}

template <typename T>
Rect<T> Rect<T>::add(const Rect<T> com)
{
	Rect<T> c((this->a + com.a), (this->b + com.b));
	return (Rect<T>)c;
}

template <typename T>
Rect<T> Rect<T>::sub(const Rect<T> com)
{
	return Rect<T>((this->a - com.a), (this->b - com.b));
}

template <typename T>
Rect<T> Rect<T>::mul(const Rect<T> com)
{
	Rect<T> c((this->a*com.a - this->b*com.b), (this->a*com.b + com.a*this->b));
	return (Rect<T>)c;
}

template <typename T>
Rect<T> Rect<T>::div(const Rect<T> com)
{
	Rect<T> t = com;
	this->computeMagnitude(); t.computeMagnitude();
	this->computePhase();	  t.computePhase();
	T c, d, e, f;
	c = this->getMagnitude();	
	d = t.getMagnitude();
	
	e = this->getPhase(false);	
	f = t.getPhase(false);
	T aa = c/d;
	T bb = e-f;
	Rect<T> temp;
	temp.setPolarComponents(aa, bb, false);
	return temp;
}

//Begin operator overloads
template <typename T>
Rect<T> Rect<T>::operator + (const Rect<T> com)
{
	return add(com);
}

template <typename T>
Rect<T> Rect<T>::operator - (const Rect<T> com)
{
	return sub(com);
}

template <typename T>
Rect<T> Rect<T>::operator * (const Rect<T> com)
{
	return mul(com);
}

template <typename T>
Rect<T> Rect<T>::operator / (const Rect<T> com)
{
	return div(com);
}

template <typename T>
void Rect<T>::complexConjugate()
{
	setComponents(this->a, (-this->b));
}

template <typename T>
Rect<T>::~Rect()
{}

/***
 *
 *		End Method definitions for class: Rect<T>
 *
 **/
