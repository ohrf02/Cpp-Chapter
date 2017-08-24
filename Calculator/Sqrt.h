//
// Created by ohrf02 on 8/22/2017.
//

#ifndef CALCULATOR_SQRT_H
#define CALCULATOR_SQRT_H

#include <cmath>
#include "calculatorOperation.h"

class Sqrt : public calculatorOperation {
public:

    //Returns if the given op-code is supported.
    virtual bool supportsOperations(string op_string) const {
        return (op_string == "sqrt" || op_string == "Sqrt");
    }

    //Returns the required number of parameters for the exact operation.
    virtual int requiredParameters() const {
        return 0;
    }

    //Returns the current value of the calculator after the operation was done.
    virtual double calcResult(double currVal, vector<string> parameters) const {
        //If the parameter is negative => throw an exception.
        if(currVal < 0) throw "The value must be positive!";
        return sqrt(currVal);
    }
};


#endif //CALCULATOR_SQRT_H
