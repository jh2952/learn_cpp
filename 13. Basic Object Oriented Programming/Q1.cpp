// Create a class called Point2d. Define a member function called distanceFrom
// which takes another Point2d as a parameter then provides the distance between
// the points, then move the member function outside of the class and make it 
// take two Point2d arguments as references.

#include <iostream>
#include <cmath>

class Point2d
{
private:

	double m_x{};
	double m_y{};

public:
	
	Point2d(double x = 0.0, double y = 0.0)
		: m_x{ x }, m_y{ y }
	{
	}

	void print()
	{
		std::cout << "Point2d";
		std::cout << "(" << m_x << ", " << m_y << ")\n";
	}

	double getX() { return m_x; }
	double getY() { return m_y; }

};

double distanceFrom(Point2d& point1, Point2d& point2)
{
	return std::sqrt((point1.getX() - point2.getX()) * (point1.getX() - point2.getX()) + (point1.getY() - point2.getY()) * (point1.getY() - point2.getY()));
}


int main()
{
	Point2d first{};
	Point2d second{ 3.0, 4.0 };
	first.print();
	second.print();
	std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

	return 0;
}
