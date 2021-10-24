#include <iostream>
#include <fstream>
#include "container.h"
#include <ctime>

using namespace std;


int main(int argc, char *argv[]) {
    if (argc != 4) {
        cout << "incorrect command line!\n"
                "  Waited (for filled input files):\n"
                "     command -f infile outfile01\n"
                "  Or (to generate random parameters):\n"
                "     command -n number outfile01\n";
        return 0;
    }
    container cont;
    Init(cont);
    if (!strcmp(argv[1], "-f")) {
        ifstream inputStream(argv[2]);
        int total;
        inputStream >> total;
        In(cont, inputStream, total);
        ofstream outputfile(argv[3]);
        outputfile << "Filled container:\n";
        Out(cont, outputfile);
        outputfile << "Common function sum: " << CommonC(cont) << '\n';
        outputfile << "Sorted container: " << '\n';
        BinaryInsertion(cont, 0, cont.len - 1);
        Out(cont, outputfile);
        Clear(cont);
        outputfile << "Container cleared!";
    } else if (!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            cout << "incorrect numer of figures = "
                 << size
                 << ". Set 0 < number <= 10000\n";
            return 3;
        }
        InRnd(cont, atoi(argv[2]));
        ofstream outputfile(argv[3]);
        outputfile << "Filled container:\n";
        Out(cont, outputfile);
        outputfile << "Common function sum: " << CommonC(cont) << '\n';
        outputfile << "Sorted container: " << '\n';
        BinaryInsertion(cont, 0, cont.len - 1);
        Out(cont, outputfile);
        Clear(cont);
        outputfile << "Container cleared!";
    } else {
        cout << "incorrect command line!\n"
                "  Waited (for filled input files):\n"
                "     command -f infile outfile01\n"
                "  Or (to generate random parameters):\n"
                "     command -n number outfile01\n";
        return 0;
    }
    cout << "runtime = " << clock()/1000000.0;
    return 0;
}

