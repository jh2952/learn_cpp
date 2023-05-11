#include <iostream>
#include <limits>
#include "random.h"

// Ignores extraneous input.
void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Check if the guess from the user is too high, too low, or correct.
bool checkGuess(int guess, int answer)
{
	if (guess == answer) {
		std::cout << "Correct! You Win!" << '\n';
		return true;
	}
	else if (guess < answer) {
		std::cout << guess << " is too low." << '\n';
		return false;
	}
	else {
		std::cout << guess << " is too high" << '\n';
		return false;
	}
}

// Check if the user wanted to play again or not. Only accepts y/n.
bool checkRetry()
{
	while (true)
	{
		std::cout << "Would you like to play again (y/n)? ";
		char answer{};
		std::cin >> answer;

		switch (answer)
		{
		case 'y':
			return false;
		case 'n':
			return true;
		default:
			break;
		}
	}
}

// Ensures that the guess the user inputs is valid. Ignores out of range values, extraneous input
// and invalid input types, such as strings and characters.
int enterGuess()
{
	int guess{};
	
	while (true)
	{
		std::cin >> guess;

		if (!std::cin) // If the input was of an invalid type.
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "That input is invalid, please enter an integer from 1 - 100: ";
			continue; // restart the iteration.
		}

		ignoreLine();

		if ((guess < 1) | (guess > 100)) // If the input was out of range.
		{
			std::cout << "That value is out of range. Select a number from 1 - 100: ";
			continue; // restart the iteration.
		}
		break;
	}
	return guess;
}

int main()
{
	while (true)
	{
		std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is." << '\n';

		int answer{ Random::get(1, 100) };
		int guesses{ 1 };

		while (guesses < 8)
		{
			std::cout << "Guess #" << guesses << ": ";
			int guess{ enterGuess() };

			if (checkGuess(guess, answer))
				break;
			else
				++guesses;
		}

		if (guesses > 7)
			std::cout << "Sorry, you lose. The correct number was: " << answer << '\n';

		if (checkRetry())
			break;
	}
}
