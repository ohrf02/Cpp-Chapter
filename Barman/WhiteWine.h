//
// created by ohrf02 on 8/20/2017.
//

#ifndef barman_whitewine_h
#define barman_whitewine_h


#include <iostream>
#include "Wine.h"

class WhiteWine : public Wine{
public:
    WhiteWine(int year, const char *name) : Wine(year, name) {};
    void prepare() const{std::cout << "serve cold and pour into a wine glass." << std::endl;}


};


#endif //barman_whitewine_h
