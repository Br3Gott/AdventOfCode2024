#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void printDisk (vector<int> disk) {
    for (int c : disk) {
        cout << c;
    }
    cout << endl;
}

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

    vector<int> alreadyMoved;
    size_t count{};
    size_t pos{disk.size() - 1};
    while (pos > 0) {
        if (disk[pos] != -1 && find(alreadyMoved.begin(), alreadyMoved.end(), disk[pos]) == alreadyMoved.end()) {
            size_t freeReq{};
            size_t searchPos{pos};
            while (disk[searchPos--] == disk[pos] && searchPos > 0) {
                freeReq++;
            }
            size_t foundFree{};
            size_t newPos{pos};
            bool found{};
            for (size_t i{}; i < pos && !found; i++) {
                if (disk[i] == -1) {
                    foundFree++;
                    if (foundFree == freeReq) {
                        newPos = i - foundFree + 1;
                        found = true;
                    }
                } else {
                    foundFree = 0;
                }
            }
            if (newPos < pos) {
                for (size_t i{}; i < freeReq; i++) {
                    disk[newPos + i] = disk[pos];
                }
                for (int t{}; t < freeReq; t++) {
                    disk[pos - (freeReq-1) + t] = -2;
                }
            } 
            alreadyMoved.push_back(disk[pos]);
            pos -= freeReq;
        } else {
            pos--;
        }
        count++;
    }

    size_t sum{};
    for (size_t i{}; i < disk.size(); i++) {
        if (disk[i] != -1 && disk[i] != -2 ) {
            sum += (disk[i]) * i;
        }
    }

    cout << sum << endl;

    return 0;
}