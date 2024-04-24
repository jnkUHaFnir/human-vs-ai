#include <iostream>
#include <string>

std::string extractBaseName(const std::string& path) {
    size_t found = path.find_last_of("/");
    if(found != std::string::npos) {
        return path.substr(found + 1);
    }
    return path;
}

int main() {
    std::string filePath = "/opt/home/etc/sample";
    std::string baseName = extractBaseName(filePath);
    std::cout << "Base Name: " << baseName << std::endl;

    return 0;
}
Base Name: sample
