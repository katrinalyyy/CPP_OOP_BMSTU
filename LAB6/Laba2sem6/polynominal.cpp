#include "polynominal.h"
#include <cstring>

Polynomial::Polynomial(Term term, int num, int cap, int sortOrder) {
    capacity = cap;
    count = num;
    terms = new Term[capacity];
    terms[0] = term;
    sortingOrder = sortOrder;
}

Polynomial::Polynomial() {
    Term term;
    count = 0;
    capacity = 1;
    sortingOrder = 1;
    terms = new Term[capacity];
}

Polynomial::~Polynomial() {
    delete[] terms;
}

Polynomial::Polynomial(const Polynomial& other) {
    sortingOrder = other.sortingOrder;
    capacity = other.capacity;
    count = other.count;
    terms = new Term[capacity];
    for (int i = 0; i < count; ++i)
        terms[i] = other.terms[i];
}

void Polynomial::addTerm(Term term) {
    if (count < capacity) {
        terms[count] = term;
        count++;
    }
    else {
        Term* newTerms = new Term[count + 1];
        for (int i = 0; i < count; ++i)
            newTerms[i] = terms[i];
        delete[] terms;
        newTerms[count] = term;
        terms = newTerms;
        count++;
        capacity++;
    }
}

void Polynomial::addTerm(int coef, int exp) {
    Term term(coef, exp);
    if (count < capacity) {
        terms[count] = term;
        count++;
    }
    else {
        Term* newTerms = new Term[count + 1];
        for (int i = 0; i < count; ++i)
            newTerms[i] = terms[i];
        delete[] terms;
        newTerms[count] = term;
        terms = newTerms;
        count++;
        capacity++;
    }
}

void Polynomial::removeTerm(int index) {
    for (int i = index; i < count - 1; ++i)
        terms[i] = terms[i + 1];
    --count;
}

void Polynomial::sort() {
    for (int i = 0; i < count; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if ((terms[i].getDegree()) * sortingOrder < (terms[j].getDegree()) * sortingOrder) {
                Term temp(terms[i]);
                terms[i] = terms[j];
                terms[j] = temp;
            }
        }
    }
    addTerm(0, -1);
    int i = 0;
    int j = 0;
    int k = 0;
    while (terms[i].getDegree() != -1) {
        if (terms[i + 1].getDegree() != terms[i].getDegree()) {
            i++;
            j = i;
            k = 0;
        }
        else {
            while (terms[j].getDegree() == terms[i].getDegree()) {
                j++;
                k++;
            }
            for (int h = i + 1; h < j; ++h) {
                terms[i].coefficient += terms[h].coefficient;
            }
            for (int h = 1; h < k; ++h)
                removeTerm(i + 1);
            i++;
            j = i;
            k = 0;
        }
    }
    removeTerm(count - 1);
}

Polynomial& Polynomial::add(Polynomial& other) {
    Term* newTerms = new Term[count + other.count];
    for (int i = 0; i < count; ++i)
        newTerms[i] = terms[i];
    for (int i = count; i < count + other.count; ++i)
        newTerms[i] = other.terms[i - count];
    count = count + other.count;
    capacity = count;
    terms = newTerms;
    sort();
    return *this;
}

Polynomial& Polynomial::multiply(Polynomial& other) {
    Term* newTerms = new Term[count * other.count];
    int k = 0;
    for (int i = 0; i < other.count; ++i) {
        for (int j = 0; j < count; ++j) {
            Term temp(terms[j] * other.terms[i]);
            newTerms[k] = temp;
            k++;
        }
    }
    delete[] terms;
    count = count * other.count;
    capacity = count;
    terms = newTerms;
    sort();
    return *this;
}

Polynomial operator+(Polynomial& p1, Polynomial& p2) {
    Polynomial result;
    result.count = p1.count + p2.count;
    result.capacity = result.count;
    result.sortingOrder = (p1.sortingOrder == -1 && p2.sortingOrder == -1) ? -1 : 1;
    delete[] result.terms;
    result.terms = new Term[result.count];
    for (int i = 0; i < p1.count; ++i) {
        result.terms[i] = p1.terms[i];
    }
    for (int i = p1.count; i < result.count; ++i) {
        result.terms[i] = p2.terms[i - p1.count];
    }
    result.sort();
    return result;
}

Polynomial operator*(Polynomial& p1, Polynomial& p2) {
    Polynomial result;
    delete[] result.terms;
    result.terms = new Term[p1.count * p2.count];
    int k = 0;
    for (int i = 0; i < p1.count; ++i) {
        for (int j = 0; j < p2.count; ++j) {
            Term temp(p1.terms[i] * p2.terms[j]);
            result.terms[k] = temp;
            k++;
        }
    }
    result.count = p1.count * p2.count;
    result.capacity = result.count;
    result.sort();
    return result;
}

std::istream& operator>>(std::istream& in, Polynomial& p) {
    char* buffer = new char[256];
    char* termBuffer = new char[256];
    in.getline(buffer, 256);    
    buffer = trimSpaces(buffer);
    int i = 0;
    int j = 0;
    while (buffer[i] != '\0') { 
        j = i;
        do
            j++;
        while (buffer[j] != '-' && buffer[j] != '+' && buffer[j] != '\0');
        for (int h = i; h <= j; ++h)
            termBuffer[h - i] = buffer[h];
        termBuffer[j - i] = '\0';
        Term term(termBuffer);   
        p.addTerm(term);
        i = j;
    }
    p.sortingOrder = 1;
    delete[] buffer;
    delete[] termBuffer;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Polynomial& p) {
    for (int i = 0; i < p.count; ++i) {
        out << p.terms[i];
    }
    out << '\n';
    return out;
}

Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this == &other) return *this;
    sortingOrder = other.sortingOrder;
    count = other.count;
    capacity = count;
    delete[] terms;
    terms = new Term[count];
    for (int i = 0; i < count; ++i)
        terms[i] = other.terms[i];
    return *this;
}

Polynomial& Polynomial::operator*=(Polynomial& other) {
    return multiply(other);
}

Polynomial& Polynomial::operator+=(Polynomial& other) {
    return add(other);
}
