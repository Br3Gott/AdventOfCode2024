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
            if (valid) {
                sum += numbers[ceil(numbers.size() / 2)];
            } 
        }
    }

    cout << sum << endl;

    return 0;
}