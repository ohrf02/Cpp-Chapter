#include <iostream>
#include "Fraction.h"

int main() {
    Fraction f1(1, 3);
    Fraction f2(1, 2);

    Fraction f3 = f1 + f2 - f2;
    f3 = f3 * 3;
    f3.minimize();
    f3.Print();
    return 0;
}