//
// Created by ohrf02 on 8/17/2017.
//

#ifndef FRACTION_FRACTION_H
#define FRACTION_FRACTION_H


class Fraction {
public:
    //Constructor and destructor.
    Fraction(int nominator, int denominator);
    ~Fraction(){};

    //Functions for getting the private parameters.
    int get_nominator() const {return nominator;}
    int get_denominator() const {return denominator;}

    //Prints the fraction.
    void Print() const;

    //Casts to float/double.
     operator float () const;
     operator double() const;

    //Minimizes the fraction's values.
     void minimize();

    //Multiplication
    Fraction operator*(const Fraction& other) const;
    Fraction operator*(const int num) const;

    //Addition
    Fraction operator+(const Fraction& other) const;
    Fraction operator+(const int num) const;

    //Subtraction
    Fraction operator- (const Fraction& other) const;
    Fraction operator- (const int num) const;

    //Division
    Fraction operator/ (const Fraction& other) const;
    Fraction operator/ (const int num) const;

    //Powering.
    Fraction operator^ (const int num) const;

private:
    //The nominator and the denominator of the fraction.
    int nominator;
    int denominator;
};


#endif //FRACTION_FRACTION_H
