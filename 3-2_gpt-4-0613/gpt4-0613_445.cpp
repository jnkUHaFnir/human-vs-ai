#include <iostream>
#include <string>

std::string filter_input(const std::string &input) {
    std::string result;
    for(auto const &c: input) {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == ' ') {
            result += c;
        }
    }
    return result;
}

int main() {
    std::string data = "Your cURL data with \n line breaks...and other special characters...";
    std::string filtered = filter_input(data);
    std::cout << "Filtered data: " << filtered << std::endl;
    return 0;
}
