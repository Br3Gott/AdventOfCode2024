#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int main() {

    // ifstream input{"example.txt"};
    ifstream input{"input.txt"};

    string line;
    vector<int> row1;
    map<int, int> row2;

    while (getline(input, line)) {
        stringstream ss{line};
        int temp;
        ss >> temp;
        row1.push_back(temp);
        ss >> temp;
        row2[temp]++;
    }

    int sum{};

    for(int i : row1) {
        sum += i * row2[i];
    }

    cout << sum << endl;

    return 0;
}