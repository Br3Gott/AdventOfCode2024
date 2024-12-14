#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    // ifstream input{"example.txt"};
    ifstream input{"input.txt"};

    vector<int> disk{};
    bool files{true};
    size_t block{};
    char c{};
    while (input >> c) {
        int val = c - '0';
        for (size_t i{}; i < val; i++) {
            disk.push_back(files ? block : -1);
        }
        if (files) {
            block++;
        }
        files = !files;
    }

    auto it = find(disk.begin(), disk.end(), -1);
    while (it != disk.end()) {
        int val{-1};
        while (val == -1) {
            val = disk.back();
            disk.pop_back();
        }
        *it = val;
        it = find(disk.begin(), disk.end(), -1);
    }

    size_t sum{};
    for (size_t i{}; i < disk.size(); i++) {
        sum += disk[i] * i;
    }

    cout << sum << endl;

    return 0;
}