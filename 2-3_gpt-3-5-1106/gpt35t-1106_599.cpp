In maths, which of the following numbers is not referred to as a square number?;
A: 0;
B: 1;
C: 2;
D: 3;
---
What is the capital of France?;
A: London;
B: Paris;
C: Rome;
D: Berlin;
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream infile("questions.txt");
    std::string line;

    while (std::getline(infile, line)) {
        if (line != "---") {
            // Split the line into question and answers
            // Then display the question and answers
            std::cout << line << std::endl;
            // ...
        }
    }

    return 0;
}
