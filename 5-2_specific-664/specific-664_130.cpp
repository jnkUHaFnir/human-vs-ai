#include <iostream>
#include <string>

int main(int argc, char *argv[])   
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <positive_integer>" << std::endl;
        return 1;
    }

    try {
        int inputValue = std::stoi(argv[1]);
        if (inputValue < 1) {
            std::cerr << "ERROR: Please input a positive integer." << std::endl;
            return 1;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "ERROR: Invalid input. Please input a positive integer." << std::endl;
        return 1;
    } catch (const std::out_of_range& e) {
        std::cerr << "ERROR: Input out of range. Please input a smaller positive integer." << std::endl;
        return 1;
    }

    // If the input is a valid positive integer, continue with the program
    return 0;
}
