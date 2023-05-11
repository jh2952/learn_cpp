/*
Write a program to simulate a ball being dropped off of a tower.
User is asked for the inital height of the tower in metres.
Output the height of the ball above the ground after t = [0:5].
(The ball should not go below the ground).
*/

#include <iostream>
#include <cmath>

// Ask user for initial height in metres.
double askHeight()
{
	std::cout << "Enter the tower height in metres: ";
	double height{};
	std::cin >> height;

	return height;
}

// Outputs the distance the ball has fallen. Takes in an integer time, and returns an end height fallen.
double distanceFallen(int time, double inital)
{
	constexpr double gravity{ 9.8 };

	double end_height = gravity * (std::pow(time, 2) / 2);
	return inital - end_height;
}

// Prints the height of the ball to the console.
void outputHeight(int time, double height)
{
	if (height <= 0)
		std::cout << "At " << time << " seconds, the ball is on the ground" << '\n';
	else
		std::cout << "At " << time << " seconds, the ball is at height " << height << '\n';
}
	
// I am following the course structure, but it is obvious this code can be improved with a while loop.

int main()
{
	double height{ askHeight() };
	outputHeight(0, (distanceFallen(0, height)));
	outputHeight(1, (distanceFallen(1, height)));
	outputHeight(2, (distanceFallen(2, height)));
	outputHeight(3, (distanceFallen(3, height)));
	outputHeight(4, (distanceFallen(4, height)));
	outputHeight(5, (distanceFallen(5, height)));

	return 0;
}
