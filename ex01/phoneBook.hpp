#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class phoneBook
{
    private:
        contact _contacts[8];
        int _idx;
        int _getIndex();
    
    public:
        phoneBook();
        ~phoneBook();
        void    add(); //use init_new of contact class
        void    search(); //use view and display of contact class
        void    welcome(void) const;
};

#endif