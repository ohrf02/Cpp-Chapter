//
// Created by ohrf02 on 8/21/2017.
//

#ifndef CALCULATOR_CALCULATOROPERATION_H
#define CALCULATOR_CALCULATOROPERATION_H

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class calculatorOperation {
public:

    //Returns if the given op-code is supported.
    virtual bool supportsOperations(string op_string)const = 0;

    //Returns the required number of parameters for the exact operation.
    virtual int requiredParameters() const = 0;

    //Returns the current value of the calculator after the operation was done.
    virtual double calcResult(double currVal, vector<string> parameters) const = 0;

    //Checks if a given string is number.
    bool isNumber(const std::string s) const {
        std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }
};


#endif //CALCULATOR_CALCULATOROPERATION_H
