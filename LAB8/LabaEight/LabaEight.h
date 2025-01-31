#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>

void printVector(std::vector<float>& vec);
void printList(std::list<int>& cont, int x);


class Card {
    std::string title;   // заглавие книги
    std::string author;  // автор
    int number;          // количество имеющихся экземпляров
public:
    Card() : title(""), author(""), number(0) {}
    Card(std::string t, std::string a, int n) : title(t), author(a), number(n) {}

    std::string get_author(){
        return author;
    }

    void print(){
        std::cout << "книга: " << title << " автор: " << author << " количество: " << number << std::endl;
    }
};


class Complex {
    double real; 
    double imag;

public:
    Complex(double r, double i) : real(r), imag(i) {}

    void print() {
        std::cout << real;
        if (imag >= 0) {
            std::cout << " + i * " << imag;
        }
        else {
            std::cout << " - i * " << -imag;
        }
        std::cout << std::endl;
    }

    Complex operator+(Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }
};