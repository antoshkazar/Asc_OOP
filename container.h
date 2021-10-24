//
// Created by Anton Zaripov on 23.10.2021.
//

#ifndef ASC_OOP_CONTAINER_H
#define ASC_OOP_CONTAINER_H

#include <fstream>
#include "language.h"

class container {
public:
    enum {
        max_len = 10000
    };
    language *cont[max_len];
    int len;
};

void InRnd(container &c, int size);

void In(container &c, std::ifstream &ifst, int total);

void Init(container &c);

void Out(container &c, std::ofstream &ofst);

void Clear(container &c);

double CommonC(container &c);

void BinaryInsertion(container &mas, int first, int last);

#endif //ASC_OOP_CONTAINER_H
