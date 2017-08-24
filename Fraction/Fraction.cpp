//
// Created by ohrf02 on 8/17/2017.
//

#include <iostream>
#include "Fraction.h"
#include <cmath>

//Returns the largest common divider of the two given numbers.
int find_divider(int a, int b);

//The constructor.
Fraction::Fraction(int nominator, int denominator) {
    this->nominator = nominator;
    this->denominator = denominator;
}

//The multiplation operator-functions.
Fraction Fraction::operator*(const Fraction &other) const {
    Fraction f((nominator * other.get_nominator()), (denominator * other.get_denominator()));
    return f;
}

Fraction Fraction::operator*(const int num) const {
    Fraction f(num * nominator, denominator);
    return  f;
}

//The addition operator-functions.
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

//The subtraction operator-functions.
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

//The division operator-functions.
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

//Prints the fraction.
void Fraction::Print() const{
    std::cout << "( " << nominator;
    std::cout <<" / " << denominator << " )" << std::endl;
}

//Returns a float of the fraction.
Fraction::operator float() const {
    return ((float)nominator / (float)denominator);
}

//Returns a double of the fraction.
Fraction::operator double() const {
    return ((double)nominator/ (double)denominator);
}

//Power the fraction by the given number.
Fraction Fraction::operator^(const int num) const {
    Fraction f((int)pow(nominator, num), (int)pow(denominator, num));
    return f;
}

//Minimaizes the fraction's elements by the largest common divider.
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

//Returns the largest common divider of the two given numbers.
int find_divider(int a, int b){
    int divider = 1;
    for (int i = 1; i < (a < b ? a : b); ++i) {
        if(a % i == 0 && b % i == 0)
            divider = i;
    }

    return divider;

}

