#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex 
                << ";amount:" << _amount
                << ";created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts()
{
    return _nbAccounts;
}

int Account::getTotalAmount()
{
    return _totalAmount;
}

int Account::getNbDeposits()
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout   << " accounts:" << _nbAccounts << ";total:"
                << _totalAmount << ";deposits:"
                << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp()
{
    time_t time = std::time(0);
    std::tm *local_time = std::localtime(&time);
    char buffer[20];

    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", local_time);

    std::cout << buffer;
}

void Account::makeDeposit (int deposit)
{
    this->_amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
    _nbDeposits++;

    _displayTimestamp();
    std::cout   << " index:" << _accountIndex
                << ";p_amount:" << _amount - deposit
                << ";deposit:" << deposit
                << ";amount:" << _amount
                << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawals)
{
    if (this->_amount < withdrawals)
    {
        _displayTimestamp();
        std::cout   << " index:" << _accountIndex
                << ";p_amount:" << _amount
                << ";withdrawal:refused" << std::endl;
        return false;
    }

    _amount -= withdrawals;
    _totalAmount -= withdrawals;
    _totalNbWithdrawals++;
    _nbWithdrawals++;

    _displayTimestamp();
    std::cout   << " index:" << _accountIndex
                << ";p_amount:" << _amount + withdrawals
                << ";withdrawal:" << withdrawals
                << ";amount:" << _amount
                << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    
    return true;
}

int Account::checkAmount() const
{
    return this->_amount;
}

void Account::displayStatus() const
{
    _displayTimestamp();

    std::cout << " index:" << this->_accountIndex
                << ";amount:" << this->_amount
                << ";deposits:" << this->_nbDeposits
                << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
