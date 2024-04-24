#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::ostringstream formattedStringStream;
    int number = 42;
    double value = 3.14;

    formattedStringStream << "The number is: " << number << ", and the value is: " << value;

    std::string formattedString = formattedStringStream.str();

    std::ofstream file("output.txt");
    file << formattedString;

    file.close();

    return 0;
}
