// linked_list.hpp

#include "linked_list.h"

// Constructor
template <typename T>
LinkedList<T>::LinkedList() {
    init();
}

// Copy constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList& other) {
    init();
    copy(other);
}

// Copy assignment
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other) {
    if (this != &other) {
        destroy();
        init();
        copy(other);
    }
    return *this;
}
// Remove an element by index
template <typename T>
void LinkedList<T>::remove(size_t index) {
    if (index >= list_size) throw std::out_of_range("Index out of range");
    Node* current = head->next;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    --list_size;
}

// Destructor
template <typename T>
LinkedList<T>::~LinkedList() {
    destroy();
}

// Initialize the list
template <typename T>
void LinkedList<T>::init() {
    head = new Node();  // Sentinel head node
    tail = new Node();  // Sentinel tail node
    head->next = tail;
    tail->prev = head;
    list_size = 0;
}

// Copy elements from another list
template <typename T>
void LinkedList<T>::copy(const LinkedList& other) {
    Node* current = other.head->next;
    while (current != other.tail) {
        push_back(current->data);
        current = current->next;
    }
}

// Destroy the list
template <typename T>
void LinkedList<T>::destroy() {
    clear();
    delete head;
    delete tail;
}

// Add an element to the front
template <typename T>
void LinkedList<T>::push_front(const T& value) {
    Node* newNode = new Node(value, head->next, head);
    head->next->prev = newNode;
    head->next = newNode;
    ++list_size;
}

// Add an element to the back
template <typename T>
void LinkedList<T>::push_back(const T& value) {
    Node* newNode = new Node(value, tail, tail->prev);
    tail->prev->next = newNode;
    tail->prev = newNode;
    ++list_size;
}

// Remove an element from the front
template <typename T>
void LinkedList<T>::pop_front() {
    if (is_empty()) throw std::underflow_error("List is empty");
    Node* toDelete = head->next;
    head->next = toDelete->next;
    toDelete->next->prev = head;
    delete toDelete;
    --list_size;
}

// Remove an element from the back
template <typename T>
void LinkedList<T>::pop_back() {
    if (is_empty()) throw std::underflow_error("List is empty");
    Node* toDelete = tail->prev;
    tail->prev = toDelete->prev;
    toDelete->prev->next = tail;
    delete toDelete;
    --list_size;
}

// Check if the list is empty
template <typename T>
bool LinkedList<T>::is_empty() const {
    return list_size == 0;
}

// Get the size of the list
template <typename T>
size_t LinkedList<T>::size() const {
    return list_size;
}

// Clear the list
template <typename T>
void LinkedList<T>::clear() {
    while (!is_empty()) {
        pop_front();
    }
}

// Print the list contents
template <typename T>
void LinkedList<T>::print() const {
    Node* current = head->next;
    while (current != tail) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

