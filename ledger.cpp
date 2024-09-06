#ifndef LEDGER_H_INCLUDED
#define LEDGER_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "linked_list.h"
#include "transaction.h"

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
    size_t getTransactionCount() const { return size(); }

private:
    // Helper method to find a transaction by ID
    size_t findTransactionIndex(int transactionID) const;
};

// Implementation

void Ledger::addTransaction(const Transaction& transaction) {
    push_back(transaction);
}

bool Ledger::removeTransaction(int transactionID) {
    size_t index = findTransactionIndex(transactionID);
    if (index < size()) {
        LinkedList<Transaction>::pop_front(); // Replace with appropriate deletion logic
        return true;
    }
    return false;
}

std::vector<Transaction> Ledger::getTransactionsInvolvingUser(const std::string& userID) const {
    std::vector<Transaction> transactions;
    for (size_t i = 0; i < size(); ++i) {
        if (LinkedList<Transaction>::operator[](i).involves_user(userID)) {
            transactions.push_back(LinkedList<Transaction>::operator[](i));
        }
    }
    return transactions;
}

std::vector<Transaction> Ledger::getAllTransactions() const {
    std::vector<Transaction> transactions;
    for (size_t i = 0; i < size(); ++i) {
        transactions.push_back(LinkedList<Transaction>::operator[](i));
    }
    return transactions;
}

double Ledger::getUserBalance(const std::string& userID) const {
    double balance = 0.0;
    for (size_t i = 0; i < size(); ++i) {
        const Transaction& transaction = LinkedList<Transaction>::operator[](i);
        if (transaction.getSenderID() == userID) {
            balance -= transaction.getAmount();
        } else if (transaction.getReceiverID() == userID) {
            balance += transaction.getAmount();
        }
    }
    return balance;
}

void Ledger::printUserBalances() const {
    std::vector<std::string> users;
    for (size_t i = 0; i < size(); ++i) {
        const Transaction& transaction = LinkedList<Transaction>::operator[](i);
        if (std::find(users.begin(), users.end(), transaction.getSenderID()) == users.end()) {
            users.push_back(transaction.getSenderID());
        }
        if (std::find(users.begin(), users.end(), transaction.getReceiverID()) == users.end()) {
            users.push_back(transaction.getReceiverID());
        }
    }
    for (const std::string& user : users) {
        std::cout << user << ": $" << std::fixed << std::setprecision(2) << getUserBalance(user) << std::endl;
    }
}

void Ledger::printTransactions() const {
    for (size_t i = 0; i < size(); ++i) {
        std::cout << LinkedList<Transaction>::operator[](i) << std::endl;
    }
}

size_t Ledger::findTransactionIndex(int transactionID) const {
    for (size_t i = 0; i < size(); ++i) {
        if (LinkedList<Transaction>::operator[](i).getTransactionID() == transactionID) {
            return i;
        }
    }
    return size(); // Return size() if not found
}

#endif // LEDGER_H_INCLUDED