#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <positive_integer>" << std::endl;
        return 1;
    }

    try {
        int input = std::stoi(argv[1]);
        
        if (input < 1) {
            std::cerr << "ERROR: Please enter a positive integer." << std::endl;
            return 1;
        }
    } catch (std::exception& e) {
        std::cerr << "ERROR: Invalid input. Please enter a valid positive integer." << std::endl;
        return 1;
    }

    // Rest of your program logic here
    
    return 0;
}
