//
// Created by aykull on 20/09/18.
//
#include <iostream>


class MPointerGC {
private:

    static MPointerGC* instance;
    MPointerGC();

public:

    static MPointerGC* getInstance();
};

MPointerGC* MPointerGC ::instance =0;

MPointerGC* MPointerGC::getInstance() {
    if (instance == 0){
        instance = new MPointerGC();
    }
    return instance;
}

MPointerGC::MPointerGC() {}


