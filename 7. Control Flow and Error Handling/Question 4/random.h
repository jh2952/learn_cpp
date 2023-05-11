// This header-only Random namespace implements a self-seeding Mersenne Twister PRNG.
// This header was provided by the course structure for re-use, but it works by generating
// a seed based on the device clock and memory, and then generating a pseudo random number
// with the mersenne twister PRNG.

#ifndef RANDOM_H
#define RANDOM_H

#include <chrono>
#include <random>

namespace Random
{
	inline std::mt19937 init()
	{
		std::random_device rd;

		// Create seed sequence with high-res clock and 7 random numbers from std::random_device
		std::seed_seq ss{
			static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
			rd(), rd(), rd(), rd(), rd(), rd(), rd() };

		return std::mt19937{ ss };
	}

	inline std::mt19937 mt{ init() };

	// Generate a random number from [min:max]
	inline int get(int min, int max)
	{
		std::uniform_int_distribution die{ min, max };
		return die(mt); // and then generate a random number from our global generator
	}
};

#endif
