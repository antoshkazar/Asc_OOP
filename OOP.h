//
// Created by Anton Zaripov on 23.10.2021.
//

#ifndef ASC_OOP_OOP_H
#define ASC_OOP_OOP_H


#include <fstream>

class OOP{

public:
    enum inheritance {
        one, plural, interface
    };
    enum inheritance inheritance;
    double TIOBE;
    int year;
};

void InO(class OOP &oop, std::ifstream &ifst);

void InRndO(OOP &oop);

void OutO(OOP &oop, std::ofstream &ofst);

double CommonO(OOP &oop);

#endif //ASC_OOP_OOP_H
