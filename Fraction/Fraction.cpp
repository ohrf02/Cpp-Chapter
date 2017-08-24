//
// Created by ohrf02 on 8/17/2017.
//

#include <iostream>
#include "Fraction.h"
#include <cmath>

int find_divider(int a, int b);

Fraction::Fraction(int nominator, int denominator) {
    this->nominator = nominator;
    this->denominator = denominator;
}

Fraction Fraction::operator*(const Fraction &other) const {
    Fraction f((nominator * other.get_nominator()), (denominator * other.get_denominator()));
    return f;
}

Fraction Fraction::operator*(const int num) const {
    Fraction f(num * nominator, denominator);
    return  f;
}

Fraction Fraction::operator+(const Fraction &other) const {
    int nom, demon;
    nom = (other.denominator * nominator) + (other.nominator * denominator);
    demon = other.denominator * denominator;
    Fraction f(nom, demon);
    return f;
}

Fraction Fraction::operator+(const int num) const {
    int nom = nominator + (num * denominator);
    Fraction f(nom, denominator);
    return f;
}

Fraction Fraction::operator-(const Fraction &other) const {
    int nom, demon;
    nom = (other.denominator * nominator) - (other.nominator * denominator);
    demon = other.denominator * denominator;
    Fraction f(nom, demon);
    return f;
}

Fraction Fraction::operator-(const int num) const {
    int nom = nominator - (num * denominator);
    Fraction f(nom, denominator);
    return f;
}

Fraction Fraction::operator/(const Fraction &other) const {
    int nom = other.get_nominator();
    int denom = other.get_denominator();
    Fraction f(denom, nom);

    return Fraction::operator*(f);
}

Fraction Fraction::operator/(const int num) const {
    Fraction f(1, num);
    return Fraction::operator*(f);
}

void Fraction::Print() const{
    std::cout << "( " << nominator;
    std::cout <<" / " << denominator << " )" << std::endl;
}

Fraction::operator float() const {
    return ((float)nominator / (float)denominator);
}

Fraction::operator double() const {
    return ((double)nominator/ (double)denominator);
}

Fraction Fraction::operator^(const int num) const {
    Fraction f((int)pow(nominator, num), (int)pow(denominator, num));
    return f;
}

void Fraction::minimize() {
    int divider = find_divider(nominator, denominator);
    if (nominator / denominator == 1) {
        nominator = 1;
        denominator = 1;
    } else {
        nominator /= divider;
        denominator /= divider;

    }
}
int find_divider(int a, int b){
    int divider = 1;
    for (int i = 1; i < (a > b ? a : b); ++i) {
        if(a % i == 0 && b % i == 0)
            divider = i;
    }

    return divider;

}

