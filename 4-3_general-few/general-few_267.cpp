#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string myString = "Hello, World!";
    const char* formattedString = myString.c_str();

    std::ofstream file("output.txt");
    if (file.is_open()) {
        fprintf(file, "%s\n", formattedString);
        file.close();
        std::cout << "String written to file." << std::endl;
    } else {
        std::cerr << "Error opening file." << std::endl;
    }

    return 0;
}
