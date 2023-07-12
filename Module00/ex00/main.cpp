#include "main.hpp"

int main()
{
    Account accountA = Account();
    
    accountA.setId(0);
    accountA.setValue(100);

    std::cout << accountA.getId() << std::endl;
    std::cout << accountA.getValue() << std::endl;
    
    Account accountB = Account();
    accountB.setId(1);
    accountB.setValue(100);

    std::cout << accountB.getId() << std::endl;
    std::cout << accountB.getValue() << std::endl;

    return (EXIT_SUCCESS);
}