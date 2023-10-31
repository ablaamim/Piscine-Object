#include "Bank.hpp"
#include <iostream>

int main() {
    Bank bank;
    try {
        // Create accounts
        bank.createAccount(1, 1000);
        bank.createAccount(2, 2000);

        // Deposit into account
        bank.depositIntoAccount(1, 500);

        // Give loan
        bank.giveLoan(2, 300);

        // Print bank details
        std::cout << std::endl << bank << std::endl << std::endl;

        // Get and print account info
        Bank::AccountInfo accountInfo = bank.getAccountInfo(1);
        std::cout << "Account 1 ID: " << accountInfo.id << ", Value: " << accountInfo.value << std::endl;

        // Delete an account
        bank.deleteAccount(1);
        std::cout << "After deleting account 1:" << std::endl;
        
        std::cout << std::endl << bank << std::endl << std::endl;

        //bank.deleteAccount(47);

        // Access account using operator[]
        const Bank::AccountInfo accountRef = bank[2]; 
        std::cout << "Account ID: " << accountRef.id << ", Value: " << accountRef.value << std::endl;

        //const Bank::AccountInfo accountRef2 = bank[-10]; // Assuming index 0 exists

        // bank.depositIntoAccount(99, 100); // Deposit into non-existent account
        // bank.giveLoan(99, 200); // Give loan to non-existent account
        // Bank::AccountInfo nonExistentAccountInfo = bank.getAccountInfo(99); // Access non-existent account
        // bank.deleteAccount(99); // Delete non-existent account

        // test negative value

        //bank.createAccount(3, -1000);

        //std::cout << bank << std::endl;

    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}





