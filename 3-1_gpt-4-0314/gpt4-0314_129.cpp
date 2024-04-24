#include <iostream>
#include <fstream>

int main()
{
    std::ifstream file("numbers.txt");

    char numbers[4][15];

    // Initialize the loop variable `lines` outside the loop
    unsigned lines = 0;

    // Read only 4 lines and break the loop if the end of file is reached
    for(; lines < 4 && file.getline(numbers[lines],15,'\n'); ++lines){}

    file.close(); // Close the file

    // Display the read numbers
    for(unsigned i = 0; i < lines; ++i)
    {
        std::cout << "Number " << i + 1 << ": " << numbers[i] << std::endl;
    }

    return 0;
}
