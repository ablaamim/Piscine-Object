#include "CustomerAccountSystem.hpp"

Account::Account() : id(-1), value(0)
{
    std::cout << "Account constructor called" << std::endl;
}

Account::~Account()
{
    std::cout << "Account destructor called" << std::endl;
}

Account::Account(const Account &p_account)
{
    std::cout << "Account copy constructor called" << std::endl;
    *this = p_account;
}

Account &Account::operator=(const Account &p_account)
{
    std::cout << "Account operator = called" << std::endl;
    if (this != &p_account)
    {
        this->id = p_account.id;
        this->value = p_account.value;
    }
    return (*this);
}

std::ostream& operator<<(std::ostream& p_os, const Account& p_account)
{
    p_os << "Account id: " << p_account.id << " value: " << p_account.value;
    return (p_os);
}

int Account::getId() const
{
    return (this->id);
}

void Account::setId(int p_id)
{
    this->id = p_id;
}

int Account::getValue() const
{
    return (this->value);
}

void Account::setValue(int p_value)
{
    this->value = p_value;
}