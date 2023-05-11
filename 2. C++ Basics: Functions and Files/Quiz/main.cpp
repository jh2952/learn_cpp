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
