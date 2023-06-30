// Write a template class names 'StringValuePair' that inherits
// from a partially specialised Pair class (using std::string as the
// first type, and allowing the user to specify the second type).
// [main() provided by author].

#include <iostream>
#include <string>
#include <string_view>

template <typename T, typename U>
class Pair
{
private:
	T m_x;
	U m_y;

public:
	Pair(const T x, const U y)
		: m_x{ x }, m_y{ y }
	{
	}

	const T first() const { return m_x; }
	const U second() const { return m_y; }
};

template<typename T>
class StringValuePair : public Pair<std::string, T>
{
public:
	StringValuePair(std::string string, T value)
		: Pair<std::string, T>{string, value}
	{
	}
};

int main()
{
	StringValuePair<int> svp{ "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}
