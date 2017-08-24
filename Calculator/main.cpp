#include <iostream>
#include <vector>
#include <sstream>

//The imports for the sub calculatorOperation classes' headers.
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include "Power.h"
#include "Sqrt.h"
#include "Set.h"

//Gets the parameters from a given string and splits the parameters into a vector.
vector<string> getParameters(string input);

using namespace std;

//The main function.
int main() {

    //The vector of the calculator's operations.
    vector<calculatorOperation*> op_list(7);
    op_list[0] = new Addition;
    op_list[1] = new Subtraction;
    op_list[2] = new Multiplication;
    op_list[3] = new Division;
    op_list[4] = new Power;
    op_list[5] = new Sqrt;
    op_list[6] = new Set;


    //The boolean for the
    bool flage = true, forFlage = true;
    string input, op_code;
    double currentValue = 0;

    //The calculator's loop
    while (flage) {


        //Reads the input from the client.
        getline(cin, input);

        //Converts the input from string to string-stream.
        stringstream ss(input);

        //Gets the first word(the op-code) from the input.
        ss >> op_code;

        //Splits the parameters from the input to a vector(without the op-code).
        vector<string> parameters = getParameters(input);

        //Resets the for boolean.
        forFlage = true;

        //Checks if the op-code is an calculator'a operation.
        for (int i = 0; i < op_list.capacity() && forFlage; ++i) {

            //If the op-code is an calculator'a operation:
            if (op_list[i]->supportsOperations(op_code)) {

                //If the user did not give the exact number of parameters that the operation needs:
                if (parameters.capacity() != op_list[i]->requiredParameters()) {
                    cout << "The are " << op_list[i]->requiredParameters() << " parameters required!" << endl;
                    forFlage = false;
                }
                else {
                    try {
                        //Calls the operation and update the current value.
                        currentValue = op_list[i]->calcResult(currentValue, parameters);
                        cout << "Current value is: " << currentValue << endl;
                        forFlage = flage;
                    }
                    catch (const char *crap) {
                        cout << crap << endl;
                        forFlage = false;
                    }
                }
            }

        }
        //If the user entered one of the exit-commands => exit the program.
        if (op_code == "q" || op_code == "exit") {
            cout << "Goodbye" << endl;
            flage = false;
        }
    }



    return 0;
}

//Gets the parameters from a given string and splits the parameters into a vector.
vector<string> getParameters(string input){

    vector<string> vec;
    string temp;

    //The string-stream of the user's input.
    stringstream ss(input);

    //Removes the op-code from the stream.
    getline(ss, temp, ' ');

    //Reads word by word from the stream and stores the word in the vector.
    while (getline(ss, temp, ' ')){
        vec.push_back(temp);
    }

    return vec;
}