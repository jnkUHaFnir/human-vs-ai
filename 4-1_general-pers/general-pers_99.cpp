#include <iostream>
#include <string>

char getInput() {
    std::string input;
    
    while (true) {
        std::cout << "Enter a single character: ";
        std::cin >> input;
        
        if (input.length() == 1) {
            return input[0];
        } else {
            std::cout << "Please enter only a single character." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void singleCharInputHandler(char c) {
    std::cout << "You entered: " << c << std::endl;
    // Continue with the rest of your program logic here
}

void multipleCharInputHandler() {
    std::cout << "Multiple characters entered. Handling multiple input case..." << std::endl;
    // Handle the case where multiple characters are entered
}

int main() {
    char input = getInput();
    
    if (std::cin.fail()) {
        // Handle possible input stream failure
        std::cerr << "Input error occurred." << std::endl;
        return 1;
    }

    if (input) {
        singleCharInputHandler(input);
    } else {
        multipleCharInputHandler();
    }

    return 0;
}
