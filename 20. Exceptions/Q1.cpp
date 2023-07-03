// Write a Fraction class that has a constructor that takes a numerator and a denominator. 
// If the user passes in a denominator of 0, throw an exception of type std::runtime_error (included in the stdexcept header). 
// In your main program, ask the user to enter two integers. 
// If the Fraction is valid, print the fraction. If the Fraction is invalid, catch a std::exception, and tell the user that they entered an invalid fraction.

#include <iostream>
#include <stdexcept>

class Fraction
{
private:
	int m_top{};
	int m_bot{};
public:
	Fraction(int top, int bottom)
		: m_top{ top }, m_bot{ bottom }
	{
		if (m_bot <= 0)
			throw std::runtime_error("Cannot divide by zero");
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
	out << f.m_top << '/' << f.m_bot;
	return out;
}

int userInput()
{
	int temp{};
	std::cin >> temp;
	return temp;
}

int main()
{
	std::cout << "Enter a numerator: ";
	int top{ userInput() };
	std::cout << "Enter a denominator: ";
	int bot{ userInput() };

	try
	{
		Fraction frac{ top, bot };
		std::cout << frac << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	return 0;
}
