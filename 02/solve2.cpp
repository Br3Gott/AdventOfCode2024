#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>

using namespace std;

int main() {

    // ifstream input{"example.txt"};
    ifstream input{"input.txt"};

    int result{};

    string line;
    while (getline(input, line)) {

        stringstream ss{line};

        int temp;
        vector<int> filteredLine;
        while (ss >> temp) {
            filteredLine.push_back(temp);
        }

        vector<vector<int>> lineMutations;

        for (int i{}; i < filteredLine.size(); i++) {
            vector<int> tempLine{filteredLine};
            tempLine.erase(tempLine.begin() + i);
            lineMutations.push_back(tempLine);
        }

        int anyValid{false};
        for (auto l : lineMutations) {

            bool valid{true};

            bool increasing{false};
            bool decreasing{false};

            int previousNum;
            bool first{true};
            for (int num : l) {
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
                anyValid = true;
            }
        }
        if (anyValid) {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}