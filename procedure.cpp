//
// Created by Anton Zaripov on 23.10.2021.
//

#include <iostream>
#include "procedure.h"

void Inp(procedure &p, std::ifstream &ifst) {
    ifst >> p.abstract >> p.TIOBE >> p.year;
    // std::cout<< "type procedure "  << p.abstract <<' '<< p.TIOBE <<' ' << p.year <<'\n';
}

void InRndP(procedure &p) {
    p.abstract = rand() % 2;
    p.TIOBE = rand() % 100 + 1;
    p.year = rand() % 50 + 1950;
    // std::cout<< "type procedure "  << p.abstract <<' '<< p.TIOBE <<' ' << p.year <<'\n';
}

void OutP(procedure &p, std::ofstream &ofst) {
    //ofst << "1\n" << p.abstract << " " << p.TIOBE << ' ' << p.year << '\n';
    ofst << "It is a Procedure Language: abstract - " << p.abstract << "; TIOBE - "
         << p.TIOBE << "; year - " << p.year << ";\n";
}

double CommonP(procedure &p) {
    return p.year / 9.0;
}
