#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;

int main() {

    // ifstream input{"example.txt"};
    ifstream input{"input.txt"};

    int result{};

    stringstream buffer;

    char temp;
    while (input >> temp) {
        buffer << temp;
        if (buffer.str().size() > 4) {
            buffer.str(buffer.str().substr(1));
            buffer.seekp(0, buffer.end);
        }
        if (buffer.str() == "mul(") {
            char next = input.peek();
            if (isdigit(next)) {
                int num1, num2;
                char comma;
                input >> num1 >> comma;
                if (comma == ',' && isdigit(input.peek())) {
                    input >> num2;
                    input >> next;
                    if (next == ')') {
                        result += num1 * num2;
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