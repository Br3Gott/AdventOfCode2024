#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    // ifstream input{"example.txt"};
    ifstream input{"input.txt"};

    vector<string> maze;

    int currentOut, currentIn;
    bool outside{};

    string line;
    while (getline(input, line)) {
        maze.push_back(line);
        auto it = find(line.begin(), line.end(), '^');
        if (it != line.end()) {
            currentOut = (maze.size() - 1);
            currentIn = distance(line.begin(), it);
        }
    }

    while (!outside) {
        if (maze[currentOut][currentIn] == '^') {
            if ((currentOut - 1) < 0) {
                outside = true;
                maze[currentOut][currentIn] = '+';
            } else {
                if (maze[(currentOut - 1)][currentIn] == '#') {
                    maze[currentOut][currentIn] = '>';
                } else {
                    maze[currentOut--][currentIn] = '+';
                    maze[currentOut][currentIn] = '^';
                }
            }
        }
        if (maze[currentOut][currentIn] == '>') {
            if ((currentIn + 1) > (maze[currentOut].length() - 1)) {
                outside = true;
                maze[currentOut][currentIn] = '+';
            } else {
                if (maze[currentOut][(currentIn + 1)] == '#') {
                    maze[currentOut][currentIn] = 'V';
                } else {
                    maze[currentOut][currentIn++] = '+';
                    maze[currentOut][currentIn] = '>';
                }
            }
        }
        if (maze[currentOut][currentIn] == 'V') {
            if ((currentOut + 1) > (maze.size() - 1)) {
                outside = true;
                maze[currentOut][currentIn] = '+';
            } else {
                if (maze[(currentOut + 1)][currentIn] == '#') {
                    maze[currentOut][currentIn] = '<';
                } else {
                    maze[currentOut++][currentIn] = '+';
                    maze[currentOut][currentIn] = 'V';
                }
            }
        }
        if (maze[currentOut][currentIn] == '<') {
            if ((currentIn - 1) < 0) {
                outside = true;
                maze[currentOut][currentIn] = '+';
            } else {
                if (maze[currentOut][(currentIn - 1)] == '#') {
                    maze[currentOut][currentIn] = '^';
                } else {
                    maze[currentOut][currentIn--] = '+';
                    maze[currentOut][currentIn] = '<';
                }
            }
        }
        
    }

    int sum{};

    for (auto l : maze) {
        for (char c : l) {
            if (c == '+') {
                sum++;
            }
        }
    }

    cout << sum << endl;

    return 0;
}