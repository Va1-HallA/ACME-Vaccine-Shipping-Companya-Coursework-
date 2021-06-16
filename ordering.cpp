#include <iostream>
#include <fstream>
#include <string>
#include "Customer.h"
#include "Manager.h"
using namespace std;

int main (int argc, char* argv[]){
    if (argc != 2){
        cerr << "invalid number of input parameters. Expect: 1" << endl;
        exit(1);
    }
    string filename = argv[1];
    ifstream file(filename);
    if (!file) {
        cerr << "unable to open file" << endl;
        return 1;
    }
    string line;
    while(getline(file, line)){
        Manager::handleInput(line);
    }
    return 0;
}