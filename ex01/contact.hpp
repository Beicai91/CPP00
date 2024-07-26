#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

class   contact
{
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _secret;
        int _idx;
        std::string _getInput(std::string prompt) const;
        std::string _get_truncated(std::string str);
    
    public:
        contact();
        ~contact();
        void    init_new(int idx);
        void    display() const;
        void    view();
};

#endif