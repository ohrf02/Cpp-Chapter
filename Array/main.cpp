#include <iostream>
#include "ProtectedArray.h"

int main() {
    ProtectedArray<int> arr(10);
    try {
        arr[5] = 4;
        *(arr + 2) = 5;

        std::cout << arr[5] << std::endl;
        std::cout << arr[2] << std::endl;
    }
    catch (const char* crap){
        std::cout << crap << std::endl;
    }
}
