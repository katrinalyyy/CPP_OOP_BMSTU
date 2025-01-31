#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

char* trimSpaces(char* str);

class Term {
private:
    int degree;
    int coefficient;
public:
    friend class Polynomial;
    Term();
    Term(int coef, int deg);
    Term(const Term& other); //copy
    Term(char* str); 
    void parse(char* buf); 
    friend std::ostream& operator<<(std::ostream& out, const Term& t);
    friend std::istream& operator>>(std::istream& in, Term& t);
    friend Term operator+(Term& t1, Term& t2);
    friend Term operator*(Term& t1, Term& t2);
    Term& operator=(const Term& t);
    int getDegree() const { return degree; }
    int getCoefficient() const { return coefficient; }
};

