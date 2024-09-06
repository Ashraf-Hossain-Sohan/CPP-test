// user.cpp

#include "user.h"

// Constructor
User::User(const std::string& id, double balance) : id(id), balance(balance) {}

// Get the user's ID
std::string User::getID() const {
    return id;
}

// Get the user's balance
double User::getBalance() const {
    return balance;
}

// Update the user's balance by adding or subtracting an amount
void User::updateBalance(double amount) {
    balance += amount;
}

// Overload the equality operator to compare two users based on their ID
bool User::operator==(const User& other) const {
    return id == other.id;
}

// Overload the stream insertion operator for printing the user details
std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "User ID: " << user.id << ", Balance: $" << user.balance;
    return os;
}
