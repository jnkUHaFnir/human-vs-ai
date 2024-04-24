#include <iostream>
#include <cstring>

using std::cerr;
using std::endl;

bool isPositiveInteger(const char* str) {
    if(str == nullptr || *str == '\0') // Check if string is empty or null
        return false;

    // Check if the first character is a positive sign, skip if true.
    if(str[0] == '+') 
        ++str;

    // Check if each character is a digit
    while (*str) {
        if (!isdigit(*str)) // If not a digit, return false
            return false;
        ++str;
    }
    return true;
}

int main(int argc, char *argv[])
{
    if (argc < 2 || !isPositiveInteger(argv[1]) || atoi(argv[1]) < 1) {
        cerr << "ERROR!" << endl;
        return 1;
    }
    // Your program logic here
    return 0;
}
