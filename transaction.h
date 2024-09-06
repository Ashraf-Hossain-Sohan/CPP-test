#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED

#include <iostream>
#include <string>

class Transaction {
public:
    // Constructor
    Transaction(int transactionID, const std::string& senderID, const std::string& receiverID, double amount);

    // Accessor methods
    int getTransactionID() const;
    std::string getSenderID() const;
    std::string getReceiverID() const;
    double getAmount() const;

    // Mutator methods
    void setSenderID(const std::string& senderID);
    void setReceiverID(const std::string& receiverID);
    void setAmount(double amount);

    // Check if the transaction involves a particular user
    bool involves_user(const std::string& user_id) const;

    // Overloaded operators
    bool operator==(const Transaction& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Transaction& transaction);

private:
    int transactionID;     // Unique identifier for the transaction
    std::string senderID;  // ID of the user sending the cryptocurrency
    std::string receiverID; // ID of the user receiving the cryptocurrency
    double amount;          // Amount of cryptocurrency being transferred
};

#endif // TRANSACTION_H_INCLUDED
