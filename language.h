//
// Created by Anton Zaripov on 23.10.2021.
//

#ifndef ASC_OOP_LANGUAGE_H
#define ASC_OOP_LANGUAGE_H

#include <fstream>
#include "OOP.h"
#include "procedure.h"
#include "functional.h"

class language {
public:
    union {
        class procedure p;

        class OOP oop;

        class functional f;
    };
    enum key {
        procedure, OOP, functional
    };
    enum key k;
};

language *InL(std::ifstream &ifst);

language *InRndL();

void OutL(language &lang, std::ofstream &file);

double CommonL(language &lang);

#endif //ASC_OOP_LANGUAGE_H
