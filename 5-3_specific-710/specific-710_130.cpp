#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])   
{ 
    if(argc < 2)
    {
        std::cerr << "Error: No input provided." << std::endl;
        return 1;
    }

    char* input = argv[1];
    char* endptr;
    long value = strtol(input, &endptr, 10);

    if (*endptr != '\0' || value <= 0)
    {
        std::cerr << "Error: Input must be a positive integer." << std::endl;
        return 1;
    }

    // Input is a valid positive integer
    std::cout << "Input is a positive integer: " << value << std::endl;

    return 0;
}
