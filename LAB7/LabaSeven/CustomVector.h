#ifndef CUSTOMVECTOR_H
#define CUSTOMVECTOR_H

#include <iostream>

template <typename T>
class CustomVector {
private:
    T* data;
    size_t capacity;
    size_t size;

    void resize() {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        T* newData = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    CustomVector() : data(nullptr), capacity(0), size(0) {}

    ~CustomVector() {
        clear();
    }

    void push_back(T value) {
        if (size == capacity) {
            resize();
        }
        data[size++] = value;
    }

    T at(size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    size_t getSize() const {
        return size;
    }

    void remove(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        delete data[index];
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    void clear() {
        for (size_t i = 0; i < size; ++i) {
            delete data[i];
        }
        delete[] data;
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << "Index " << i << ": ";
            data[i]->show();
        }
    }
};

#endif // CUSTOMVECTOR_H
