#include "megaphone.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    Megaphone   phone;
    int i;

    if (argc == 1)
    {
        phone.printNoise();
        return (0);
    }
    i = 1;
    while (i < argc)
    {
        phone.printUC(argv[i]);
        i++;
    }
    std::cout << std::endl;
    return (0);
}