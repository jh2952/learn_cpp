// Create a class template named Triad that has 3 members of the same template type.
// main() was provided by the question.
// Make it compile. It should output [1, 2, 3][1.2, 3.4, 5.6]

#include <iostream>

template <typename T>
struct Triad
{
	T first{};
	T second{};
	T third{};
};

template <typename T>
void print(Triad<T> t)
{
	std::cout << "[" << t.first << ", " << t.second << ", " << t.third << "]";
	std::cout << '\n';
}

// I'm using C++20 so this isn't required, but is good practice because not everyone uses C++20.
template <typename T>
Triad(T, T, T) -> Triad<T>;

int main()
{
	Triad t1{ 1, 2, 3 }; // note: uses CTAD to deduce template arguments
	print(t1);

	Triad t2{ 1.2, 3.4, 5.6 }; // note: uses CTAD to deduce template arguments
	print(t2);

	return 0;
}
