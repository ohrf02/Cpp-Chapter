//
// Created by ohrf02 on 8/20/2017.
//

#ifndef barman_drink_h
#define barman_drink_h


class Drink {
public:
    virtual void prepare() const = 0;
    virtual const char* getName() const{return "drink";}
};


#endif //BARMAN_DRINK_H
