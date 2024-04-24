#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string inputString = "Hello, %s! Your age is %d.";

    char formattedString[256]; // adjust the buffer size as needed

    const char* name = "John";
    int age = 25;

    sprintf(formattedString, inputString.c_str(), name, age);

    std::ofstream file("output.txt");
    if (file.is_open()) {
        file << formattedString << std::endl;
        file.close();
        std::cout << "String formatted and written to file successfully." << std::endl;
    } else {
        std::cerr << "Error opening file." << std::endl;
    }

    return 0;
}
