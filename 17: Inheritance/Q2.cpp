#include <iostream>

class Fruit
{
private:
	std::string m_name{};
	std::string m_colour{};
public:
	Fruit() = default;
	Fruit(std::string_view name, std::string_view colour)
		: m_name{ name }, m_colour{ colour }
	{
	}

	std::string_view getName() { return m_name; }
	std::string_view getColour() { return m_colour; }
};

class Apple : public Fruit
{
protected:
	Apple(std::string_view name, std::string_view colour)
		: Fruit{ name, colour }
	{
	}
public:
	Apple() = default;
	Apple(std::string_view colour)
		: Fruit{ "Apple", colour }
	{
	}
};

class Banana : public Fruit
{
public:
	Banana() : Fruit{ "Banana", "Yellow" }
	{
	}
};

class GrannySmith : public Apple
{
public:
	GrannySmith() : Apple{ "Granny Smith Apple", "Green" }
	{
	}
};

int main()
{
	Apple a{ "red" };
	Banana b{};
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColour() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColour() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColour() << ".\n";

	return 0;
}
