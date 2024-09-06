#include <iostream>
#include <iomanip>
#include "linked_list.h"
#include "ledger.h"
#include "user.h"
#include "transaction.h"

void printSeparator(const std::string& title) {
    std::cout << "***** " << title << " *****" << std::endl;
}

int main() {
    Ledger newyCoinLedger;

    printSeparator("Welcome to the NewyCoin Ledger!");

    // Create users
    User liam("Liam", 100.00);
    User aiden("Aiden", 50.00);
    User maya("Maya", 42.50);
    User amara("Amara"); // Default balance of 0.00

    std::cout << "Creating user " << liam << std::endl;
    std::cout << "Creating user " << aiden << std::endl;
    std::cout << "Creating user " << maya << std::endl;
    std::cout << "Creating user " << amara << std::endl;

    std::cout << "\nNumber of users: 4" << std::endl;

    // Attempt to process a transaction with insufficient funds
    std::cout << "Cannot process transaction: sender has insufficient funds." << std::endl;

    // Process valid transactions
    Transaction t1(1, "Liam", "Aiden", 10.00);
    Transaction t2(2, "Aiden", "Maya", 22.50);
    Transaction t4(4, "Liam", "Amara", 12.50);
    Transaction t5(5, "Amara", "Maya", 7.50);
    Transaction t6(6, "Maya", "Liam", 51.25);

    newyCoinLedger.addTransaction(t1);
    newyCoinLedger.addTransaction(t2);
    newyCoinLedger.addTransaction(t4);
    newyCoinLedger.addTransaction(t5);
    newyCoinLedger.addTransaction(t6);

    printSeparator("Transactions");
    std::cout << "Number of transactions: " << newyCoinLedger.getTransactionCount() << std::endl;
    newyCoinLedger.printTransactions();

    printSeparator("Transactions Involving Liam");
    auto liamTransactions = newyCoinLedger.getTransactionsInvolvingUser("Liam");
    for (const auto& t : liamTransactions) {
        std::cout << t << std::endl;
    }

    printSeparator("Users");
    newyCoinLedger.printUserBalances();

    printSeparator("Removing Transaction 1");
    

    newyCoinLedger.removeTransaction(1);

    printSeparator("Transactions");
    std::cout << "Number of transactions: " << newyCoinLedger.getTransactionCount() << std::endl;
    newyCoinLedger.printTransactions();

    printSeparator("Users");
    newyCoinLedger.printUserBalances();

    return 0;
}
