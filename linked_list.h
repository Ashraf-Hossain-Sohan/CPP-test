#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include <iostream>
#include <stdexcept>

// Templated LinkedList class
template <typename T>
class LinkedList {
public:
    // Nested Node structure
    struct Node {
        T data;
        Node* next;
        Node* prev;

        // Constructor for a new node
        Node(const T& data = T{}, Node* next = nullptr, Node* prev = nullptr)
            : data(data), next(next), prev(prev) {}
    };

    // Constructors and Destructor
    LinkedList();                     // Default constructor
    LinkedList(const LinkedList& other); // Copy constructor
    LinkedList& operator=(const LinkedList& other); // Copy assignment
    ~LinkedList();                    // Destructor

    // Methods for list operations
    void LinkedList<T>::remove(size_t index);
    void push_front(const T& value);   // Add an element to the front
    void push_back(const T& value);    // Add an element to the back
    void pop_front();                  // Remove an element from the front
    void pop_back();                   // Remove an element from the back
    bool is_empty() const;             // Check if the list is empty
    size_t size() const;               // Get the size of the list
    void clear();                      // Clear the list
    void print() const;                // Print the list contents

    // Additional utility functions can be declared here...

private:
    Node* head;  // Pointer to the sentinel head node
    Node* tail;  // Pointer to the sentinel tail node
    size_t list_size;  // Number of elements in the list

    // Helper functions
    void init();                      // Helper function to initialize list
    void copy(const LinkedList& other); // Helper function to copy from another list
    void destroy();                   // Helper function to delete all nodes
};

#endif // LINKED_LIST_H_INCLUDED
