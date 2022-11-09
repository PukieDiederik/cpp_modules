#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructors/Destructors
Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	++_nbAccounts;

	_amount = initial_deposit;
	_totalAmount += initial_deposit;

	_nbDeposits = 0;
	_nbWithdrawals = 0;

	//print creation
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}
Account::~Account( void )
{
	//print deletion
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

// Getters/Setters
int	Account::getNbAccounts( void ) { return _nbAccounts; }
int	Account::getTotalAmount( void ) { return _totalAmount; }
int	Account::getNbDeposits( void ) { return _totalNbDeposits; }
int	Account::getNbWithdrawals( void ) { return _totalNbDeposits; }
int	Account::checkAmount( void ) const { return _amount; }

void	Account::makeDeposit( int deposit )
{
	_amount += deposit;
	_totalAmount += deposit;
	++_nbDeposits;
	++_totalNbDeposits;

	//print deposits
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit
			  << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits <<  std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (_amount - withdrawal < 0)
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
		return false;
	}

	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	++_nbWithdrawals;
	++_totalNbWithdrawals;

	//printing
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal << ";withdrawal:" << withdrawal
			  << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals <<  std::endl;
	return true;
}

void	Account::_displayTimestamp( void )
{
	time_t now = time(0);
	tm *t = std::localtime(&now);
	std::cout << std::setfill('0') <<  "[" << t->tm_year + 1900 << std::setw(2) <<t->tm_mon << std::setw(2)
			  << t->tm_mday << "_" << std::setw(2) << t->tm_hour << std::setw(2) << t->tm_min << std::setw(2)
			  << t->tm_sec << "] ";
}
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << std::endl;
}
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
