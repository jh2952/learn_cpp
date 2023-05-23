#include <iostream>
#include <iterator>

// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is found, -1 otherwise

int binarySearch(const int* array, int target, int min, int max)
{   
    // Three options. Less than, more than, or equal to.
    // If equal, return index of center element. 
    // If more than, discard top half of array. Restart assessment.
    // If less than, discord bottom half of array. Restart assessment.
    
    while (true)
    {
        int mid{ max + min / 2 };

        if (array[mid] == target)
            return mid;

        if (array[mid] < target)
        {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }

        if (min > max)
            return -1;
    }
}

int recursiveBinarySearch(const int* array, int target, int min, int max)
{
    while (min <= max)
    {
        int mid{ max + min / 2 };

        if (array[mid] < target)
        {
            return recursiveBinarySearch(array, target, mid + 1, max);
        }
        else if (array[mid] > target)
        {
            return recursiveBinarySearch(array, target, min, mid - 1);
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

int main()
{
    constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

    // We're going to test a bunch of values to see if they produce the expected results
    constexpr int numTestValues{ 9 };
    // Here are the test values
    constexpr int testValues[numTestValues]{ 0, 3, 12, 13, 22, 26, 43, 44, 49 };
    // And here are the expected results for each value
    int expectedValues[numTestValues]{ -1, 0, 3, -1, -1, 8, -1, 13, -1 };

    std::cout << "Using iterative binary search: \n";

    // Loop through all of the test values
    for (int count{ 0 }; count < numTestValues; ++count)
    {
        // See if our test value is in the array
        int index{ binarySearch(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1) };
        // If it matches our expected value, then great!
        if (index == expectedValues[count])
            std::cout << "test value " << testValues[count] << " passed!\n";
        else // otherwise, our binarySearch() function must be broken
            std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
    }

    std::cout << '\n' << "Using recursive binary search:\n";

    for (int count{ 0 }; count < numTestValues; ++count)
    {
        // See if our test value is in the array
        int index{ recursiveBinarySearch(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1) };
        // If it matches our expected value, then great!
        if (index == expectedValues[count])
            std::cout << "test value " << testValues[count] << " passed!\n";
        else // otherwise, our binarySearch() function must be broken
            std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
    }

    return 0;
}
