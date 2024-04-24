#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "ERROR! No input provided." << std::endl;
        return 1;
    }

    std::string input = argv[1];

    // Check if the input is a positive integer.
    if (!std::all_of(input.begin(), input.end(), ::isdigit) || input.empty())
    {
        std::cerr << "ERROR! Input is not a positive integer." << std::endl;
        return 1;
    }

    try
    {
        // Convert the input string to an integer.
        int value = std::stoi(input);

        // Check if the integer is positive.
        if (value < 1)
        {
            std::cerr << "ERROR! Input is not a positive integer." << std::endl;
            return 1;
        }

        // Continue with your program...
        // ...

    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << "ERROR! Input is not a valid integer." << std::endl;
        return 1;
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "ERROR! Input is out of integer range." << std::endl;
        return 1;
    }

    return 0;
}
