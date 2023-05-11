/* 
*  User is asked to enter 2 floating point numbers. (use doubles)
*  User is asked to enter a basic math operator (+ - * /)
*  Program computes the answer on the numbers the user entered and prints
*  the result.
*  If the user enters an invalid symbol, the program should print nothing.
*/

#include <iostream>

double getNumber() // returns a double number value inputted from the user.
{
	std::cout << "Enter a double integer: ";
	double x{};
	std::cin >> x;

	return x;
}

char getOperator() // returns a char mathematical operator chosen by the user.
{
	std::cout << "Enter one of the following operators, + - * / : ";
	char c{};
	std::cin >> c;

	return c;
}

int main() // performs the evaluation of the chosen mathematical expression by the user. Exits of invalid operator.
{
	double num1{ getNumber() };
	double num2{ getNumber() };

	char op{ getOperator() };

	// ASCII code coversions: + -> 43, - -> 45, * -> 42, / -> 47.

  // showing off while practicing static_cast. Can just make condition (op == '+') or (op == '-') etc.
  
	if (static_cast<int>(op) == 43)
		std::cout << "You chose addition: " << num1 << " + " << num2 << " is " << num1 + num2;
	else if (static_cast<int>(op) == 45)
		std::cout << "You chose subtraction: " << num1 << " - " << num2 << " is " << num1 - num2;
	else if (static_cast<int>(op) == 42)
		std::cout << "You chose multiplication: " << num1 << " * " << num2 << " is " << num1 * num2;
	else if (static_cast<int>(op) == 47)
		std::cout << "You chose division: " << num1 << " / " << num2 << " is " << num1 / num2;
	else
		return 0;

	return 0;
}
