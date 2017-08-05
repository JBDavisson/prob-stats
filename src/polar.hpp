template <typename T>
Polar<T>::Polar()
{}

template <typename T>
Polar<T>::Polar(Magnitude m, Phase p)
{
	mag = (m >= 0 ? m : 0);
	ang = p;
}

template <typename T>
Polar<T>::Polar(const Rect<T>& r)
{
	this->mag = std::sqrt(std::pow(r.a, 2) + std::pow(r.b, 2));
	this->ang = std::atan2(r.b, r.a);
}

template <typename T>
Magnitude Polar<T>::getMagnitude(void) const
{
	return mag;
}

template <typename T>
Phase Polar<T>::getPhase(void) const
{
	return ang;
}

template <typename T>
Component Polar<T>::getReal(void) const
{
	return (T)(this->mag * std::cos(this->ang));
}

template <typename T>
Component Polar<T>::getImaginary(void) const
{
	return (T)(this->mag * std::sin(this->ang));
}

template <typename T>
Polar<T> Polar<T>::operator + (const Polar<T> p)
{
	Magnitude m = this->getReal() + p.getReal();
	Phase 	  a = this->getImaginary() + p.getImaginary();
	return Polar<T>((std::sqrt(std::pow(m, 2) + std::pow(a, 2))), (std::atan2(a, m)));
}

template <typename T>
Polar<T> Polar<T>::operator - (const Polar<T> p)
{
	Magnitude m = this->getReal() - p.getReal();
	Phase 	  a = this->getImaginary() - p.getImaginary();
	return Polar<T>((std::sqrt(std::pow(m, 2) + std::pow(a, 2))), (std::atan2(a, m)));
}

template <typename T>
Polar<T> Polar<T>::operator * (const Polar<T> p)
{
	return Polar<T>((this->mag * p.mag), (this->ang + p.ang));
}

template <typename T>
Polar<T> Polar<T>::operator / (const Polar<T> p)
{
	return Polar<T>((this->mag / p.mag), (this->ang - p.ang));
}

template <typename T>
Polar<T>::~Polar()
{}