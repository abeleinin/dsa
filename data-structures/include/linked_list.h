#pragma once

#include <cstddef>

template <typename T>
class Node {
public:
    Node(T value);

    Node(T value, Node* next);

private:
    T value;
    Node* next;
};

template <typename T>
class LinkedList {
public:
    LinkedList();

    ~LinkedList();

    LinkedList(T value);

    void add(T value);

    void prepend(T value);

    void insert(size_t index, T value);

    void remove(T value);

    void remove_at(size_t index);

    Node<T>* find(T value);

    T get(T value) const;

    void set(size_t index, T value);

    bool is_empty() const;

    void print_list() const;

    size_t get_size() const;

private:
    Node<T>* head;

    Node<T>* tail;

    size_t size = 0;
};

