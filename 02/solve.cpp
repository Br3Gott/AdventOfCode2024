#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

int main() {

    // ifstream input{"example.txt"};
    ifstream input{"input.txt"};

    int result{};

    string line;
    while (getline(input, line)) {

        bool valid{true};

        bool increasing{false};
        bool decreasing{false};

        stringstream ss{line};
        int previousNum;
        bool first{true};
        int num;
        while (ss >> num) {
            if (first) {
                first = false;
            } else {
                if (abs(previousNum - num) > 3 || previousNum - num == 0) {
                    valid = false;
                }
                if (previousNum > num) {
                    if (decreasing) {
                        valid = false;
                    }
                    increasing = true;
                }
                if (previousNum < num) {
                    if (increasing) {
                        valid = false;
                    }
                    decreasing = true;
                }
            }
            previousNum = num;
        }
        if (valid) {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}