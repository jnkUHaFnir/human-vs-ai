#include <iostream>
#include <string>
#include <sstream>

std::string ConvertToString(const std::string& prefix, int value, const std::string& suffix) {
    std::stringstream ss;
    ss << prefix << value << suffix;
    return ss.str();
}

int main() {
    int data = 200; // fetched from memory
    std::string result1 = ConvertToString("*FV", data, "#");
    std::string result2 = ConvertToString("*RV", data, "#");

    std::cout << result1 << std::endl;  // *FV200#
    std::cout << result2 << std::endl;  // *RV200#

    return 0;
}
