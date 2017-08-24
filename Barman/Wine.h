//
// Created by ohrf02 on 8/20/2017.
//

#ifndef BARMAN_WINE_H
#define BARMAN_WINE_H


#include "Drink.h"
#include <string.h>
#include <string>

class Wine : public Drink{
public:
    Wine(int year, const char* name){this->year = year; this->Name = name;}
    Wine(){};

    virtual const char* getName() const;
    virtual void prepare()const = 0;

private:
    int year;
    const char* Name;
};


#endif //BARMAN_WINE_H
