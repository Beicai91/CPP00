#include "phoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

int main(void)
{
    phoneBook   pb;
    std::string input;

    pb.welcome();
    while (1)
    {
        std::getline(std::cin, input);
        if (input.compare("ADD") == 0)
            pb.add();
        else if (input.compare("SEARCH") == 0)
            pb.search();
        else if (input.compare("EXIT") == 0)
            exit(0);
        else
            std::cout << "Invalid operation. Please try again." << std::endl;
    }
    return (0);
}

