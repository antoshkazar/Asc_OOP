//
// Created by Anton Zaripov on 23.10.2021.
//

#include <iostream>
#include "functional.h"

void InF(functional &f, std::ifstream &ifst) {
    std::string buff;
    ifst >> buff;
    if (buff == "stat") {
        f.typization = f.stat;
    } else {
        f.typization = f.dynamic;
    }
    ifst >> f.lazy >> f.TIOBE >> f.year;
    // std::cout <<"type functional " << f.typization <<' ' << f.lazy<<' '<< f.TIOBE<<' '<<f.year<<'\n';
}

void InRndF(struct functional &f) {
    f.typization = rand() % 2 ? functional::stat : functional::dynamic;
    f.TIOBE = rand() % 100 + 1;
    f.year = rand() % 70 + 1950;
    f.lazy = rand() % 2;
    // std::cout << "type functional " << f.typization << ' ' << f.lazy << ' ' << f.TIOBE << ' ' << f.year << '\n';
}

void OutF(functional &f, std::ofstream &ofst) {
    std::string tipyz;
    if (f.typization)
        tipyz = "stat";
    else
        tipyz = "dynamic";
    // ofst << "3\n" << tipyz << " " << f.lazy << " " << f.TIOBE << ' ' << f.year << '\n';
    ofst << "It is a Functional Language: typization - " << tipyz << "; laziness - " << f.lazy << "; TIOBE - "
         << f.TIOBE << "; year - " << f.year << ";\n";
}

double CommonF(functional &f) {
    return f.year / 10.0;
}