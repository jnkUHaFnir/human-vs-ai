#include <iostream>
#include <string>
#include <sstream>

std::string ConstructString(const std::string& header, int value, const std::string& footer) {
    std::stringstream ss;
    ss << header << value << footer;
    return ss.str();
}

int main() {
    int FrontVIB = 200; // Value fetched from memory
    int RearVIB = 200;  // Value fetched from memory

    std::string String4H1 = ConstructString("*FV", FrontVIB, "#");
    std::string String4H3 = ConstructString("*RV", RearVIB, "#");

    std::cout << "String4H1: " << String4H1 << std::endl;
    std::cout << "String4H3: " << String4H3 << std::endl;

    return 0;
}
