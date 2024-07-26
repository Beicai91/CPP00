#include <vector>
#include <iostream>
#include <ctime>
#include <iomanip>

#include "Account.hpp"

//initialize static member variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


//constructor and destructor
Account::Account(int initial_deposit)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;
    //initialize non-static member variables
    this->_accountIndex = _nbAccounts - 1;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" << "amount:" << initial_deposit << ";" << "created" << std::endl;
}

//public static member functions
Account::~Account(void)
{
    _nbAccounts--;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->_amount << ";"
              << "closed" << std::endl;
}

int  Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void    Account::displayAccountsInfos(void)
{
    //display general info
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";" 
              << "total:" << _totalAmount << ";" 
              << "deposits:" << _totalNbDeposits << ";" 
              << "withdrawals:" << _totalNbWithdrawals 
              << std::endl;
}

//public non-static member functions
void    Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" 
              << "amount:" << this->_amount << ";"
              << "deposits:" << this->_nbDeposits << ";"
              << "withdrawals:" << this->_nbWithdrawals
              << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "p_amount:" << this->_amount << ";"
              << "deposit:" << deposit << ";"
              << std::flush;
    this->_amount += deposit;
    this->_nbDeposits++;
    std::cout << "amount:" << this->_amount << ";"
              << "nb_deposits:" << this->_nbDeposits
              << std::endl;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "p_amount:" << this->_amount << ";"
              << std::flush;
    this->_amount -= withdrawal;
    if (this->checkAmount() == 0)
    {
        this->_amount += withdrawal;
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
    this->_nbWithdrawals++;
    std::cout << "withdrawal:" << withdrawal << ";"
              << "amout:" << this->_amount << ";"
              << "nb_withdrawals:" << this->_nbWithdrawals
              << std::endl;
    _totalNbWithdrawals++;
    return (true);
}

int Account::checkAmount(void) const
{
    if (this->_amount < 0)
        return (0);
    else
        return (1);
}

//private static member functions
void    Account::_displayTimestamp(void)
{
    std::time_t now = std::time(NULL);
    std::tm *tm_ptr = std::localtime(&now);
    std::cout << std::setfill('0');
    std::cout << "["
              << (tm_ptr->tm_year + 1900)
              << std::setw(2) << (tm_ptr->tm_mon + 1)
              << std::setw(2) << (tm_ptr->tm_mday)
              << "_"
              << std::setw(2) << (tm_ptr->tm_hour)
              << std::setw(2) << (tm_ptr->tm_min)
              << std::setw(2) << (tm_ptr->tm_sec)
              << "] ";
}