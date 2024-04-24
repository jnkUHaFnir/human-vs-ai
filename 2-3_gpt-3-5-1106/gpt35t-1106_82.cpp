#include <iostream>
#include <sstream>

int main() {
    unsigned short FrontVIB = GetWord(@FrontVIB@, 0);
    unsigned short RearVIB = GetWord(@RearVIB@, 0);

    std::stringstream string1, string2;
    string1 << "*FV" << std::setfill('0') << std::setw(3) << FrontVIB << "#";
    string2 << "*RV" << std::setfill('0') << std::setw(3) << RearVIB << "#";

    std::string String4H1 = string1.str();
    std::string String4H3 = string2.str();

    std::cout << "String4H1: " << String4H1 << std::endl;
    std::cout << "String4H3: " << String4H3 << std::endl;

    return 0;
}
