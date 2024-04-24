#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> backword(const std::string& input) {
    std::vector<std::string> output;
    std::stringstream ss(input);
    std::string word;
    while (ss >> word) {
        output.push_back(word);
    }
    return output;
}

int main() {
    auto output = backword("dfs sdfsdfsd dsffsdf");
    for (const auto& word : output) {
        std::cout << word << std::endl;
    }
    return 0;
}
