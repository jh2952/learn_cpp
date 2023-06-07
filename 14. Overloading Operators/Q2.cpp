// main() provided by the question.

// Create an 'Average' class which keeps track of the average
// of all integers passed into it.

// Write all neccessary functions for the main() function to execute.

#include <iostream>

class Average
{
private:
	std::int32_t m_sum{};
	std::int8_t m_count{};
public:
	Average()
	{}

	// ostream operator overload
	friend std::ostream& operator<<(std::ostream& out, Average& average);

	// operator += overload forward decleration.
	Average& operator+=(int a);
};

std::ostream& operator<<(std::ostream& out, Average& average)
{
	out << static_cast<double>(average.m_sum) / average.m_count;
	return out;
}

Average& Average::operator+=(int a)
{
	m_sum += a;
	++m_count;
	return *this; // return the object for chaining.
}

int main()
{
	Average avg{};

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}
