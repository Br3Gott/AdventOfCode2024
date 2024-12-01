#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <cmath>

using namespace std;

int main() {

    // ifstream input{"example.txt"};
    ifstream input{"input.txt"};

    string line;
    multiset<int> row1;
    multiset<int> row2;

    while (getline(input, line)) {
        stringstream ss{line};
        int temp;
        ss >> temp;
        row1.insert(temp);
        ss >> temp;
        row2.insert(temp);
    }

    int sum{};

    auto row1Pos{row1.begin()};
    auto row2Pos{row2.begin()};

    while (row1Pos != row1.end() || row2Pos != row2.end()) {
        sum += abs(*(row1Pos++) - *(row2Pos++));
    }

    cout << sum << endl;

    return 0;
}