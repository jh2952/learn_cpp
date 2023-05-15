// Write a function template named add that allows the user to add 2 values 
// of the same type. main() provided by the question.

// Write a function named mult() that allows the user to multiply one value
// of any type and an integer. The function should return the same type
// as the first parameter.

// Write a function named sub(), that allows the user to subtract two values
// of different types.

#include <iostream>

template <typename T>
T add(T x, T y)
{
	return x + y;
}

template <typename T>
T mult(T x, int y)
{
	return x * y;
}

template <typename T, typename U>
auto sub(T x, U y)
{
	return x - y;
}

int main()
{
	std::cout << add(2, 3) << '\n';
	std::cout << add(1.2, 3.4) << '\n';
	std::cout << mult(2, 3) << '\n';
	std::cout << mult(1.2, 3) << '\n';
	std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';

	return 0;
}
