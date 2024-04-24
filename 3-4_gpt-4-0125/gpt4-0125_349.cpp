#include <string>
#include <iostream>
#include <stdexcept>

int main() {
    char* input = "12345";
    try {
        std::string strInput(input); // Convert char* to std::string
        int number = std::stoi(strInput);
        std::cout << "The number is: " << number << std::endl;
    } catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
    } catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    } catch (...) {
        std::cerr << "Unknown error occurred" << '\n';
    }
    return 0;
}
#include <iostream>
#include <cstdlib>  // for std::strtol
#include <cerrno>   // for errno

int main() {
    const char* input = "12345abc";
    char* end;
    errno = 0; // reset errno to 0 before a call to strtol
    long int number = std::strtol(input, &end, 10);

    if (end == input) {
        std::cerr << "Parse error: no digits were found\n";
    } else if (*end != '\0') {
        std::cerr << "Additional characters after number: " << end << '\n';
    } else if (errno == ERANGE) {
        std::cerr << "The number is out of the range of representable values by a long int.\n";
    } else {
        std::cout << "The number is: " << number << '\n';
    }

    return 0;
}
