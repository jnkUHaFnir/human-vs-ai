#include <string>
#include <iostream>

std::string extractBaseName(const std::string& path) {
    const char separator = '/';
    size_t pos = path.find_last_of(separator);
    if (pos != std::string::npos) {
        return path.substr(pos + 1);
    } else {
        return path;
    }
}

int main() {
    std::string path = "/opt/home/etc/sample";
    std::string baseName = extractBaseName(path);
    std::cout << "Base name: " << baseName << std::endl;
    return 0;
}
