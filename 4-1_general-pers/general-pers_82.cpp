#include <iostream>
#include <string>
#include <sstream>

std::string ConvertToString(const std::string& prefix, int number, const std::string& suffix) {
    std::ostringstream oss;
    oss << prefix << std::setfill('0') << std::setw(3) << number << suffix;
    return oss.str();
}

int main() {
    int frontVIB = GetWord("@FrontVIB@", 0);
    int rearVIB = GetWord("@RearVIB@", 0);

    std::string rvString = ConvertToString("*RV", frontVIB, "#");
    std::string fvString = ConvertToString("*FV", rearVIB, "#");

    std::cout << "rvString: " << rvString << std::endl;
    std::cout << "fvString: " << fvString << std::endl;

    return 0;
}

unsigned short GetWord(const char* address, int offset) {
    // Implement your logic to fetch the word value from memory address
    return 200; // Just a placeholder return value for demonstration
}
