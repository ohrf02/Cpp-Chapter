//
// Created by ohrf02 on 8/22/2017.
//

#ifndef CALCULATOR_POWER_H
#define CALCULATOR_POWER_H

#include <math.h>
#include "calculatorOperation.h"

class Power : public calculatorOperation {
public:

    //Returns if the given op-code is supported.
    virtual bool supportsOperations(string op_string) const {
        return (op_string == "pow" || op_string == "^");
    }

    //Returns the required number of parameters for the exact operation.
    virtual int requiredParameters() const {
        return 1;
    }

    //Returns the current value of the calculator after the operation was done.
    virtual double calcResult(double currVal, vector<string> parameters) const {
        int param = std::atoi(parameters[0].c_str());

        //If the parameter is not a number => throw an exception.
        if(!(isNumber(parameters[0]))) throw "The parameter must be a number!";

        //If the parameter is negative => throw an exception.
        if(param < 0) throw "The parameter for the power must be positive!";
        return pow(currVal, param);
    }

};


#endif //CALCULATOR_POWER_H
