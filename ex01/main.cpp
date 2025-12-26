#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElem(const T& x)
{
    std::cout << x << '\n';
}

void incInt(int& x)
{
    ++x;
}

void addBang(std::string& s)
{
    s += "!";
}

int main()
{
    std::cout << "---- int array: print ----\n";
    int a[] = {1, 2, 3, 4, 5};
    ::iter(a, 5, printElem<int>);

    std::cout << "---- int array: modify (inc) ----\n";
    ::iter(a, 5, incInt);
    ::iter(a, 5, printElem<int>);

    std::cout << "---- string array: print ----\n";
    std::string s[] = {"hello", "world", "iter"};
    ::iter(s, 3, printElem<std::string>);

    std::cout << "---- string array: modify (addBang) ----\n";
    ::iter(s, 3, addBang);
    ::iter(s, 3, printElem<std::string>);

    std::cout << "---- const int array: print ----\n";
    const int ca[] = {10, 20, 30};
    ::iter(ca, 3, printElem<int>);

    std::cout << "---- nullptr safety (optional) ----\n";
    ::iter(static_cast<int*>(0), 3, incInt);
    ::iter(a, 5, static_cast<void(*)(int&)>(0));

    return 0;
}