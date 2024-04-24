#include <iostream>
#include <fstream>
#include <cstdio> // For snprintf

int main() {
    std::ofstream file("output.txt", std::ios::app); // Open file in append mode
    if (!file.is_open()) return -1;

    const int bufferSize = 256;
    char buffer[bufferSize];

    int value = 42;
    const char *text = "value is";

    // Safely format the string into the buffer
    snprintf(buffer, sizeof(buffer), "%s: %d", text, value);

    // Write to file stream
    file << buffer;
    file.close();

    return 0;
}
#include <iostream>
#include <fstream>
#include <sstream> // For std::ostringstream

int main() {
    std::ofstream file("output.txt", std::ios::app); // Open file in append mode
    if (!file.is_open()) return -1;

    int value = 42;
    const char *text = "value is";

    // Use std::ostringstream for safe and convenient formatting
    std::ostringstream oss;
    oss << text << ": " << value;

    // Write directly to file stream
    file << oss.str();
    file.close();

    return 0;
}
