#ifndef INHERITANCE_SET_H
#define INHERITANCE_SET_H

#include <iostream>

#include "myvector.h"

template <class Data>
class MySet : public MyVector<Data> {
public:
    MySet(Data g = NULL) : MyVector<Data>(g) {};
    bool operator==(MySet& lot);

    MySet& operator+=(MySet& lot);
    MySet& operator-=(MySet& lot);
    MySet& operator*=(MySet& lot);
    void add_element(Data g);
    bool is_element(Data g);
    friend std::ostream& operator<<(std::ostream& out, MySet& lot) {
        for (int i = 0; i < lot.size; i++) out << lot.data[i] << "  ";
        return out;
    }
    template <class T>
    friend MySet operator+(MySet& l1, MySet& l2);
    template <class T>
    friend MySet operator-(MySet& l1, MySet& l2);
    template <class T>
    friend MySet operator*(MySet& l1, MySet& l2);
    MySet& operator=(MySet lot);
    Data get() { return this->data[0]; }
};


template <class Data>
bool MySet<Data>::operator==(MySet& lot) {
    if (this->size != lot.size) {
        return false;
    }
    else {
        for (int i = 0; i < this->size; i++) {
            if (this->data[i] != lot.data[i]) return false;
        }
    }
    return true;
}

template <class Data>
bool MySet<Data>::is_element(Data g) {
    for (int i = 0; i < this->size; i++) {
        if (g == this->data[i]) return true;
    }
    return false;
}

template <class Data>
MySet<Data>& MySet<Data>::operator*=(MySet<Data>& lot) {
    for (int i = 0; i < lot.size; i++) {
        if (!is_element(lot.data[i])) add_element(lot.data[i]);
    }
    return *this;
}

template <class Data>
MySet<Data>& MySet<Data>::operator-=(MySet<Data>& lot) {
    for (int i = 0; i < lot.size; i++) {
        if (is_element(lot.data[i])) delete_element(find(lot.data[i]));
    }
    return *this;
}

template <class Data>
MySet<Data>& MySet<Data>::operator+=(MySet<Data>& lot) {
    int i = 0;
    while (this->data[i] != NULL) {
        if (!lot.is_element(this->data[i]))
            this->delete_element(i);
        else
            i++;
    }
    return *this;
}


template <class Data>
MySet<Data> operator+(MySet<Data>& l1, MySet<Data>& l2) {
    MySet<Data> temp(l1);
    temp += l2;
    return temp;
}

template <class Data>
MySet<Data> operator-(MySet<Data>& l1, MySet<Data>& l2) {
    MySet<Data> temp(l1);
    temp -= l2;
    return temp;
}

template <class Data>
void MySet<Data>::add_element(Data g) {
    if (!is_element(g)) {
        if (this->size < this->max_size) {
            this->data[this->size] = g;
            this->size++;
        }
        else {
            Data* temp = new Data[this->size + 1];  
            for (int i = 0; i < this->size; i++) temp[i] = this->data[i];
            temp[this->size] = g;
            delete[] this->data;
            this->size++;
            this->max_size++;
            this->data = temp;
        }
        this->sort();
    }
}

template <class Data>
MySet<Data> operator*(MySet<Data>& l1, MySet<Data>& l2) {
    MySet<Data> temp(l1);
    temp *= l2;
    return temp;
}

template <>
bool MySet<char*>::is_element(char* g) {
    if ((*this).find(g) == -1) { return 0; }
    return 1;
}

template <>
bool MySet<char*>::operator==(MySet<char*>& lot) {
    if (this->size != lot.size) return false;
    for (int i = 0; i < this->size; i++) {
        if (strcmp(this->data[i], lot.data[i]) != 0) return false;
    }
    return true;
}

template <>
void MySet<char*>::add_element(char* g) {
    if (!is_element(g)) {
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
            max_size++;
            size++;
            delete[] data;
            data = temp;
        }
        sort();
    }
}

template <>
MySet<char*>& MySet<char*>::operator=(MySet<char*> lot) {
    for (int i = 0; i < size; i++) delete[] data[i];
    delete[] data;

    this->size = lot.size;
    this->max_size = lot.size;
    data = new char* [size];
    for (int i = 0; i < size; i++) {
        data[i] = new char[strlen(lot.data[i]) + 1];
        strcpy(data[i], lot.data[i]);
    }
    return *this;
}

template <>
MySet<char*>& MySet<char*>::operator-=(MySet<char*>& lot) {
    for (int i = 0; i < lot.size; i++) {
        if (is_element(lot.data[i])) delete_element(find(lot.data[i]));
    }
    return *this;
}

template <>
inline MySet<char*>& MySet<char*>::operator += (MySet<char*>& lt) {          //////////
    for (int i{}; i < lt.size; ++i) {
        if ((*this).find((lt.data)[i]) == -1) {
            (*this).add_element(lt.data[i]);
        }
    }
    return *this;
}

template <>
MySet<char*>& MySet<char*>::operator*=(MySet<char*>& lot) {
    for (int i = 0; i < lot.size; i++) {
        if (!is_element(lot.data[i])) add_element(lot.data[i]);
    }
    return *this;
}

template <char*>
MySet<char*> operator+(MySet<char*>& l1, MySet<char*>& l2) {        
    MySet<char*> lt;
    for (int i{}; i < l1.size; ++i) {
        lt.add_element(l1[i]);
    }
    for (int i{}; i < l2.size; ++i) {
        if (lt.find(l2[i]) == -1) {
            lt.add_element(l2[i]);
        }
    }
    return lt;
}

template <char*>
MySet<char*> operator*(MySet<char*>& l1, MySet<char*>& l2) {
    MySet<char*> temp(l1);
    temp *= l2;
    return temp;
}

template <char*>
MySet<char*> operator-(MySet<char*>& l1, MySet<char*>& l2) {
    MySet<char*> temp(l1);
    temp -= l2;
    return temp;
}

#endif  // INHERITANCE_SET_H
