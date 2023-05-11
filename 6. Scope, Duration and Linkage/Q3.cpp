// main() was provided in the question.
// Write a function passOrFail() which returns true for the first 3 calls, and false thereafter. 
// Point of the question is to mess about with the "static" keyword and observe its nature;
// preserving its value even after function termination. 

#include <iostream>

bool passOrFail()
{
	static int s_bool{ 3 };

	if (s_bool >= 0)
		--s_bool;
	return (s_bool >= 0);

}

int main()
{
	std::cout << "User #1: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #2: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #3: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #4: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #5: " << (passOrFail() ? "Pass\n" : "Fail\n");

	return 0;
}
