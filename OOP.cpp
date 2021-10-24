//
// Created by Anton Zaripov on 23.10.2021.
//

#include <iostream>
#include "OOP.h"

void InO(OOP &oop, std::ifstream &ifst) {
    std::string buff;
    ifst >> buff;
    if (buff == "one") {
        oop.inheritance = OOP::one;
    } else if (buff == "plural") {
        oop.inheritance = OOP::plural;
    } else {
        oop.inheritance = OOP::interface;
    }
    ifst >> oop.TIOBE >> oop.year;
    // std::cout <<"type oop " <<  oop.inheritance << ' ' << oop.TIOBE << ' ' << oop.year << '\n';
}

void InRndO(OOP &oop) {
    oop.inheritance = rand() % 2 ? OOP::plural : OOP::one;
    oop.year = rand() % 50 + 1950;
    oop.TIOBE = rand() % 100 + 1;
    // std::cout << "type oop " << oop.inheritance << ' ' << oop.TIOBE << ' ' << oop.year << '\n';
}

void OutO(OOP &oop, std::ofstream &ofst) {
    std::string inher;
    switch (oop.inheritance) {
        case 0:
            inher = "one";
            break;
        case 1:
            inher = "plural";
            break;
        default:
            inher = "interface";
    }
    //ofst << "2\n" << inher << " " << oop.TIOBE << ' ' << oop.year << '\n';
    ofst << "It is a OOP Language: inheritance - " << inher << "; TIOBE - "
         << oop.TIOBE << "; year - " << oop.year << ";\n";
}

double CommonO(OOP &oop) {
    return oop.year / 3.0;
}