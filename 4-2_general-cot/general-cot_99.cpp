#include <iostream>

char getSingleCharInput() {
    std::string input;
    std::cout << "Please enter a character: ";
    std::cin >> input;

    if (input.length() > 1) {
        std::cout << "Multiple characters entered. Handling multiple characters...\n";
        // Call the function to handle multiple characters
        // handleMultipleChars(input);
        return '\0'; // Return null character or handle it accordingly
    } else {
        return input[0];
    }
}

int main() {
    char userInput = getSingleCharInput();
    
    if(userInput != '\0') {
        std::cout << "The character entered is: " << userInput << std::endl;
    } else {
        std::cout << "Multiple characters were entered. Exiting program." << std::endl;
    }

    return 0;
}
