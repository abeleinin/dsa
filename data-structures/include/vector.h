#pragma once

#include <cstddef>
#include <iostream>

template <typename T>
class Vector {
public:
    Vector() {
      m_data = new T[1];
      m_capacity = 1;
      m_size = 0;
    }

    Vector(int size) {
      m_data = new T[2*size];
      m_capacity = 2*size;
      m_size = size;
    }

    ~Vector() {
      delete[] m_data;
    }

    size_t size() const {
      return m_size;
    }

    T& at(size_t index);

    const T& at(size_t index) const;

    size_t capacity() const;

    bool is_empty() const;

    void push_back(const T& value) {
      if (m_size == m_capacity) {
        T* temp = new T[2*m_capacity];

        for (int i = 0; i < m_capacity; ++i)  {
          temp[i] = m_data[i];
        }

        delete[] m_data;
        m_data = temp;
        m_capacity *= 2;
      }

      m_data[m_size] = value; 
      m_size++;
    }

    void pop_back() {
      m_size--;
    }

    void insert(size_t index, const T& value);

    void remove(size_t index);

    void clear() {
      m_size = 0;
    }

    void reserve(size_t new_capacity) {
      m_capacity = new_capacity;
    }

    void shrink_to_fit();

    void print() const {
      std::cout << "[";
      for (int i = 0; i < m_size; ++i) {
        std::cout << to_string(m_data[i]);
        if (i != m_size - 1)
          std::cout << ", ";
      }
      std::cout << "]" << std::endl;
    }
  
private:
  T* m_data;

  int m_size;
  
  int m_capacity;
};
