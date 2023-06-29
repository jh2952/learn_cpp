// Create an abstract class names 'Shape', with a pure virtual print function, 
// overloaded operator<<, and virtual destructor.

// Derive from this class Circle and Triangle. Triangle should have three points,
// and circle should contain an origin point and a radius.

// Given these classes, make the main() function [provided by author] execute.

#include <iostream>
#include <algorithm>
#include <vector>

class Point
{
private:
	int m_x{};
	int m_y{};

public:
	Point() = default;
	Point(int x, int y)
		: m_x{ x }, m_y{ y }
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		return out << "Point(" << p.m_x << ", " << p.m_y << ')';
	}
};

class Shape
{
public:
	virtual std::ostream& print(std::ostream& out) const = 0;

	friend std::ostream& operator<<(std::ostream& out, const Shape& s)
	{
		return s.print(out);
	}

	virtual ~Shape() = default;
};

class Triangle : public Shape
{
private:
	Point m_1{};
	Point m_2{};
	Point m_3{};
public:
	Triangle(const Point& p1, const Point& p2, const Point& p3)
		: m_1{p1}, m_2{p2}, m_3{p3}
	{}

	std::ostream& print(std::ostream& out) const override
	{
		out << "Triangle(" << m_1 << ", " << m_2 << ", " << m_3 << ")" << '\n';
		return out;
	}
};

class Circle : public Shape
{
private:
	Point m_origin{};
	int   m_radius{};
public:
	Circle(const Point& p1, int radius)
		: m_origin{ p1 }, m_radius{ radius }
	{
	}

	std::ostream& print(std::ostream& out) const override
	{
		out << "Circle(" << m_origin << ", radius = " << m_radius << ")\n";
		return out;
	}

	int getRadius() { return m_radius; }
};

bool compareRadius(Circle* c1, Circle* c2)
{
	return c1->getRadius() < c2->getRadius();
}

int getLargestRadius(std::vector<Shape*>& v)
{
	std::vector<Circle*> circles{};

	for (const auto& element : v)
	{
		if (typeid(*element) == typeid(Circle))
			circles.push_back(dynamic_cast<Circle*>(element));
		else
			continue;
	}

	std::sort(circles.begin(), circles.end(), compareRadius);

	return circles.back()->getRadius();
}

int main()
{
	std::vector<Shape*> v{
	  new Circle{Point{ 1, 2 }, 7},
	  new Circle{Point{ 2, 4 }, 13},
	  new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
	  new Circle{Point{ 7, 8 }, 3}
	};

	// print each shape

	for (auto& element : v)
		std::cout << *element << '\n';

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	// deallocate memory

	for (auto& element : v)
		delete element;

	return 0;
}
