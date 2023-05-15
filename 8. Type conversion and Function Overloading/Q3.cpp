// q1: What is the output of this program and why?

#include <iostream>

void print(int x)
{
    std::cout << "int " << x << '\n';
}

void print(double x)
{
    std::cout << "double " << x << '\n';
}

int main()
{
    short s{ 5 };
    print(s);

    return 0;
}

// Answer: when print() is called with a short type arguement, the compiler
// will try to look for a function with argument type short. Failing this,
// the compiler will attempt numeric promotions, which in this case is possible
// with promotion from short -> int. Therefore this program will output
// "int 5

// q2: Why won't the following compile?

#include <iostream>

void print()
{
    std::cout << "void\n";
}

void print(int x = 0)
{
    std::cout << "int " << x << '\n';
}

void print(double x)
{
    std::cout << "double " << x << '\n';
}

int main()
{
    print(5.0f);
    print();

    return 0;
}

// Answer:
// First print call - no exact match - applies numeric promotion to argument
// from float to double, then function call is resolved to print(double x).
// Second print call - ambiguous match - functions with default parameters
// don't resolve overloaded functions. Can't tell if resolve to print() or
// print (int x = 0).

//q3. Why won't the following compile?

#include <iostream>

void print(long x)
{
    std::cout << "long " << x << '\n';
}

void print(double x)
{
    std::cout << "double " << x << '\n';
}

int main()
{
    print(5);

    return 0;
}

// Answer: No exact match, nor any matches through numeric promotion, so
// compiler performs numeric conversions to find a match. Since int can
// be numerically converted to both double and long, we have an ambiguous
// match and therefore a compile error.

