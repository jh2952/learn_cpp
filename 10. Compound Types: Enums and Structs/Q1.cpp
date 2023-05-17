// In a game, we want to have monsters. Declare a struct that represents your monster.
// It should have a type that can be one of the following:
// An ogre, a dragon, an orc, a giant spider, or a slime. 
// Use enum class for this.
// Each individual monster should have:
// A name (std::string_view), and health. 
// Write a func printMonster() that prints out all of the structs members.
// Instantiage an ogre and a slime, initalize them using an initalizer list.
// Pass them to printMonster().

#include <iostream>
#include<string>

enum class MonsterType
{
	ogre,
	dragon,
	orc,
	giantSpider,
	slime,
};

struct MonsterStats
{
	MonsterType type{};
	std::string_view name{};
	int health{};
};

void printMonster(MonsterStats& monster)
{
	std::string_view type{};

	switch (monster.type) // This could be its own function: std::string monsterName()
	{
	case MonsterType::ogre: 
		type = "Ogre";
		break;
	case MonsterType::dragon: 
		type = "Dragon";
		break;
	case MonsterType::orc: 
		type = "Orc";
		break;
	case MonsterType::giantSpider: 
		type = "Giant Spider";
		break;
	case MonsterType::slime: 
		type = "Slime";
		break;
	default: 
		type = "???";
		break;
	}

	std::cout << "This " << type << " is named " << monster.name << " and has " << monster.health << " health.";
	std::cout << '\n';
}

int main()
{
	MonsterStats ogre{ MonsterType::ogre, "Torg", 145 };
	MonsterStats slime{ MonsterType::slime, "Blurp", 23 };
	MonsterStats dragon{ MonsterType::dragon, "Smaug", 1000 };

	printMonster(ogre);
	printMonster(slime);
	printMonster(dragon);

	return 0;
}

