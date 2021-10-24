//
// Created by Anton Zaripov on 23.10.2021.
//

#include <iostream>
#include "language.h"

language *InL(std::ifstream &ifst) {
    language *lang = new language;
    int k;
    ifst >> k;
    switch (k) {
        case 1:
            lang->k = language::procedure;
            Inp(lang->p, ifst);
            return lang;
        case 2:
            lang->k = language::OOP;
            InO(lang->oop, ifst);
            return lang;
        case 3:
            lang->k = language::functional;
            InF(lang->f, ifst);
            return lang;
        default:
            return 0;
    }
}

language *InRndL() {
    language *lang = new language;
    int i = rand() % 3;
    switch (i) {
        case 0:
            lang->k = language::procedure;
            InRndP(lang->p);
            return lang;
        case 1:
            lang->k = language::OOP;
            InRndO(lang->oop);
            return lang;
        default:
            lang->k = language::functional;
            InRndF(lang->f);
            return lang;
    }
}

void OutL(language &lang, std::ofstream &file) {
    switch (lang.k) {
        case language::functional:
            return OutF(lang.f, file);
        case language::procedure:
            return OutP(lang.p, file);
        case language::OOP:
            return OutO(lang.oop, file);
        default:
            file << "Something went wrong!";
            return;
    }
}

double CommonL(language &lang) {
    switch (lang.k) {
        case language::procedure:
            return CommonP(lang.p);
        case language::OOP:
            return CommonO(lang.oop);
        case language::functional:
            return CommonF(lang.f);
        default:
            return 0.0;
    }
}
