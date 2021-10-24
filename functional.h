//
// Created by Anton Zaripov on 23.10.2021.
//

#ifndef ASC_OOP_FUNCTIONAL_H
#define ASC_OOP_FUNCTIONAL_H


#include <fstream>

class functional {

public:
    enum typization {
        stat, dynamic,
    };
    enum typization typization;
    bool lazy;
    int year;
    double TIOBE;
};

void InF(functional &f, std::ifstream &ifst);

void InRndF(struct functional &f);

void OutF(functional &f, std::ofstream &ofst);

double CommonF(functional &f);

#endif //ASC_OOP_FUNCTIONAL_H
