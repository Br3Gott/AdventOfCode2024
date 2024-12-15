#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <format>

using namespace std;

vector<vector<int>> topo;
vector<unordered_map<string, bool>> finds;

void check(size_t i, size_t u, unordered_map<string, bool> visited, size_t id) {
    visited[format("{}:{}", i, u)] = true;
    if (topo[i][u] == 9) {
        finds[id][format("{}:{}", i, u)] = true;
    }
    // check up
    if (i > 0 && !visited[format("{}:{}", (i - 1), u)]) {
        if (topo[i - 1][u] == (topo[i][u] + 1)) {
            check((i - 1), u, visited, id);
        }
    }
    // check down
    if (i < (topo.size() - 1) && !visited[format("{}:{}", (i + 1), u)]) {
        if (topo[i + 1][u] == (topo[i][u] + 1)) {
            check((i + 1), u, visited, id);
        }
    }
    // check left
    if (u > 0 && !visited[format("{}:{}", i, (u - 1))]) {
        if (topo[i][u - 1] == (topo[i][u] + 1)) {
            check(i, (u - 1), visited, id);
        }
    }
    // check right
    if (u < (topo[i].size() - 1) && !visited[format("{}:{}", i, (u + 1))]) {
        if (topo[i][u + 1] == (topo[i][u] + 1)) {
            check(i, (u + 1), visited, id);
        }
    }
}

int main() {

    // ifstream input{"example.txt"};
    ifstream input{"input.txt"};

    string line;
    while (getline(input, line)) {
        stringstream ss{line};
        vector<int> row;
        char height;
        while (ss >> height) {
            row.push_back(height - '0');
        }
        topo.push_back(row);
    }

    size_t id{};
    for (size_t i{}; i < topo.size(); i++) {
        for (size_t u{}; u < topo[i].size(); u++) {
            if (topo[i][u] == 0) {
                finds.push_back({});
                unordered_map<string, bool> visited;
                visited[i + ":" + u] = true;
                check(i, u, visited, id++);
            }
        }
    }

    size_t sum{};
    for (auto f : finds) {
        sum += f.size();
    }

    cout << sum << endl;

    return 0;
}