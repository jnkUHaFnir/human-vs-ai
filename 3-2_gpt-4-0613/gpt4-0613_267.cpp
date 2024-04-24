#include <cstdio>
#include <string>
#include <fstream>

const int SIZE = 100;

int main() {
    char buffer[SIZE];
    std::string s = "This is a string.";
    std::sprintf(buffer, "%s", s.c_str());

    std::ofstream file("file.txt");
    file << buffer;

    return 0;
}
#include <sstream>
#include <string>
#include <fstream>

int main() {
    std::ostringstream oss;
    std::string s = "This is a string.";
    oss << s;

    std::ofstream file("file.txt");
    file << oss.str();

    return 0;
}
