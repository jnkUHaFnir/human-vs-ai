#include <iostream>
#include <vector>

int main() {
    // Example char array
    char data[] = {0, 0, 0, 0, 'H', 'e', 'l', 'l', 'o', 0, 'W', 'o', 'r', 'l', 'd', 0, 0, 0, 0};

    // Calculate the total length of the char array
    int totalLength = sizeof(data) / sizeof(char);

    // Starting index to iterate from (assuming byte 8 based on your question)
    int startIndex = 8;

    // Vector to store the extracted strings
    std::vector<std::string> strings;

    // Variables to keep track of the start and end indices of each string
    int start = startIndex;
    int end = start;

    // Iterate through the char array
    for (int i = start; i < totalLength; i++) {
        // Check if we have encountered the NUL char ('\0')
        if (data[i] == '\0') {
            // Extract the string from the char array
            std::string str(&data[start], end - start);

            // Add the string to the vector
            strings.push_back(str);

            // Update the start and end indices for the next string
            start = i + 1;
            end = start;
        } else {
            end++;
        }
    }

    // Print the extracted strings
    for (const auto& str : strings) {
        std::cout << str << std::endl;
    }

    return 0;
}
