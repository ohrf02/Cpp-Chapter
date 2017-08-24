//
// Created by ohrf02 on 8/22/2017.
//

#ifndef CALCULATOR_MULTIPLICATION_H
#define CALCULATOR_MULTIPLICATION_H


#include "calculatorOperation.h"

class Multiplication : public calculatorOperation {
public:

    //Returns if the given op-code is supported.
    virtual bool supportsOperations(string op_string) const {
        return (op_string == "mul" || op_string == "*");
    }

    //Returns the required number of parameters for the exact operation.
    virtual int requiredParameters() const {
        return 1;
    }

    //Returns the current value of the calculator after the operation was done.
    virtual double calcResult(double currVal, vector<string> parameters) const {
        //If the parameter is not a number => throw an exception.
        if(!(isNumber(parameters[0]))) throw "The parameter must be a number!";
        return currVal * std::atoi(parameters[0].c_str());
    }
};


#endif //CALCULATOR_MULTIPLICATION_H
