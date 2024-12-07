#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main() {

    // ifstream input{"example.txt"};
    ifstream input{"input.txt"};

    vector<unsigned long long> results;
    vector<vector<unsigned long long>> valuesList;

    unsigned long long total{};

    string line;
    while (getline(input, line)) {
        stringstream ss{line};
        unsigned long long result;
        char trash;
        unsigned long long value;
        vector<unsigned long long> values;
        ss >> result >> trash;
        results.push_back(result);
        while (ss >> value) {
            values.push_back(value);
        }
        valuesList.push_back(values);
    }

    for (size_t i{}; i < results.size(); i++) {
        vector<unsigned long long> combinationsSums;
        
        size_t pos{2};
        combinationsSums.push_back(valuesList[i][0] + valuesList[i][1]);
        combinationsSums.push_back(valuesList[i][0] * valuesList[i][1]);
        combinationsSums.push_back(stoull(to_string(valuesList[i][0]) + to_string(valuesList[i][1])));

        while (pos < valuesList[i].size()) {
            vector<unsigned long long> tempCombinationsSums{combinationsSums};
            combinationsSums.erase(combinationsSums.begin(), combinationsSums.end());
            for (unsigned long long s : tempCombinationsSums) {
                combinationsSums.push_back(s + valuesList[i][pos]);
                combinationsSums.push_back(s * valuesList[i][pos]);
                combinationsSums.push_back(stoull(to_string(s) + to_string(valuesList[i][pos])));
            }
            pos++;
        }

        bool success{};
        for (unsigned long long result : combinationsSums) {
            if (result == results[i]) {
                success = true;
            }
        }
        if (success) {
            total += results[i];
        }
    }

    cout << total << endl;

    return 0;
}