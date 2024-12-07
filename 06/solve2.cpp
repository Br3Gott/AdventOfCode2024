#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    // ifstream input{"example.txt"};
    ifstream input{"input.txt"};

    vector<string> maze;

    int startOut, startIn;

    string line;
    while (getline(input, line)) {
        maze.push_back(line);
        auto it = find(line.begin(), line.end(), '^');
        if (it != line.end()) {
            startOut = (maze.size() - 1);
            startIn = distance(line.begin(), it);
        }
    }

    vector<vector<string>> mazes;

    for (int i{}; i < maze.size(); i++) {
        for (int u{}; u < maze[i].length(); u++) {
            if (maze[i][u] == '.') {
                vector<string> tempMaze{maze};
                tempMaze[i][u] = '#';
                mazes.push_back(tempMaze);
            }
        }
    }

    int sumStuck{};
    int mazeCheck{};

    for (vector<string> m : mazes) {
        int currentOut{startOut}, currentIn{startIn};
        bool outside{};
        bool stuck{};
        int stuckCounter{};

        while (!outside && !stuck) {
            
            if (m[currentOut][currentIn] == '^') {
                if ((currentOut - 1) < 0) {
                    outside = true;
                    m[currentOut][currentIn] = '+';
                } else {
                    if (m[(currentOut - 1)][currentIn] == '#') {
                        m[currentOut][currentIn] = '>';
                    } else {
                        m[currentOut--][currentIn] = '+';
                        if (m[currentOut][currentIn] == '+') {
                            stuckCounter++;
                        }
                        m[currentOut][currentIn] = '^';
                    }
                }
            }
            if (m[currentOut][currentIn] == '>') {
                if ((currentIn + 1) > (m[currentOut].length() - 1)) {
                    outside = true;
                    m[currentOut][currentIn] = '+';
                } else {
                    if (m[currentOut][(currentIn + 1)] == '#') {
                        m[currentOut][currentIn] = 'V';
                    } else {
                        m[currentOut][currentIn++] = '+';
                        if (m[currentOut][currentIn] == '+') {
                            stuckCounter++;
                        }
                        m[currentOut][currentIn] = '>';
                    }
                }
            }
            if (m[currentOut][currentIn] == 'V') {
                if ((currentOut + 1) > (m.size() - 1)) {
                    outside = true;
                    m[currentOut][currentIn] = '+';
                } else {
                    if (m[(currentOut + 1)][currentIn] == '#') {
                        m[currentOut][currentIn] = '<';
                    } else {
                        m[currentOut++][currentIn] = '+';
                        if (m[currentOut][currentIn] == '+') {
                            stuckCounter++;
                        }
                        m[currentOut][currentIn] = 'V';
                    }
                }
            }
            if (m[currentOut][currentIn] == '<') {
                if ((currentIn - 1) < 0) {
                    outside = true;
                    m[currentOut][currentIn] = '+';
                } else {
                    if (m[currentOut][(currentIn - 1)] == '#') {
                        m[currentOut][currentIn] = '^';
                    } else {
                        m[currentOut][currentIn--] = '+';
                        if (m[currentOut][currentIn] == '+') {
                            stuckCounter++;
                        }
                        m[currentOut][currentIn] = '<';
                    }
                }
            }

            if (stuckCounter++ > 10000) {
                stuck = true;
            }
        }

        if (stuck) {
            sumStuck++;
        }
    }

    cout << sumStuck << endl;

    return 0;
}