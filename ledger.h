#ifndef LEDGER_H_INCLUDED
#define LEDGER_H_INCLUDED
#include <string>
#include <vector>
#include "linked_list.h"
#include "transaction.h"
#include <iostream>
#include <iomanip>
#include <algorithm>


class Ledger : private LinkedList<Transaction> {
public:
    // Constructor and Destructor
    Ledger() = default;
    ~Ledger() = default;

    // Add a transaction to the ledger
    void addTransaction(const Transaction& transaction);

    // Remove a transaction from the ledger by its ID
    bool removeTransaction(int transactionID);

    // Retrieve all transactions involving a specific user
    std::vector<Transaction> getTransactionsInvolvingUser(const std::string& userID) const;

    // Get all transactions in the ledger
    std::vector<Transaction> getAllTransactions() const;

    // Get the balance of a user
    double getUserBalance(const std::string& userID) const;

    // Print all users and their balances
    void printUserBalances() const;

    // Print all transactions
    void printTransactions() const;

    // Get the number of transactions
    size_t getTransactionCount() const;

private:
    // Helper method to find a transaction by ID
    size_t findTransactionIndex(int transactionID) const;
};


void Ledger::addTransaction(const Transaction& transaction) {
    
}

bool Ledger::removeTransaction(int transactionID) {
    
}

std::vector<Transaction> Ledger::getTransactionsInvolvingUser(const std::string& userID) const {
    
}

std::vector<Transaction> Ledger::getAllTransactions() const {
    
}

double Ledger::getUserBalance(const std::string& userID) const {
    
}

void Ledger::printUserBalances() const {
    
}

void Ledger::printTransactions() const {
    
}

size_t Ledger::findTransactionIndex(int transactionID) const {
    
    }

#endif // LEDGER_H_INCLUDED
