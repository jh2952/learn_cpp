// Create a random monster generator.

#include <iostream>
#include <array>
#include "Random.h"


// Monster Class : HP, Name, Roar and Monster type.
class Monster
{
public:

	enum Type
	{
		dragon,
		goblin, 
		ogre,
		orc,
		skeleton,
		troll,
		vampire,
		zombie,
		max_monster_types
	};

private:

	Type m_type{};
	std::string m_name{};
	std::string m_roar{};
	int m_hitPoints{};

public:

	Monster(Type type, std::string_view name, std::string_view roar, int hp)
		: m_type{ type }
		, m_name{ name }
		, m_roar{ roar }
		, m_hitPoints{ hp }
	{}

	std::string_view m_getTypeString()
	{
		switch (m_type)
		{
		case Type::dragon:   return "dragon";
		case Type::goblin:   return "goblin";
		case Type::ogre:     return "orge";
		case Type::orc:      return "orc";
		case Type::skeleton: return "skeleton";
		case Type::troll:    return "troll";
		case Type::vampire:  return "vampire";
		case Type::zombie:   return "zombie";

		default:
			return "???";
		}
	}

	void print()
	{
		std::cout << m_name << " the " << m_getTypeString() << " has " <<
			m_hitPoints << " hp and says " << m_roar << ".\n";
	}
};

// Uses Mersenne Twister PRNG to generate random attributes to assign to
// the Monster class.

namespace MonsterGenerator
{
	Monster generate()
	{
		static std::array<std::string, 6> names{ "Bones", "Stinker", "Blob", "Binky", "Jenga", "Slow" };
		static std::array<std::string, 6> roars{ "*rattle*", "*farts*", "*blorp*", "Nyeheheh", "*CRASH*", "..." };
		
		Monster::Type randType{ static_cast<Monster::Type>(Random::get(Monster::dragon, Monster::max_monster_types - 1)) };
		int randHp{ Random::get(1, 100) }; // Arbitrary range from 1-100
		std::string_view randName{ names[Random::get(0, 5)] }; // 0 - 5 are indices for the array
		std::string_view randRoar{ roars[Random::get(0, 5)] };

		return Monster{ randType, randName, randRoar, randHp };
	}
}

int main()
{
	Monster m{ MonsterGenerator::generate() };
	m.print();

	return 0;
}
