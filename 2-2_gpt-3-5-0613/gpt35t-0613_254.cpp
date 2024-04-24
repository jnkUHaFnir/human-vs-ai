#include <iostream>
#include <string>
#include <regex>

struct Person {
    std::string name;
};

bool isValidName(const std::string& name) {
    // Regular expression pattern to check for valid names (only letters and spaces)
    std::regex pattern("^[A-Za-z ]+$");
    return std::regex_match(name, pattern);
}

int main() {
    Person person;
    person.name = "Steve XYZ";

    std::string userInput;
    std::cout << "Enter a name: ";
    std::getline(std::cin, userInput);

    if (isValidName(userInput)) {
        if (userInput == person.name) {
            std::cout << "Names match!" << std::endl;
        } else {
            std::cout << "Names do not match!" << std::endl;
        }
    } else {
        std::cout << "Invalid name entered!" << std::endl;
    }

    return 0;
}
