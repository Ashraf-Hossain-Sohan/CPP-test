// transaction.cpp

#include "transaction.h"

// Constructor
Transaction::Transaction(int transactionID, const std::string& senderID, const std::string& receiverID, double amount)
    : transactionID(transactionID), senderID(senderID), receiverID(receiverID), amount(amount) {}

// Accessor Methods
int Transaction::getTransactionID() const {
    return transactionID;
}

std::string Transaction::getSenderID() const {
    return senderID;
}

std::string Transaction::getReceiverID() const {
    return receiverID;
}

double Transaction::getAmount() const {
    return amount;
}

// Mutator Methods
void Transaction::setSenderID(const std::string& senderID) {
    this->senderID = senderID;
}

void Transaction::setReceiverID(const std::string& receiverID) {
    this->receiverID = receiverID;
}

void Transaction::setAmount(double amount) {
    this->amount = amount;
}

// Check if the transaction involves a particular user
bool Transaction::involves_user(const std::string& user_id) const {
    return (senderID == user_id || receiverID == user_id);
}

// Overload the equality operator to compare two transactions by their ID
bool Transaction::operator==(const Transaction& other) const {
    return transactionID == other.transactionID;
}

// Overload the stream insertion operator for printing the transaction details
std::ostream& operator<<(std::ostream& os, const Transaction& transaction) {
    os << "Transaction ID: " << transaction.transactionID
       << ", Sender: " << transaction.senderID
       << ", Receiver: " << transaction.receiverID
       << ", Amount: $" << transaction.amount;
    return os;
}
