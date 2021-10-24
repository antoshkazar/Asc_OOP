//
// Created by Anton Zaripov on 23.10.2021.
//

#include <iostream>
#include "container.h"

void In(container &c, std::ifstream &ifst, int total) {
    if ((total < 1) || (total > 10000)) {
        std::cout << "incorrect numer of figures = "
                  << total
                  << ". Set 0 < number <= 10000\n";
        return;
    }
    for (int i = 0; i < total; i++) {
        if ((c.cont[c.len] = InL(ifst)) != 0) {
            c.len++;
        }
    }
}

void Init(container &c) {
    c.len = 0;
}

void InRnd(container &c, int size) {
    while (c.len < size) {
        if ((c.cont[c.len] = InRndL()) != nullptr) {
            c.len++;
        }
    }
}

void Out(container &c, std::ofstream &ofst) {
    ofst << "Container has " << c.len << " elements." << '\n';
    for (int i = 0; i < c.len; i++) {
        ofst << i + 1 << ": ";
        OutL(*(c.cont[i]), ofst);
    }
}

void Clear(container &c) {
    for (int i = 0; i < c.len; i++) {
        delete c.cont[i];
    }
    c.len = 0;
}

double CommonC(container &c) {
    double div = 0.0;
    for (int i = 0; i < c.len; i++) {
        div += CommonL(*(c.cont[i]));
    }
    return div;
}

void BinaryInsertion(container &mas, int first, int last) {
    language *mid, *count;
    int f = first, l = last;
    mid = mas.cont[(f + l) / 2];
    do {
        while (CommonL(*(mas.cont[f])) < CommonL(*mid)) f++;
        while (CommonL(*(mas.cont[l])) > CommonL(*mid)) l--;
        if (f <= l) {
            count = mas.cont[f];
            mas.cont[f] = mas.cont[l];
            mas.cont[l] = count;
            f++;
            l--;
        }
    } while (f < l);
    if (first < l) BinaryInsertion(mas, first, l);
    if (f < last) BinaryInsertion(mas, f, last);
}