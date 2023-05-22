// Write a function that prints a C-style string character by character.
// Use a pointer to step through the string. Stop at the null terminator.

#include <iostream>

void printString(const char arr[])
{
	for (int index{ 0 }; *(arr + index) != '\0'; ++index)
	{
		std::cout << *(arr + index) << '\n';
	}
}

int main()
{
	printString("Hello, world!");

	return 0;
}
