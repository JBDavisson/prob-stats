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
Polar<T>::~Polar()
{}