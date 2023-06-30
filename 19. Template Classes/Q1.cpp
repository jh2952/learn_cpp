// Write a class template called Pair1 that allows the user to define
// one template type that is used for both values in the pair. 
// [main() provided by author]

#include <iostream>

template <typename T>
class Pair1
{
private:
	T m_value1{};
	T m_value2{};
public:
	Pair1(T value1, T value2)
		: m_value1{ value1 }, m_value2{ value2 }
	{
	}

	T first()  const { return m_value1; }
	T second() const { return m_value2; }
};

int main()
{
	Pair1<int> p1{ 5, 8 };
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2{ 2.3, 4.5 };
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}
