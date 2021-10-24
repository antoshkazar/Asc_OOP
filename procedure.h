//
// Created by Anton Zaripov on 23.10.2021.
//

#ifndef ASC_OOP_PROCEDURE_H
#define ASC_OOP_PROCEDURE_H


#include <fstream>

class procedure{
public:
    bool abstract;
    double TIOBE;
    int year;

};

void Inp(procedure &p, std::ifstream &ifst);

void InRndP(procedure &p);

void OutP(procedure &p, std::ofstream &ofst);

double CommonP(procedure &p);

#endif //ASC_OOP_PROCEDURE_H
