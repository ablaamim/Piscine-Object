#ifndef CUSTOMERACCOUNTSYSTEM_HPP
# define CUSTOMERACCOUNTSYSTEM_HPP

#include "BankingSystem.hpp"
#include <iostream>
#include <vector>

class Account
{
    private :
        int id;
        int value;
    public :
        // Canonical form
        Account();
        ~Account();
        Account(const Account &p_account);
        Account &operator=(const Account &p_account);
        friend std::ostream& operator<<(std::ostream& p_os, const Account& p_account);

        // Getters and setters

        int getId() const;
        void setId(int p_id);
        int getValue() const;
        void setValue(int p_value);
};

#endif