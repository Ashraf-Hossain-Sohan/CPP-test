#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <iostream>
#include <string>

class User {
public:
    // Constructor
    User(const std::string& id, double balance = 0.0);

    // Getter methods
    std::string getID() const;
    double getBalance() const;

    // Method to modify balance
    void updateBalance(double amount);

    // Overloaded operators
    bool operator==(const User& other) const;
    friend std::ostream& operator<<(std::ostream& os, const User& user);

private:
    std::string id;      // Unique identifier for the user
    double balance;      // Balance of the user
};

#endif // USER_H_INCLUDED
