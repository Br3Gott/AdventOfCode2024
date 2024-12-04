#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int countSubstring(const string& str, const string& sub)
{
    int count = 0;
    for (
        size_t offset = str.find(sub);
        offset != string::npos;
        offset = str.find(sub, offset + sub.length())
    )
    {
        count++;
    }
    return count;
}

int main() {

    // ifstream input{"example.txt"};
    ifstream input{"input.txt"};

    vector<string> regular;
    vector<string> vertical;
    vector<string> diagonalRight;
    vector<string> diagonalLeft;

    //prepare regular
    string line;
    while (getline(input, line)) {
        regular.push_back(line);
    }

    //prepare vertical
    for (int u{}; u < regular[0].length(); u++) {
        stringstream tempLine;
        for (int i{}; i < regular.size(); i++) {
            tempLine << regular[i].at(u);
        }
        vertical.push_back(tempLine.str());
    }

    //prepare diagonalRight
    for (int u{}; u < regular[0].length(); u++) {
        stringstream tempLine;
        int column{u};
        for (int i{}; i < regular.size(); i++) {
            if (column < regular[i].length()) {
                tempLine << regular[i].at(column++);
            }
        }
        diagonalRight.push_back(tempLine.str());
    }
    for (int u{1}; u < regular.size(); u++) {
        stringstream tempLine;
        int column{};
        for (int i{u}; i < regular.size(); i++) {
            if (column < regular[i].length()) {
                tempLine << regular[i].at(column++);
            }
        }
        diagonalRight.push_back(tempLine.str());
    }

    //prepare diagonalLeft
    for (int u{(int)regular[0].length() - 1}; u >= 0 ; u--) {
        stringstream tempLine;
        int column{u};
        for (int i{}; i < regular.size(); i++) {
            if (column >= 0) {
                tempLine << regular[i].at(column--);
            }
        }
        diagonalLeft.push_back(tempLine.str());
    }
    for (int u{1}; u < regular.size(); u++) {
        stringstream tempLine;
        int column{(int)regular[0].length() - 1};
        for (int i{u}; i < regular.size(); i++) {
            if (column >= 0) {
                tempLine << regular[i].at(column--);
            }
        }
        diagonalLeft.push_back(tempLine.str());
    }

    int sum{};

    for (string s : regular) {
        sum += countSubstring(s, "XMAS");
        sum += countSubstring(s, "SAMX");
    }
    for (string s : vertical) {
        sum += countSubstring(s, "XMAS");
        sum += countSubstring(s, "SAMX");
    }
    for (string s : diagonalRight) {
        sum += countSubstring(s, "XMAS");
        sum += countSubstring(s, "SAMX");
    }
    for (string s : diagonalLeft) {
        sum += countSubstring(s, "XMAS");
        sum += countSubstring(s, "SAMX");
    }

    cout << sum << endl;

    return 0;
}

