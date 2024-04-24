#include <iostream>
#include <limits>

char getCharInput() {
    std::cout << "Please enter a single character: ";
    char input;
    std::cin >> input;
    
    // Check if there are more characters in the input buffer
    if (std::cin.peek() != '\n') {
        std::cout << "Error: Please enter only a single character.\n";
        std::cin.clear(); // Clear error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the rest of the input buffer
        return '\0'; // Return null character to indicate error
    }
    
    return input;
}

void processSingleCharInput(char input) {
    // Process the single character input here
    std::cout << "Processing input: " << input << std::endl;
}

int main() {
    char input = getCharInput();
    
    if (input != '\0') {
        processSingleCharInput(input);
    } else {
        // Handle the error condition where multiple characters were entered
        std::cout << "Exiting program due to invalid input.\n";
    }

    return 0;
}
