#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include <unordered_map>

using namespace std;

unordered_map<size_t, unordered_map<size_t, size_t>> preComputedStones;

size_t blink (size_t start, size_t pos) {
    if (! preComputedStones[pos][start]) {
        vector<size_t> stones{start};
        for (auto it = stones.begin(); it != stones.end(); it++) {
            string str{to_string(*it)};
            if (*it == 0) {
                *it = 1;
            } else if (str.length() % 2 == 0) {
                *it = stoul(str.substr(0, str.length() / 2));
                it = stones.insert(it + 1, stoul(str.substr(str.length() / 2, str.length() / 2)));
            } else {
                *it = *it * 2024;
            }
            size_t amount{};
            for (size_t stone : stones) {
                if ((pos - 1) != 0) {
                    amount += blink(stone, (pos - 1));
                } else {
                    amount++;
                }
            }
            preComputedStones[pos][start] = amount;
        }
    }
    return preComputedStones[pos][start];
}

int main() {

    // ifstream input{"example.txt"};
    ifstream input{"input.txt"};

    vector<size_t> stones{istream_iterator<size_t>(input), istream_iterator<size_t>()};

    size_t amount{};
    for (size_t stone : stones) {
        amount += blink(stone, 75);
    }

    cout << amount << endl;

    return 0;
}