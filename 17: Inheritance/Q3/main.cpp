// In this quiz, I create a randomly generated monster game.
// The player encounters monsters, and either fights, or runs.
// On killing each monster, they gain gold and levels. 
// When the player either reaches a high enough level, or dies, the game ends.

#include <iostream>
#include <string>
#include <array>
#include <limits>

#include "Random.h"

enum pOutcomes
{
	pWin,
	pLose,
	pRun,
	pInProgress,
	max_outcomes,
};

class Creature
{
protected:
	std::string m_name{};
	char m_symbol{};
	int m_health{};
	int m_damage{};
	int m_gold{};
public:
	// Constructor
	Creature(std::string_view name, char symbol, int health, int damage, int gold)
		: m_name{ name }, m_symbol{ symbol }, m_health{ health }, m_damage{ damage },
		  m_gold{ gold }
	{
	}

	// Getters
	std::string getName() const { return m_name; }
	char getSymbol() const      { return m_symbol; }
	int getHealth()  const      { return m_health; }
	int getDamage()  const      { return m_damage; }
	int getGold()    const      { return m_gold; }

	void reduceHealth(int amount) { m_health -= amount; }
	void addGold(int amount)      { m_gold += amount; }

	bool isDead() const { return m_health <= 0; }
};

class Player : public Creature
{
private:
	int m_level{};
public:
	Player(std::string name) : Creature{ name, '@', 10, 1, 0 }, m_level{ 1 }
	{
	}

	void levelUp()
	{
		++m_level;
		++m_damage;
	}

	int getLevel() { return m_level; }

	bool hasWon() { return m_level >= 20; }
};

class Monster : public Creature
{
public:
	enum Type
	{
		dragon,
		orc,
		slime,
		max_types,
	};

	Monster(Type type) : Creature{ getDefaultCreature(type) }
	{
	}

	static Monster getRandomMonster()
	{
		int rand{ Random::get(0, max_types - 1) };
		Monster randMonst{ static_cast<Type>(rand) };
		return randMonst;
	}

private:
	static const Creature& getDefaultCreature(Type type)
	{
		static const std::array<Creature, static_cast<std::size_t>(max_types)> monsterData
		{ { {"dragon", 'D', 20, 4, 100},
			{"orc", 'o', 4, 2, 25},
			{"slime", 's', 1, 1, 10} }
		};

		return monsterData.at(static_cast<std::size_t>(type));
	}
};

std::string inputName()
{
	std::cout << "Enter your name: ";
	std::string name{};
	std::getline(std::cin >> std::ws, name);
	return name;
}

bool inputFight()
{
	/*
	Recieves user input : R -> Run, F -> Fight.
	Returns TRUE for fight.
	Return FALSE for run.
	Ignores incorrect/extraneous input, and recives upper & lower case.
	*/

	while (true)
	{
		std::cout << "(R)un, or (F)ight? ";
		char move{};
		std::cin >> move;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch (move)
		{
		case 'R':
		case 'r':
			return false;
		case 'F':
		case 'f':
			return true;
		default:
		{
			std::cout << "Invalid Input.\n";
			break;
		}
		}
	}
}

bool attemptRun()
{
	bool run{static_cast<bool>(Random::get(0, 1))};
	// Uniform distribution and two integers, therefore 50% to select one or the other.
	return run;
}

pOutcomes fight(Player& p, Monster& m)
{
	m.reduceHealth(p.getDamage());
	std::cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage.\n";

	if (m.isDead())
	{
		std::cout << "You killed the " << m.getName() << '\n';
		p.addGold(m.getGold());
		std::cout << "You gained " << m.getGold() << " gold." << '\n';
		return pWin;
	}

	p.reduceHealth(m.getDamage());
	std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";

	if (p.isDead())
	{
		std::cout << "You died.\n";
		return pLose;
	}

	return pInProgress;
}

pOutcomes run(Player& p, Monster& m)
{
	if (attemptRun())
	{
		std::cout << "You successfully fled.\n";
		return pRun;
	}

	std::cout << "You failed to flee\n";

	p.reduceHealth(m.getDamage());
	std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";

	if (p.isDead())
	{
		std::cout << "You died.\n";
		return pLose;
	}

	return pInProgress;
}

int main()
{
	Player p{ inputName() };
	std::cout << "Welcome, " << p.getName() << '\n';
	pOutcomes current{};

	while (p.getLevel() < 20)
	{
		Monster m{ Monster::getRandomMonster() };
		std::cout << "You have encountered a " << m.getName() << ' ' << m.getSymbol() << '\n';

		current = pInProgress;
		
		while (current == pInProgress)
		{
			std::cout << "Your health: " << p.getHealth() << std::endl;
			std::cout << m.getName() << "'s health: " << m.getHealth() << std::endl;

			if (inputFight())
				current = fight(p, m);
			else
				current = run(p, m);
		}

		if (current == pWin)
		{
			p.levelUp();
			std::cout << "You are now level " << p.getLevel() << '\n';
			continue;
		}
		else if (current == pLose)
			break;
		else
			continue;
	}

	if (current != pLose)
	{
		std::cout << "You won! You reached level 20 with " << p.getGold() << " gold!";
	}
	else
	{
		std::cout << "You reached level " << p.getLevel() << " with " << p.getGold() << " gold.";
	}

	return 0;
}
