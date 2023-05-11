// main() was provided by the question.
// Complete main() by writing the isPrime() function using a for loop.

#include <iostream>
#include <cassert>

bool isPrime(int N) // N is the integer being evaluated for 'primeness'
{
    switch (N)
    {
    case 0:
    case 1:
        return false; // 0 & 1 arent prime, handle them here to avoid division by 0 and remainder by 1 problems.
    default:
        for (int i{ 2 }; i < N; ++i) // Check if N is divisible by values from [2:N].
        {
            if (N % i == 0)
                return false;
        }
        return true;
    }
}

int main()
{
    assert(!isPrime(0));
    assert(!isPrime(1));
    assert(isPrime(2));
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(isPrime(11));
    assert(isPrime(13));
    assert(!isPrime(15));
    assert(!isPrime(16));
    assert(isPrime(17));
    assert(isPrime(19));
    assert(isPrime(97));
    assert(!isPrime(99));
    assert(isPrime(13417));

    std::cout << "Success!\n";

    return 0;
}

// Self Marking:
// Fine stuff, but keep in mind this math fact:
//      A non-prime number MUST have AT LEAST ONE divisor which is LESS THAN OR EQUAL to
//      its square root.
// 
// You only need to check if N is divisible from 2, up to and including, the square root of N.
// If there is no factor of N in this range, then N is prime. 
//
// There are also various number theory tricks for checking divisibility that are worth
// investigating if they improve performance (the digit sum for divisibility by 3 comes to mind).
