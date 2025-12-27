// #include <iostream>
// #include <string>
// #include "Array.hpp"

// int main()
// {
//     std::cout << "---- default constructor ----\n";
//     Array<int> empty;
//     std::cout << "empty.size() = " << empty.size() << "\n";

//     std::cout << "\n---- sized constructor + write/read ----\n";
//     Array<int> a(3);
//     std::cout << "a.size() = " << a.size() << "\n";
//     a[0] = 10;
//     a[1] = 20;
//     a[2] = 30;
//     std::cout << "a: " << a[0] << " " << a[1] << " " << a[2] << "\n";

//     std::cout << "\n---- copy constructor (deep copy) ----\n";
//     Array<int> b(a);
//     b[0] = 999;
//     std::cout << "a[0] = " << a[0] << " (should be 10)\n";
//     std::cout << "b[0] = " << b[0] << " (should be 999)\n";

//     std::cout << "\n---- assignment operator (deep copy) ----\n";
//     Array<int> c;
//     c = a;
//     c[1] = 777;
//     std::cout << "a[1] = " << a[1] << " (should be 20)\n";
//     std::cout << "c[1] = " << c[1] << " (should be 777)\n";

//     std::cout << "\n---- const Array + const operator[] ----\n";
//     const Array<int> ca(a);
//     std::cout << "ca[2] = " << ca[2] << "\n";

//     std::cout << "\n---- out of bounds ----\n";
//     try {
//         std::cout << a[3] << "\n";
//     } catch (const std::exception& e) {
//         std::cout << "Caught exception on a[3]\n";
//     }

//     std::cout << "\n---- string Array ----\n";
//     Array<std::string> s(2);
//     s[0] = "hello";
//     s[1] = "world";
//     std::cout << s[0] << " " << s[1] << "\n";

//     return 0;
// }

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}