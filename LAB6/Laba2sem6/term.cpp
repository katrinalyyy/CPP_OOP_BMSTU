#include "term.h"

char* trimSpaces(char* str) {
    char buffer[256];
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            buffer[j++] = str[i];
        }
        i++;
    }
    buffer[j] = '\0';
    delete[] str;
    str = new char[strlen(buffer) + 1];
    std::strcpy(str, buffer);
    return str;
}

Term::Term() : coefficient(0), degree(0) {}

Term::Term(int coef, int deg) : coefficient(coef), degree(deg) {}

Term::Term(const Term& other) : coefficient(other.coefficient), degree(other.degree) {}

Term::Term(char* str) {
    parse(str);
}

void Term::parse(char* buf) {
    char buffer[256];
    int index = 0, counter = 0;
    coefficient = 0;
    degree = 0;

    if (buf[0] == '-' && buf[1] == 'x') {
        coefficient = -1;
        counter = 1;
    }
    else if (buf[0] == 'x') {
        coefficient = 1;
        counter = 0;
    }
    else if (buf[0] == '+' && buf[1] == 'x') {
        coefficient = 1;
        counter = 1;
    }
    else if (buf[0] == '0' && buf[1] == 'x' && buf[1] != '^') {
        coefficient = 0;
        counter = 1;
    }
    else if (buf[0] == '0' && buf[1] == 'x' && buf[1] == '^' && buf[2] == '0') {
        coefficient = 0;
        counter = 0;
    }
    else if (buf[0] == '-' && buf[1] == '0' && buf[1] == 'x' && buf[2] == '^' && buf[3] == '0') {
        coefficient = 0;
        counter = 0;
    }
    else {
        for (int i = 0; i < 256; ++i) {
            if (buf[i] == 'x' || buf[i] == '\0') {
                for (int j = 0; j < i; ++j)
                    buffer[j] = buf[j];
                buffer[i] = '\0';
                coefficient = atoi(buffer);
                if (buf[i] == '\0') {
                    counter = -1;
                    degree = 0;
                }
                else {
                    counter = i;
                }
                break;
            }
        }
    }
    if (counter != -1) {
        if (buf[counter + 1] == '\0') {
            degree = 1;
        }
        else {
            counter += 2;
            for (int i = counter; i < 256; ++i) {
                if (buf[i] == '\0') {
                    for (int j = counter; j < i; ++j)
                        buffer[j - counter] = buf[j];
                    buffer[i - counter] = '\0';
                    degree = atoi(buffer);
                    break;
                }
            }
        }
    }
}

Term operator+(Term& t1, Term& t2) {
    if (t1.degree == t2.degree)
        return { t1.coefficient + t2.coefficient, t1.degree };
    else {
        std::cout << "Ошибка, сумма термов разной степени" << std::endl;
        return { 0, 0 };
    }
}

Term operator*(Term& t1, Term& t2) {
    Term result;
    result.coefficient = t1.coefficient * t2.coefficient;
    result.degree = t1.degree + t2.degree;
    return result;
}

Term& Term::operator=(const Term& t) {
    if (this == &t) return *this;
    this->coefficient = t.coefficient;
    this->degree = t.degree;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Term& t) {
    if (t.coefficient == 0) {
        return out;
    }
    else {
        char sign = '+';
        if (t.coefficient < 0)
            sign = '-';
        int absCoef = abs(t.coefficient);
        if (absCoef == 1 && t.degree == 1)
            out << sign << "x ";
        else if (t.degree == 0)
            out << sign << absCoef << ' ';
        else if (t.degree == 1)
            out << sign << absCoef << "x ";
        else if (absCoef == 1)
            out << sign << "x^" << t.degree << ' ';
        else
            out << sign << absCoef << "x^" << t.degree << ' ';
        return out;
    }
}

std::istream& operator>>(std::istream& in, Term& t) {
    char* buf = new char[256];
    in.getline(buf, 256);
    buf = trimSpaces(buf);
    t.parse(buf);
    delete[] buf;
    return in;
}
