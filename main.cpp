#include <iostream>
#include "QuickHull.h"
using namespace std;
int main(int argc, char* argv[]) {
    string input = argv[1];
    string output = argv[2];

    QuickHull alg;
    alg.loadData(input);
    alg.run();
    alg.result(output);
    return 0;
}