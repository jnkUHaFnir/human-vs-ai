#include <iostream>
#include <fstream>

int main() {
    std::string str;
    int num = 10;
    float value = 3.14;

    // Format the string using sprintf
    sprintf(str, "The number is %d and the value is %.2f", num, value);

    // Send the string into a file stream
    std::ofstream file("output.txt");
    if (file.is_open()) {
        file << str;
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }

    return 0;
}
