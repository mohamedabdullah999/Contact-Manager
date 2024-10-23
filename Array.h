#ifndef ARRAY_H
#define ARRAY_H
#include "Person.h"
#include "Address.h"
#include <iostream>
#include <stdexcept>

template<class T>
class Array {
private:
    int size;
    T* Arr;
    int capacity;
    void resize(size_t newcapacity) {
        T* newptr = new T[newcapacity]; // alocate new storage in memory
        for (size_t i = 0; i < getSize(); i++) {
            newptr[i] = Arr[i]; // copy
        }
        delete[] Arr; // release
        Arr = newptr;//equality
    }

public:
    Array(int cap = 10000) : size(0), capacity(cap) {
        Arr = new T[capacity]; 
    }

    ~Array() { 
        delete[] Arr;//To keep memory clean
    }

    Array(Array& coppy) {
        size = coppy.size;
        Arr = new T[size];
        for (int i = 0; i < size; i++) {
            Arr[i] = coppy.Arr[i];
        }
    }

    void Append(T object) {
        if (size >= capacity) {
            resize(capacity * 2);
        }
        Arr[size++] = object; 
    }

    void Insert(T element, int index) {
        if (index > size) {
            throw out_of_range("Index out of range");
        }
        if (size >= capacity) {
            resize(capacity * 2);
        }
        if (index <=  0) {
            throw out_of_range("Index out of range");
        }
        for (int i = size; i > index; i--) {
            Arr[i] = Arr[i - 1];
        }
        Arr[index] = element;
        size++;

    }
    
    T& get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return Arr[index]; 
    }

    void reversearr() {
        size_t start = 0;
        size_t end = size - 1;
        while (start < end) {
            swap(Arr[start], Arr[end]);
            start++;
            end--;
        }
    }

    void set(int index, const T& value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Arr[index] = value;
    }
    
    int getSize() const {
        return size; 
    }

    void Remove() {
        if (size == 0) {
            throw underflow_error("Array is empty");
        }
        size--;
    }

    void Delete(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        for (int i = index; i < size - 1; i++) {
            Arr[i] = Arr[i + 1];
        }
        size--;
        if(size <= capacity / 4){
            resize(capacity / 2);
        }
    }

    void Display() {
        for (int i = 0; i < size; i++) {
            cout << Arr[i];
        }
    }

    Array& operator=(const Array& coppy) {
        if (this != &coppy) {
            delete[]Arr;
            size = coppy.size;
            Arr = new T[size];
            for (int i = 0; i < size; i++) {
                Arr[i] = coppy.Arr[i];
            }
        }
        return* this;
    }

    // Operator[] overload for non-const objects
    T& operator[](int index) {
        if (index >= 0 && index < size) {
            return Arr[index];
        }
        throw out_of_range("Index out of bounds");
    }

    // Operator[] overload for const objects
    const T& operator[](int index) const {
        if (index >= 0 && index < size) {
            return Arr[index];
        }
        throw out_of_range("Index out of bounds");
    }
};
#endif 
