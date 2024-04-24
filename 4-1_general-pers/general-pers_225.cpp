#include <iostream>
#include <string>
#include <cctype>

std::string filterString(const std::string& input) {
    std::string filteredString;
    for (char c : input) {
        if (std::isalnum(c) || std::isspace(c)) {
            filteredString += c;
        }
    }
    return filteredString;
}

int main() {
    // Simulating data received from libcurl
    std::string dataWithLineBreaks = "Hello !#$%^World\n123\n456";

    // Filtering unwanted characters
    std::string filteredData = filterString(dataWithLineBreaks);

    std::cout << "Original data: " << dataWithLineBreaks << std::endl;
    std::cout << "Filtered data: " << filteredData << std::endl;

    return 0;
}
