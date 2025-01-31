#pragma once
#define N_DEC 4

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>


class Fraction {
private:
	int numerator;
	int denominator;

	bool is_space(char* input) {
		for (int i = 0; input[i] != '\0'; i++) {
			if (input[i] == ' ') {
				return true;
			}
		}
		return false;
	}

	bool is_space(const char* input) {
		for (int i = 0; input[i] != '\0'; i++) {
			if (input[i] == ' ') {
				return true;
			}
		}
		return false;
	}

	void DeleteZeroes() {
		while (numerator % 10 == 0 && denominator % 10 == 0) {
			numerator /= 10;
			denominator /= 10;
		}
	}

public:
	Fraction();

	Fraction(int num, int den) : numerator(num), denominator(den) { }

	Fraction(const char* input);

	Fraction(char* input);

	Fraction(double fraction);

	friend std::istream& operator>>(std::istream& in, Fraction& fraction);
	friend std::ostream& operator<<(std::ostream& out, Fraction& obj);
	friend Fraction operator+(const Fraction& a, const Fraction& b);
	Fraction& operator=(const Fraction& b);


};


Fraction& operator+=(Fraction& a, int b);
Fraction& operator+=(Fraction& a, double b);
Fraction& operator+=(Fraction& a, const Fraction& b);
Fraction operator+(int a, const Fraction& b);
Fraction operator+(const Fraction& a, int b);
Fraction operator+(double a, const Fraction& b);
Fraction operator+(const Fraction& a, double b);
