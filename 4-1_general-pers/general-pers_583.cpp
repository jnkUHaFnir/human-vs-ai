#include <iostream>
#include <string>

std::string addSpaces(const std::string& input) {
    std::string result;
    int input_len = input.length();
    result.reserve((2*input_len) - 1); // reserve space for the new string
    
    for (int i = 0; i < input_len; i += 2) {
        result += input[i]; // add the first character
        
        if (i + 1 < input_len) {
            result += input[i + 1]; // add the second character
            
            if (i + 2 < input_len) {
                result += ' '; // add a space if there are more characters left
            }
        }
    }
    
    return result;
}

int main() {
    std::string input = "ABCDEFGHI";
    std::string output = addSpaces(input);
    std::cout << output << std::endl; // Output: AB CD EF GH
    return 0;
}
