#include <iostream>

int readNumber() // recieved an input and returns an integer.
{
	std::cout << "Enter a number: ";
	int x{};
	std::cin >> x;
	return x;
}

void writeAnswer(int a) // outputs the answer. 
{
	std::cout << "The answer is: " << a;
}
