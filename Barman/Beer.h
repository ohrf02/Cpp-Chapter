//
// Created by ohrf02 on 8/20/2017.
//

#ifndef BARMAN_BEER_H
#define BARMAN_BEER_H


#include <iostream>
#include "Drink.h"

class Beer : public Drink {
public:
    Beer(const char *Name) : Name(Name) {};

    const char* getName() const { return this->Name;}
    void prepare() const { std::cout << "Well, all you need to do is pour it into a glass and serve.";}


private:
    const char* Name;

};


#endif //BARMAN_BEER_H
