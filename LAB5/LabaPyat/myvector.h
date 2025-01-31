#ifndef INHERITANCE_VECTOR_H
#define INHERITANCE_VECTOR_H

#include <iostream>
#include <string>

const int MAX_SIZE = 5;

template <class Data>
class MyVector {
protected:
    int max_size;
    int size;
    Data* data;
    void resize();

public:
    MyVector(Data g = NULL, int max_size = MAX_SIZE);
    MyVector(MyVector<Data>& vec);
    ~MyVector();
    int get_size() { return size; }
    int get_max_size() { return max_size; }
    int find(Data g);
    void add_element(Data g);
    void delete_element(int index);
    void sort();
    MyVector<Data>& operator=(MyVector<Data>& vec);
    friend std::ostream& operator<<(std::ostream& out, MyVector<Data>& vec) {
        for (int i = 0; i < vector.get_size(); i++) {
            out << vector.data[i] << "  ";
        }
        return out;
    };
    Data operator[](int i);
    Data get() { return this->data[0]; }
};

template <class Data>
MyVector<Data>::~MyVector() {
    delete[] data;
}

template <class Data>
MyVector<Data>::MyVector(Data g, int max_size) {
    size = 1;
    data = new Data[max_size];
    data[0] = g;
    this->max_size = max_size;
}

template <class Data>
MyVector<Data>::MyVector(MyVector<Data>& vec) {
    if (&this != vec) {
        max_size = vec.max_size;
        size = vec.size;
        data = new Data[max_size];
        for (int i = 0; i < size; i++) {
            data[i] = vec.data[i];
        }
    }
}

template <class Data>
void MyVector<Data>::add_element(Data g) {
    if (find(g) == -1) {
        data[size + 1] = g;
        size++;
        this->resize();
    }
}

template <class Data>
int MyVector<Data>::find(Data g) {
    for (int i = 0; i < size; i++) {
        if (data[i] == g) return i;
    }
    return -1;
}

template <class Data>
void MyVector<Data>::resize() {
    if (size > max_size) {
        max_size *= 2;
    }
    if (size < max_size / 4) {
        max_size /= 2;
    }
    Data* temp = new Data[max_size];
    for (int i = 0; i < size; i++) {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
}

template <class Data>
void MyVector<Data>::delete_element(int index) {
    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size--;
    this->resize();
}

template <class Data>
MyVector<Data>& MyVector<Data>::operator=(MyVector<Data>& vec) {
    if (data != nullptr) {
        delete[] data;
    }
    data = new Data[vec.max_size];
    size = vec.size;
    max_size = vec.max_size;
    for (int i = 0; i < size; i++) {
        data[i] = vec.data[i];
    }
    return *this;
}

template <class Data>
void MyVector<Data>::sort() {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (strcmp(data[i] > data[j])) {
                Data temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

template <class Data>
Data MyVector<Data>::operator[](int i) {
    return data[i];
}

// ДЛЯ КЛАССА <char*> //
template <>
MyVector<char*>::MyVector(char* g, int max_size) {
    this->max_size = max_size;
    size = 0;
    data = new char* [max_size];
    if (g != nullptr) {
        data[0] = new char[strlen(g) + 1];
        strcpy(data[0], g);
        size++;
    }
    else {
        data[0] = nullptr;
    }
    for (int i = 1; i < max_size; ++i) {
        data[i] = nullptr;
    }
}

template <>
MyVector<char*>::MyVector(MyVector<char*>& vec) {
    data = new char* [vec.max_size];
    size = vec.size;
    max_size = vec.max_size;
    for (int i = 0; i < size; ++i) {
        data[i] = new char[strlen(vec.data[i]) + 1];
        strcpy(data[i], vec.data[i]);
    }
}

template <>
MyVector<char*>::~MyVector() {
    for (int i = 0; i < size; i++) {
        delete[] data[i];
    }
    delete[] data;
}

template <>
void MyVector<char*>::resize() {
    if (size > max_size) {
        max_size *= 2;
    }
    if (size < max_size / 4) {
        max_size /= 2;
    }
}

template <>
void MyVector<char*>::add_element(char* g) {
    if (size < max_size) {
        data[size] = new char[strlen(g) + 1];
        strcpy(data[size], g);
        size++;
    }
    else {
        char** temp = new char* [max_size + 1];
        for (int i = 0; i < size; i++) {
            temp[i] = new char[strlen(data[i]) + 1];
            strcpy(temp[i], data[i]);
        }
        temp[size] = new char[strlen(g) + 1];
        strcpy(temp[size], g);

        for (int i = 0; i < size; i++) delete[] data[i];
        delete[] data;
        data = temp;

        size++;
        this->resize();
    }
}

template <>
void MyVector<char*>::delete_element(int index) {
    for (int i = index; i < size - 1; i++) {
        delete[] data[i];
        data[i] = new char[strlen(data[i + 1]) + 1];
        strcpy(data[i], data[i + 1]);
    }
    delete[] data[size - 1];   /// -1
    data[size - 1] = nullptr;  /// -1
    size--;
    this->resize();
}

template <>
void MyVector<char*>::sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(data[i], data[j]) > 0) {
                char* temp = new char[strlen(data[i]) + 1];
                strcpy(temp, data[i]);

                delete[] data[i];
                data[i] = new char[strlen(data[j]) + 1];
                strcpy(data[i], data[j]);

                delete[] data[j];
                data[j] = new char[strlen(temp) + 1];
                strcpy(data[j], temp);
                delete[] temp;
            }
        }
    }
}


template <>
int MyVector<char*>::find(char* g) {
    int index{ -1 };
    for (int i = 0; i < size; ++i) {
        if (g != NULL) {
            if (!strcmp(data[i], g)) { 
                index = i; break; 
            }
        }
    }
    return index;
}

template <>
MyVector<char*>& MyVector<char*>::operator=(MyVector<char*>& vec) {
    if (data != nullptr) {
        for (int i = 0; i < size; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    this->size = vec.size;
    this->max_size = vec.max_size;

    data = new char* [size];
    for (int i = 0; i < size; i++) {
        this->data[i] = new char[strlen(vec.data[i]) + 1];
        strcpy(this->data[i], vec.data[i]);
    }
    return *this;
}

template <>
char* MyVector<char*>::operator[](int i) {
    return data[i];
}


#endif  // INHERITANCE_VECTOR_H
