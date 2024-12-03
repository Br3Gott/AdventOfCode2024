#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;

int main() {

    // ifstream input{"example.txt"};
    ifstream input{"input.txt"};

    int result{};

    bool enabled{true};

    stringstream buffer;

    char temp;
    while (input >> temp) {
        buffer << temp;
        if (buffer.str().size() > 7) {
            buffer.str(buffer.str().substr(1));
            buffer.seekp(0, buffer.end);
        }
        if(buffer.str().ends_with("do()")) {
            enabled = true;
        }
        if(buffer.str().ends_with("don't()")) {
            enabled = false;
        }
        if (buffer.str().ends_with("mul(")) {
            char next = input.peek();
            if (isdigit(next)) {
                int num1, num2;
                char comma;
                input >> num1 >> comma;
                if (comma == ',' && isdigit(input.peek())) {
                    input >> num2;
                    input >> next;
                    if (next == ')') {
                        if (enabled) {
                            result += num1 * num2;
                        }
                        buffer.str("");
                        buffer.seekp(0, buffer.end);
                    }
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}