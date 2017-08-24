//
// Created by ohrf02 on 8/22/2017.
//

#ifndef CALCULATOR_DIVISION_H
#define CALCULATOR_DIVISION_H


#include "calculatorOperation.h"

class Division : public calculatorOperation {
public:

    //Returns if the given op-code is supported.
    virtual bool supportsOperations(string op_string) const {
        return (op_string == "div" || op_string == "/");
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

        //If the parameter(the divider) is 0 => throw an exception.
        if(param == 0) throw "Can not divide by 0!";

        return currVal / param;
    }

};


#endif //CALCULATOR_DIVISION_H
