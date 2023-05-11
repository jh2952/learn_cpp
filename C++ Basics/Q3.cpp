#include <iostream>

int main() // Recives two integers from input and outputs sum and difference.
{
	std::cout << "Enter your first integer: ";
	int num1{};
	std::cin >> num1;

	std::cout << "Enter your second integer: ";
	int num2{};
	std::cin >> num2;

	std::cout << num1 << " + " << num2 << " is " << num1 + num2 << '\n';
	std::cout << num1 << " - " << num2 << " is " << num1 - num2;

	return 0;
}
