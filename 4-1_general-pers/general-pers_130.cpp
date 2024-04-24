#include <iostream>
#include <string>

int main(int argc, char *argv[])   
{ 
    if (argc < 2) { // Check if there are enough command line arguments
        std::cerr << "Usage: " << argv[0] << " <positive_integer>" << std::endl;
        return 1;
    }

    try {
        int number = std::stoi(argv[1]); // Convert input to integer
        if (number <= 0) {
            throw std::invalid_argument("Input value is not a positive integer");
        }
    } catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
