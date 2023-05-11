// Implement a game of HI-LO. User gets 7 tries to guess an integer between [1:100].
// Program should inform user if they won/lost, and give them the option to retry.
// Assume the user inputs a valid integer (this assumption will be erased in question 4)

#include <iostream>
#include "random.h"

// Evaluate if the user's guess was too high, too low, or correct.
bool checkGuess(int guess, int answer)
{
	if (guess == answer) {
		std::cout << "Correct! You Win!" << '\n';
		return true;
	}
	else if (guess < answer) {
		std::cout << "Your guess is too low." << '\n';
		return false;
	}
	else {
		std::cout << "Your guess is too high" << '\n';
		return false;
	}
}

// Evaluate if the user would like to replay the game upon finishing.
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
		default: // Invalid answers cause the loop to restart.
			break;
		}
	}
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
			int guess{};
			std::cin >> guess;

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
