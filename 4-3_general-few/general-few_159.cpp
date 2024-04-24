#include <iostream>
#include <limits>

int main() {
    std::string userInput;
    int maxValue = std::numeric_limits<int>::max();

    std::cout << "Enter a number: ";
    std::cin >> userInput;

    if (userInput.length() > std::to_string(maxValue).length() ||
        (userInput.length() == std::to_string(maxValue).length() && userInput > std::to_string(maxValue))) {
        std::cout << "Input value is too large, please re-enter.\n";
    } else {
        int inputAsInt = std::stoi(userInput);
        std::cout << "Input value: " << inputAsInt << std::endl;
    }

    return 0;
}
