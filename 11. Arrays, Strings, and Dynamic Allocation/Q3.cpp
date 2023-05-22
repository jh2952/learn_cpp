// Create a program to swap to values.

#include <iostream>
#include <array>

void swap(int& a, int& b)
{
	int temp{ a };
	a = b;
	b = temp;
}

int main()
{
	int x{ 5 };
	int y{ 9 };
	swap(x, y);
	std::cout << x << '\t' << y;

	return 0;
}
