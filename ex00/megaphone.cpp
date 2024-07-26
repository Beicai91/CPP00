#include "megaphone.hpp"
#include <iostream>
#include <string>

void    Megaphone::printUC(const std::string& msg)
{
    size_t len;
    std::string msgUC;

    msgUC = msg;
    len = msgUC.length();
    for (size_t i = 0; i < len; i++)
        std::cout << (char)toupper(msgUC[i]) << std::flush;
}

void    Megaphone::printNoise()
{
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}
