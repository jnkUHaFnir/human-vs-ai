#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

int main() {
    int countWords = 0, countNumbers = 0;

    std::ifstream file("input1.txt");
    std::string line;
    
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string word;
        
        while (iss >> word) {
            for (char& c : word) {
                if (c == ',' || c == '.') {
                    c = ' ';
                }
            }
            
            std::istringstream wordStream(word);
            int num;
            
            if (wordStream >> num) {
                countNumbers++;
            } else {
                countWords++;
            }
            
            std::cout << word << " ";
        }
    }

    std::cout << std::endl;
    std::cout << "Words = " << countWords << "      Numbers = " << countNumbers << std::endl;

    return 0;
}
