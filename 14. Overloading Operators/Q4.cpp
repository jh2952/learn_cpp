// Write a class called 'FixedPoint2' with two fractional digits.
// main() and testAddition() provided by the question.

#include <iostream>
#include <cmath>

class FixedPoint2
{
private:
	std::int16_t m_top{};
	std::int8_t  m_bel{};
public:
	
	FixedPoint2(double value)
	{
		// Store all integers above the decinmal in m_top
		m_top = static_cast<std::int16_t>(std::trunc(value));

		// Take m_top from the value (leaving only integers below the decimal),
		// multiply by 100 and round to the nearest whole integer.
		m_bel = static_cast<std::int8_t>(std::round((value - m_top) * 100));


		// Check if negative
		if (m_top < 0 || m_bel < 0)
		{
			if (m_top > 0)
				m_top = -m_top;
			if (m_bel > 0)
				m_bel = -m_bel;
		}
	}
	
	FixedPoint2(std::int16_t top, std::int8_t bel)
		: m_top{ top }, m_bel{ bel }
	{
		// Check if negative
		if (m_top < 0 || m_bel < 0)
		{
			if (m_top > 0)
				m_top = -m_top;
			if (m_bel > 0)
				m_bel = -m_bel;
		}
	}

	operator double() const
	{
		return m_top + (static_cast<double>(m_bel) / 100);
	}
	
	// I/O Stream
	friend std::ostream& operator<<(std::ostream& out, FixedPoint2& fp2);
	friend std::istream& operator>>(std::istream& in,  FixedPoint2& fp2);

	// Boolean Evaluation
	friend bool operator==(FixedPoint2& num1, FixedPoint2& num2);

	// Arithmetic Operators
	friend FixedPoint2 operator+(FixedPoint2& num1, FixedPoint2& num2);
	FixedPoint2 operator-(FixedPoint2& fp2);
};

bool operator==(FixedPoint2& num1, FixedPoint2& num2)
{
	return (num1.m_top == num2.m_top) && (num1.m_bel == num2.m_bel);
}

FixedPoint2 operator+(FixedPoint2& num1, FixedPoint2& num2)
{
	double value1 = static_cast<double>(num1);
	double value2 = static_cast<double>(num2);

	return FixedPoint2{ value1 + value2 };
}

FixedPoint2 FixedPoint2::operator-(FixedPoint2& fp2)
{
	fp2.m_top = -fp2.m_top;
	fp2.m_bel = -fp2.m_bel;
	return fp2;
}

std::ostream& operator<<(std::ostream& out, FixedPoint2& fp2)
{
	out << static_cast<double>(fp2);
	return out;
}

std::istream& operator>>(std::istream& in, FixedPoint2& fp2)
{
	double value;
	in >> value;
	fp2 = FixedPoint2{ value };
	return in;
}

void testAddition()
{
	// h/t to reader Sharjeel Safdar for this function
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 }) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 }) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 }) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 }) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 }) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 }) << '\n'; // first negative, possible decimal overflow
}

int main()
{
	testAddition();

	FixedPoint2 a{ -0.48 };
	std::cout << a << '\n';

	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';

	return 0;
}
