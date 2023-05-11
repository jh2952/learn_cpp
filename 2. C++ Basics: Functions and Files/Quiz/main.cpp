// 1. Write a program (named main.cpp) that reads two seperate integers from the user, adds them together, and then outputs the answer.
// 2. Contain readNumber() and writeAnswer() in a seperate file called "io.cpp".
// 3. Write a header file "io.h" to access the functions instead of using forward declerations in main.

#include <iostream>
#include "io.h"

// readNumber(); recieved an input and returns an integer.
// writeAnswer(); outputs the answer. 
// main(); execute the function.

int main()
{
	int x{ readNumber() };
	int y{ readNumber() };
	writeAnswer(x + y);

	return 0;
}
