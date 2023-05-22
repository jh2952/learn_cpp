#include <iostream>
#include <array>
#include <random>

// 1. Create Enumerations for card ranks and suits. 

enum class CardRank
{
	one,
	two,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	ten,
	jack,
	queen,
	king,
	max_ranks,
};

enum class CardSuit
{
	clubs,
	diamonds,
	hearts,
	spades,
	max_suits,
};

// 2. Create a struct to represent the card.

struct Card
{
	CardRank rank{};
	CardSuit suit{};
};

// 3. Create a function that takes a card parameter and prints the card rank
//    and suit as a two letter code. 

void printCard(const Card& card)
{
	switch (card.rank)
	{
	case CardRank::one:    std::cout << '1'; break;
	case CardRank::two:    std::cout << '2'; break;
	case CardRank::three:  std::cout << '3'; break;
	case CardRank::four:   std::cout << '4'; break;
	case CardRank::five:   std::cout << '5'; break;
	case CardRank::six:    std::cout << '6'; break;
	case CardRank::seven:  std::cout << '7'; break;
	case CardRank::eight:  std::cout << '8'; break;
	case CardRank::nine:   std::cout << '9'; break;
	case CardRank::ten:    std::cout << 'T'; break;
	case CardRank::jack:   std::cout << 'J'; break;
	case CardRank::queen:  std::cout << 'Q'; break;
	case CardRank::king:   std::cout << 'K'; break;
	default:               std::cout << '?'; break;
	}

	switch (card.suit)
	{
	case CardSuit::clubs:    std::cout << 'C'; break;
	case CardSuit::diamonds: std::cout << 'D'; break;
	case CardSuit::hearts:   std::cout << 'H'; break;
	case CardSuit::spades:   std::cout << 'S'; break;
	default:                 std::cout << '?'; break;
	}
}

// 4. Create an array to represent a deck of cards, and initalize it with one
//    of each card. Do this in a function called createDeck().

std::array<Card, 52> createDeck()
{
	std::array<Card, 52> deck{};

	int rank{ 0 };
	int suit{ 0 };

	for (auto& card : deck)
	{
		// Check if rank is too high

		if (rank >= static_cast<int>(CardRank::max_ranks))
		{
			rank = 0;
			suit += 1;
		}

		card.rank = static_cast<CardRank>(rank);
		card.suit = static_cast<CardSuit>(suit);

		std::cout << '\t';

		++rank;
	}

	return deck;
}

// 5. Write a function called printDeck() which takes an array as a parameter
//    and prints out the deck. 

void printDeck(const std::array<Card, 52>& deck)
{
	std::cout << '\n';

	for (auto card : deck)
	{
		printCard(card);
		std::cout << ' ';
	}
}

// 6. Write a function that shuffles the deck.

void shuffleDeck(std::array<Card, 52>& deck)
{
	std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::shuffle(deck.begin(), deck.end(), mt);
}

// 7. Write a function that gets the value of a card.
//   ( ace = 11, ten, jack, queen, king = 10 )

int getCardValue(const Card& card)
{
	switch (card.rank)
	{
	case CardRank::one:   return 11;

	case CardRank::two:   return 2;
	case CardRank::three: return 3;
	case CardRank::four:  return 4;
	case CardRank::five:  return 5;
	case CardRank::six:   return 6;
	case CardRank::seven: return 7;
	case CardRank::eight: return 8;
	case CardRank::nine:  return 9;
	case CardRank::ten:

	case CardRank::jack:
	case CardRank::queen:
	case CardRank::king:
		return 10;

	default:
		return 0;
	}
}

constexpr int g_MaximumScore{ 21 };
constexpr int g_MinimumDealerScore{ 17 };


bool checkScore(const int& score)
{
	return score < g_MaximumScore;
}

bool playBlackjack(const std::array<Card, 52>& deck)
{
	std::cout << '\n';

	int playerScore{};
	int dealerScore{};
	int cardsDrawn{};

	// PHASE ONE: Initial draw.
	// Dealer gets one card, player gets two.
	// Check if player score > 21. If so, return false.

	dealerScore = getCardValue(deck[cardsDrawn++]);
	playerScore = getCardValue(deck[cardsDrawn++]) + getCardValue(deck[cardsDrawn++]);

	std::cout << "Dealer score: " << dealerScore << '\n';
	std::cout << "Player score: " << playerScore << '\n';

	// PHASE TWO: Playtime
	// Player is asked: Hit or stand?
	// If hit, draw card add to score.
	// Over 21? Lose.
	// Under 21? Ask again.
	// If stand, exit loop, move onto next phase.

	while (true)
	{
		if (!checkScore(playerScore))
			return false;

		std::cout << "Hit [0] or Stand [1]? ";
		bool stand{};
		std::cin >> stand;
		
		if (stand)
			break;

		playerScore += getCardValue(deck[cardsDrawn++]);
		std::cout << "Player score: " << playerScore << '\n';
	}

	// PHASE THREE: Dealer plays
	// Dealer draws until score is >= 17.
	// Is dealer score > 21? If so, return true.
	// If not, is dealer score < Player score?
	//    If so, return true.
	//    If not, return false. 

	while (dealerScore < g_MinimumDealerScore)
	{
		dealerScore += getCardValue(deck[cardsDrawn++]);
		std::cout << "Dealer score: " << dealerScore << '\n';
	}
	
	std::cout << '\n';

	if (dealerScore > g_MaximumScore)
		return true;
	else if (dealerScore < playerScore)
		return true;
	else
		return false;
}

int main()
{
	std::array<Card, 52> deck{ createDeck() };
	shuffleDeck(deck);

	if (playBlackjack(deck))
		std::cout << "You win!";
	else
		std::cout << "You lose.";

	return 0;
}
