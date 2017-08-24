//
// Created by ohrf02 on 8/20/2017.
//

#ifndef BARMAN_REDWINE_H
#define BARMAN_REDWINE_H

#include <iostream>
#include "Wine.h"

class RedWine : public Wine{
public:
    RedWine(int year, const char *name) : Wine(year, name) {};
    void prepare() const{std::cout << "Serve the wine in room temperature and pour into a wine glass." << std::endl;}

};


#endif //BARMAN_REDWINE_H
