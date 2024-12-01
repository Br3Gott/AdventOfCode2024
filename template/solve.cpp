#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {

    ifstream input{"example.txt"};
    // ifstream input{"input.txt"};

    string line;
    while (getline(input, line)) {
        stringstream ss{line};

    }

    return 0;
}