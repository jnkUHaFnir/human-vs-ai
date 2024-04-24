#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>

std::string readZipFile(const std::string& zipFilePath) {
    std::ifstream file(zipFilePath, std::ios::in | std::ios::binary);
    if (!file.is_open()) {
        // Handle error opening file
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    return buffer.str();
}

int main() {
    std::string zipFilePath = "example.zip";
    std::string zipData = readZipFile(zipFilePath);

    if (zipData.empty()) {
        std::cout << "Failed to read zip file" << std::endl;
        return 1;
    }

    // Use zipData as needed, e.g., sending it in a POST request

    return 0;
}
