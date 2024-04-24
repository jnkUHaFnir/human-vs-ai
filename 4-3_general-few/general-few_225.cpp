#include <iostream>
#include <string>
#include <cctype>

int main() {
    // Assume webpageData is the string containing the data from the webpage with extra line breaks
    std::string webpageData = "Your webpage data here with extra line breaks";

    std::string filteredData;
    for (char c : webpageData) {
        if (std::isalnum(c) || std::isspace(c)) {
            filteredData += c;
        }
    }

    // Output the filtered data without line breaks and non-alphanumeric characters
    std::cout << "Filtered Data: " << filteredData << std::endl;

    return 0;
}
