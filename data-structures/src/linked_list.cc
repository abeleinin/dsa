#include "linked_list.h"

#include <iostream>

template <typename T>
Node<T>::Node(T value)
    : value(value)
    , next(nullptr)
{}

template <typename T>
Node<T>::Node(T value, Node* next)
    : value(value)
    , next(next)
{}

template <typename T>
LinkedList<T>::LinkedList(T value) {
    head = new Node<T>(value);
    tail = head;
    ++size;
}

template <typename T>
void LinkedList<T>::add(T value) {
    head->next = value;
    head = &value;
    ++size;
}

template <typename T>
void LinkedList<T>::print_list() const {
    if (size == 0) {
        std::cout << "nullptr" << std::endl;
    }

    std::cout << "{ " << head->value;
    for (int i = 1; i < size; ++i) {
        ++head;
        std::cout << " -> " << head->value;
    }
    std::cout << " -> nullptr " << head->value;
}
