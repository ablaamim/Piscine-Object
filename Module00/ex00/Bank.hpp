#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <vector>
#include <stdexcept>

class Bank {
private:
    class Account {
    private:
        int id;
        int value;

    public:
        Account(int id, int value);
        ~Account();
        int getId() const;
        int getValue() const;
        void deposit(int amount);
    };

    int liquidity;
    std::vector<Account> clientAccounts;
    int findAccountIndex(int accountId) const;

public:
    struct AccountInfo {
        int id;
        int value;
    };

    Bank();
    ~Bank();
    void createAccount(int id, int value);
    void deleteAccount(int accountId);
    void depositIntoAccount(int accountId, int amount);
    void giveLoan(int accountId, int amount);
    AccountInfo getAccountInfo(int accountId) const;

    AccountInfo operator[](int accountId) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Bank& bank);
    friend std::ostream& operator<<(std::ostream& os, const Account& account);
};

#endif // BANK_HPP




