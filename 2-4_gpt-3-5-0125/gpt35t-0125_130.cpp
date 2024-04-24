#include <iostream>
#include <string>

int main(int argc, char *argv[])   
{ 
    if (argc < 2) {
        std::cerr << "Please provide a number as an argument" << std::endl;
        return 1;
    }
    
    try {
        int input = std::stoi(argv[1]);
        if (input < 1) {
            std::cerr << "ERROR! Please enter a positive integer" << std::endl;
            return 1;
        }
    } catch (std::invalid_argument const &ex) {
        std::cerr << "Invalid input: " << ex.what() << std::endl;
        return 1;
    } catch (std::out_of_range const &ex) {
        std::cerr << "Number out of range: " << ex.what() << std::endl;
        return 1;
    }
    
    return 0;
}
