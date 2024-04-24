#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string data = "This is a test\nwith extra\rline breaks.";

    // Define a regular expression pattern to match non-alphanumeric characters and spaces
    std::regex pattern("[^A-Za-z0-9 ]");

    // Replace any matches with an empty string
    std::string result = std::regex_replace(data, pattern, "");

    // Output the cleaned data
    std::cout << "Cleaned data: " << result << std::endl;

    return 0;
}
