#include <iostream>
#include <fstream>

int main()
{
    std::ifstream file("numbers.txt", std::ios::in);
    if (!file.is_open())
    {
       std::cout << "Error opening file" << std::endl;
       return 1;
    }

    char numbers[4][15];

    for (unsigned lines = 0; lines < 4; ++lines)
    {
        if (!file.getline(numbers[lines], 15, '\n'))
        {
            std::cout << "Error reading line" << std::endl;
            break;
        }
    }

    // Printing the read numbers
    for (unsigned i = 0; i < 4; ++i)
    {
        std::cout << "Number " << i+1 << ": " << numbers[i] << std::endl;
    }

    file.close();

    return 0;
}
