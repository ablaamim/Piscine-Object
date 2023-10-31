#include "Bank.hpp"

// Account class methods
Bank::Account::Account(int id, int value) : id(id), value(value) {}

Bank::Account::~Account() {}

int Bank::Account::getId() const {
    return id;
}

int Bank::Account::getValue() const {
    return value;
}

void Bank::Account::deposit(int amount) {
    value += amount;
}

std::ostream& operator<<(std::ostream& os, const Bank::Account& account) {
    os << "Account ID: " << account.getId() << ", Value: " << account.getValue();
    return os;
}

// Bank class methods
Bank::Bank() : liquidity(10000) {}

Bank::~Bank() {}

void Bank::createAccount(int id, int value) {
    clientAccounts.push_back(Account(id, value));
}

void Bank::deleteAccount(int accountId)
{
    // check if account exists

    if (findAccountIndex(accountId) == -1)
        throw std::out_of_range("Account ID not found");

    int index = findAccountIndex(accountId);
    clientAccounts.erase(clientAccounts.begin() + index);
}

void Bank::depositIntoAccount(int accountId, int amount) {
    int index = findAccountIndex(accountId);
    clientAccounts[index].deposit(amount);
}

void Bank::giveLoan(int accountId, int amount) {
    int index = findAccountIndex(accountId);
    clientAccounts[index].deposit(amount);
    liquidity -= amount;
}

Bank::AccountInfo Bank::getAccountInfo(int accountId) const {
    int index = findAccountIndex(accountId);
    AccountInfo info;
    info.id = clientAccounts[index].getId();
    info.value = clientAccounts[index].getValue();
    return info;
}

int Bank::findAccountIndex(int accountId) const {
    for (size_t i = 0; i < clientAccounts.size(); i++) {
        if (clientAccounts[i].getId() == accountId) {
            return i;
        }
    }
    throw std::out_of_range("Account ID not found");
}

Bank::AccountInfo Bank::operator[](int accountId) const {
    int index = findAccountIndex(accountId);
    if (index == -1) {
        throw std::out_of_range("Account ID not found");
    }
    AccountInfo info;
    info.id = clientAccounts[index].getId();
    info.value = clientAccounts[index].getValue();
    return info;
}

std::ostream& operator<<(std::ostream& os, const Bank& bank) {
    os << "Bank Liquidity: " << bank.liquidity << std::endl;
    for (size_t i = 0; i < bank.clientAccounts.size(); i++) {
        os << bank.clientAccounts[i] << std::endl;
    }
    return os;
}

