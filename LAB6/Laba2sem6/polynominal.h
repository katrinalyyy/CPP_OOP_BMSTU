#pragma once
#include "term.h"

class Polynomial {
private:
    Term* terms;       
    int capacity, count; 
    int sortingOrder;   
public:
    Polynomial(Term term, int num, int cap, int sortOrder); 
    Polynomial();
    ~Polynomial();
    Polynomial(const Polynomial& other); // copy
    void addTerm(Term term); 
    void removeTerm(int index); 
    friend std::istream& operator>>(std::istream& in, Polynomial& p);
    friend std::ostream& operator<<(std::ostream& out, const Polynomial& p);
    Polynomial& add(Polynomial& other);
    void addTerm(int coef, int exp);
    Polynomial& multiply(Polynomial& other);
    void sort();
    Polynomial& operator*=(Polynomial& other);
    Polynomial& operator=(const Polynomial& other);
    Polynomial& operator+=(Polynomial& other);
    friend Polynomial operator+(Polynomial& p1, Polynomial& p2);
    friend Polynomial operator*(Polynomial& p1, Polynomial& p2);
};
