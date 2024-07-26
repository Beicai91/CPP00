#include "contact.hpp"

contact::contact()
{}

contact::~contact()
{}

std::string contact::_getInput(std::string prompt) const
{
    std::string input = "";
    bool    validInput = false;

    while (!validInput)
    {
        std::cout << prompt << std::flush;
        std::getline(std::cin, input);
        if (std::cin.good() && !input.empty())
            validInput = true;
        else
        {
            std::cin.clear();
            std::cout << "Invalid information, please try again" << std::endl;
        }
    }
    return (input);
}

std::string contact::_get_truncated(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return (str);
}

void    contact::init_new(int idx)
{
    this->_idx = idx;
    this->_firstName = this->_getInput("Please enter your first name: ");
    this->_lastName = this->_getInput("Please enter your last name: ");
    this->_nickName = this->_getInput("Please enter your nickname: ");
    this->_phoneNumber = this->_getInput("Please enter your phone number: ");
    this->_secret = this->_getInput("Please enter your secrect as safe key: ");
}

void    contact::display() const
{
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickName.empty())
    {
        std::cout << "This contact's information is not complete" << std::endl;
        return ;
    }
    std::cout << "Contact N." << this->_idx <<std::endl;
    std::cout << "First name: " << this->_firstName << std::endl;
    std::cout << "Last name: " << this->_lastName << std::endl;
    std::cout << "Nickname: " << this->_nickName << std::endl;
    std::cout << "Phone number: " << this->_phoneNumber << std::endl;
    std::cout << "Secret: " << this->_secret << std::endl;
}

void    contact::view()
{
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickName.empty())
        return ;
    std::cout << std::right; //set right alignement
    std::cout << "|" 
              << std::setw(10) << this->_idx << "|" 
              << std::setw(10) << this->_get_truncated(this->_firstName) << "|" 
              << std::setw(10) << this->_get_truncated(this->_lastName) << "|" 
              << std::setw(10) << this->_get_truncated(this->_nickName) << "|" 
              << std::endl;
}