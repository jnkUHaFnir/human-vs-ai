#include <iostream>
#include <string>

int main() {
    std::string input = "ABCDEFGHIJKL";
    std::string output;

    for (int i = 0; i < input.length(); i += 2) {
        output += input[i];
        output += input[i + 1];
        if (i < input.length() - 2) {
            output += " ";
        }
    }

    std::cout << output << std::endl;

    return 0;
}
