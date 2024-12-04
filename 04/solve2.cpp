#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <format>

using namespace std;

int main() {

    // ifstream input{"example.txt"};
    ifstream input{"input.txt"};

    vector<string> regular;

    //prepare regular
    string line;
    while (getline(input, line)) {
        regular.push_back(line);
    }

    unordered_map<string, int> locations;

    //read diagonalRight
    for (int u{}; u < regular[0].length(); u++) {
        stringstream tempLine;
        int column{u};
        for (int i{}; i < regular.size(); i++) {
            if (column < regular[i].length()) {
                tempLine << regular[i].at(column++);
                if (tempLine.str().length() > 3) {
                    tempLine.str(tempLine.str().substr(1));
                    tempLine.seekp(0, tempLine.end);
                }
                if (tempLine.str() == "MAS" || tempLine.str() == "SAM") {
                    locations[format("{}:{}", (i), (column-2))]++;
                }
            }
        }
    }
    for (int u{1}; u < regular.size(); u++) {
        stringstream tempLine;
        int column{};
        for (int i{u}; i < regular.size(); i++) {
            if (column < regular[i].length()) {
                tempLine << regular[i].at(column++);
                if (tempLine.str().length() > 3) {
                    tempLine.str(tempLine.str().substr(1));
                    tempLine.seekp(0, tempLine.end);
                }
                if (tempLine.str() == "MAS" || tempLine.str() == "SAM") {
                    locations[format("{}:{}", (i), (column-2))]++;
                }
            }
        }
    }

    //read diagonalLeft
    for (int u{(int)regular[0].length() - 1}; u >= 0 ; u--) {
        stringstream tempLine;
        int column{u};
        for (int i{}; i < regular.size(); i++) {
            if (column >= 0) {
                tempLine << regular[i].at(column--);
                if (tempLine.str().length() > 3) {
                    tempLine.str(tempLine.str().substr(1));
                    tempLine.seekp(0, tempLine.end);
                }
                if (tempLine.str() == "MAS" || tempLine.str() == "SAM") {
                    locations[format("{}:{}", (i), (column+2))]++;
                }
            }
        }
    }
    for (int u{1}; u < regular.size(); u++) {
        stringstream tempLine;
        int column{(int)regular[0].length() - 1};
        for (int i{u}; i < regular.size(); i++) {
            if (column >= 0) {
                tempLine << regular[i].at(column--);
                if (tempLine.str().length() > 3) {
                    tempLine.str(tempLine.str().substr(1));
                    tempLine.seekp(0, tempLine.end);
                }
                if (tempLine.str() == "MAS" || tempLine.str() == "SAM") {
                    locations[format("{}:{}", (i), (column+2))]++;
                }
            }
        }
    }

    int sum{};

    for (auto p : locations) {
        if (p.second > 1) {
            sum++;
        }
    }

    cout << sum << endl;

    return 0;
}

