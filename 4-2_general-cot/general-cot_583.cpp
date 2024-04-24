#include <iostream>
#include <string>

std::string rearrangeString(const std::string& input) {
    int input_len = input.length();
    std::string output;
    
    for (int i = 0; i < input_len; i++) {
        output += input[i];
        if (i % 2 == 1 && i != input_len - 1) { // Add space after every 2 characters
            output += ' ';
        }
    }
    return output;
}

int main() {
    std::string input = "ABCDEFGHIJKL"; // Example input
    std::string output = rearrangeString(input);
    
    std::cout << output << std::endl; // Output the rearranged string

    return 0;
}
