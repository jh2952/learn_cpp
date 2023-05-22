// Create an array to track the inventory of the player.
// Use an enum to identify different types of items.

#include <iostream>
#include <array>
#include <numeric>

enum Items
{
	pHealth,  // 0
	torch,    // 1
	arrow,    // 2
	invSize,  // 3
};

int countTotalItems(const std::array<int, invSize> inv)
{
	return std::reduce(inv.begin(), inv.end());
}

int main()
{
	std::array<int, invSize> inv{ 2, 5, 10 }; // Inventory Array
	std::cout << "Total Items: " << countTotalItems(inv) << '\n';
	std::cout << "Total Torches: " << inv[torch] << '\n';
}
