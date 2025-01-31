#include "Laba33.h"

Fraction::Fraction() {
	numerator = 0;
	denominator = 1;
}

Fraction::Fraction(const char* input) {
	int i = 0;
	int j = 0;
	int e = 0;
	int cell_part = 0;
	// Проверка на то, есть ли целая часть в дроби
	char maybe_numerator[100];

	if (is_space(input)) {
		while (input[e] != ' ') {
			maybe_numerator[i] = input[e];
			e++;
			i++;
		}
		maybe_numerator[i] = '\0';
		cell_part = std::atoi(maybe_numerator);
		e++;
	}

	char numBuffer[100];
	while (input[e] != '/' && input[e] != '\0') {
		numBuffer[j] = input[e];
		j++;
		e++;
	}
	numBuffer[j] = '\0';
	// Пропускаем разделитель и пробел
	numerator = std::atoi(numBuffer);
	if (input[e] != '\0') {
		e++;
	}
	j = 0;

	// Считываем знаменатель
	char denBuffer[100];
	if (input[e] != '\0') {
		while (input[e] != '\0' && input[e] != ' ') {
			denBuffer[j] = input[e];
			e++;
			j++;
		}
		denBuffer[j] = '\0';
		denominator = std::atoi(denBuffer);
	}
	else {
		denominator = 1;
	}



	//итог:
	if (denominator != 0) {
		if (cell_part != 0) {
			numerator = cell_part * (denominator * abs(cell_part) + numerator) / abs(cell_part);

		}
		else {
			if (is_space(input) && input[0] == '-' && input[1] == '0') {
				numerator = -1 * numerator;
			}
			else {
				numerator = (denominator * abs(cell_part) + numerator);
			}
		}
	}
	else {
		std::cout << "знаменатель не может быть равен нулю!" << std::endl;
		numerator = 0;
		denominator = 1;
	}
	//если "-0 4/3" -4/3
}


Fraction::Fraction(char* input) {
	int i = 0;
	int j = 0;
	int e = 0;
	int cell_part = 0;
	// Проверка на то, есть ли целая часть в дроби
	char maybe_numerator[100];

	if (is_space(input)) {
		while (input[e] != ' ') {
			maybe_numerator[i] = input[e];
			e++;
			i++;
		}
		maybe_numerator[i] = '\0';
		cell_part = std::atoi(maybe_numerator);
		e++;
	}

	char numBuffer[100];
	while (input[e] != '/' && input[e] != '\0') {
		numBuffer[j] = input[e];
		//std::cout << numBuffer[j] << std::endl;
		j++;
		e++;
	}
	numBuffer[j] = '\0';
	// Пропускаем разделитель и пробел
	numerator = std::atoi(numBuffer);
	if (input[e] != '\0') {
		e++;
	}
	j = 0;

	// Считываем знаменатель
	char denBuffer[100];
	if (input[e] != '\0') {
		while (input[e] != '\0' && input[e] != ' ') {
			denBuffer[j] = input[e];
			e++;
			j++;
		}
		denBuffer[j] = '\0';
		denominator = std::atoi(denBuffer);
	}
	else {
		denominator = 1;
	}

	//итог:
	if (denominator != 0) {
		if (cell_part != 0) {
			numerator = cell_part * (denominator * abs(cell_part) + numerator) / abs(cell_part);

		}
		else {
			if (is_space(input) && input[0] == '-' && input[1] == '0') {
				numerator = -1 * numerator;
			}
			else {
				numerator = (denominator * abs(cell_part) + numerator);
			}
		}
	}
	else {
		std::cout << "знаменатель не может быть равен нулю!" << std::endl;
		numerator = 0;
		denominator = 1;
	}
	//если "-0 4/3" -4/3
}

Fraction::Fraction(double fraction) {
	this->numerator = int(fraction) * pow(10, N_DEC) + int((fraction - int(fraction)) * pow(10, N_DEC));
	this->denominator = pow(10, N_DEC);
	this->DeleteZeroes();
}

std::istream& operator>>(std::istream& in, Fraction& fraction) {
    char input[100] = { 0 };
    in.getline(input, 100, '\n');
    Fraction temp(input);
    fraction = temp;
    return in;
}


std::ostream& operator<<(std::ostream& out, Fraction& obj) {
    if (abs(obj.numerator) % obj.denominator == 0) {
        out << obj.numerator / obj.denominator << '\n';
    }
    else {
        bool isminus{ 1 };
        if (obj.numerator < 0) { bool isminus = -1; }
        int denominator = obj.denominator;
        int integer = obj.numerator / obj.denominator;
        int notint = abs(obj.numerator) % obj.denominator;
        int n = std::min(notint, obj.denominator);
        for (int i = 2; i < n; ++i) {
            if (notint % i == 0 && denominator % i == 0) {
                notint /= i;
                denominator /= i;
                --i;
            }
        }
        if (integer == 0) { out << (int)((obj.numerator > 0) ? notint : -notint) << '/' << denominator << '\n'; }
        else { out << integer << " " << notint << '/' << denominator << '\n'; };
    }
    return out;
}


Fraction operator+(const Fraction& a, const Fraction& b) {
    return Fraction(a.numerator * b.denominator + b.numerator * a.denominator, a.denominator * b.denominator);
}

Fraction& Fraction::operator=(const Fraction& b) {
    numerator = b.numerator;
    denominator = b.denominator;
    return *this;
}

Fraction operator+(const Fraction& a, double b) {
    Fraction temp(b);
    return a + temp;
}

Fraction operator+(double a, const Fraction& b) {
    Fraction temp(a);
    return temp + b;
}

Fraction operator+(const Fraction& a, int b) {
    Fraction temp(b, 1);
    return a + temp;
}

Fraction operator+(int a, const Fraction& b) {
    Fraction temp(a, 1);
    return temp + b;
}

Fraction& operator+=(Fraction& a, const Fraction& b) {
    a = a + b;
    return a;
}

Fraction& operator+=(Fraction& a, double b) {
    a = a + b;
    return a;
}

Fraction& operator+=(Fraction& a, int b) {
    a = a + b;
    return a;
}
