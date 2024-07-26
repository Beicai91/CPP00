#include "phoneBook.hpp"

phoneBook::phoneBook()
{
    this->_idx = 0;
}

phoneBook::~phoneBook()
{}

int phoneBook::_getIndex()
{
    int idx;
    bool    validIdx = false;

    while (!validIdx)
    {
        std::cin >> idx;
        if (idx >= 0 && idx < 8)
            validIdx = true;
        else
            std::cout << "Invalid index. Index should be between 0 - 7. Please try again." << std::endl; 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return (idx);
}

void    phoneBook::add()
{
    if (this->_idx == 8)
        this->_idx = 0;
    this->_contacts[this->_idx].init_new(this->_idx);
    this->_idx++;
}

void    phoneBook::search()
{
    int idx;

    //view all the contacts
    for (int i = 0; i < 8; i++)
        this->_contacts[i].view();
    std::cout << "Please enter the index of one contact to see details: ";
    idx = this->_getIndex();
    this->_contacts[idx].display();
}

void    phoneBook::welcome(void) const
{
    std::cout << "Welcome to your personal phone book!" << std::endl;
    std::cout << "1. This phone book allows users to to add at maximum 8 contacts." << std::endl;
    std::cout << "2. Once 8 contacts are reached, the new contacts will replace the oldest contacts." << std::endl;
    std::cout << "3. The system doesn't offer service of storing permanently the contacts. Once exiting, the contacts are lost." << std::endl;
    std::cout << "---------------USAGE---------------" << std::endl;
    std::cout << "ADD: add a new contact;" << std::endl;
    std::cout << "SEARCH: view the repertoire of all contacts and display the details of a contact of your choice." << std::endl;
    std::cout << "EXIT: exit from the phone book system." << std::endl;
}