#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    // ifstream input{"example.txt"};
    ifstream input{"input.txt"};

    unordered_map<int, vector<int>> rules;

    vector<vector<int>> invalid;

    int sum{};
    bool ruleSection{true};
    string line;
    while (getline(input, line)) {
        stringstream ss{line};
        if (ruleSection) {
            if (line == "") {
                ruleSection = false;
            } else {
                int first, second;
                char trash;
                ss >> first >> trash >> second;
                rules[first].push_back(second);
            }
        } else {
            replace(line.begin(), line.end(), ',', ' ');
            ss.str(line);
            bool valid{true};
            vector<int> numbers;
            int current;
            while (ss >> current) {
                for (int check : numbers) {
                    if (find(rules[check].begin(), rules[check].end(), current) == rules[check].end()) {
                        valid = false;
                    }
                }
                numbers.push_back(current);
            }
            if (!valid) {
                invalid.push_back(numbers);
            } 
        }
    }

    for (auto numbers : invalid) {
        vector<int> newNumbers;
        for (int current : numbers) {
            bool inserted{};
            for (int i{}; i < newNumbers.size(); i++) {
                if (find(rules[newNumbers[i]].begin(), rules[newNumbers[i]].end(), current) != rules[newNumbers[i]].end()) {
                    if (!inserted) {
                        newNumbers.insert(newNumbers.begin() + i, current);
                        inserted = true;
                    }
                }
            }
            if (!inserted) {
                newNumbers.push_back(current);
            }
        }
        sum += newNumbers[ceil(newNumbers.size() / 2)];
    }

    cout << sum << endl;

    return 0;
}