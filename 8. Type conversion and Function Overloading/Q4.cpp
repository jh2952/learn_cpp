// What is the output of this program and why?

#include <iostream>

template <typename T>
int count(T) // This is the same as int count(T x), except we're not giving the parameter a name since we don't use the parameter
{
    static int c{ 0 };
    return ++c;
}

int main()
{
    std::cout << count(1) << '\n';
    std::cout << count(1) << '\n';
    std::cout << count(2.3) << '\n';
    std::cout << count<double>(1) << '\n';

    return 0;
}

// Answer: 2 functions are instatiated through the execution of main.
// 1: count<int>(int) since there is the function call count(1).
// 2: count<double>(double) since there is the function call count(2.3) & count<double>(1).
// Since each function is called twice, and there is a static int defined within
// the function (which recalls its state even upon function completion), the
// output is:

// 1, 2, 1, 2
