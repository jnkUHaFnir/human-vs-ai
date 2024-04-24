#include <iostream>
#include <string>
#include <sstream>

std::string ConvertToString(const std::string& subject, const std::string& insert, int pos) {
    std::string result = subject;
    result.insert(pos, insert);
    return result;
}

std::string ConstructString(int value) {
    std::ostringstream oss;
    oss << "*FV" << std::setfill('0') << std::setw(3) << value << "#";
    return oss.str();
}

int main() {
    unsigned short BUF = GetWord("@FrontVIB@", 0);
    unsigned short BUF1 = GetWord("@RearVIB@", 0);

    std::string String4H1 = ConstructString(BUF);
    std::string String4H3 = ConstructString(BUF1);

    std::cout << String4H1 << std::endl;
    std::cout << String4H3 << std::endl;

    return 0;
}
