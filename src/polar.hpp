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
Polar<T>::~Polar()
{}