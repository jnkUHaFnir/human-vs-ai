#include <iostream>
#include <cstdlib>  // For atoi()
#include <string>
using namespace std;

bool isPositiveInteger(const char *str)
{
    while(*str != '\0')
    {
        if (!isdigit(*str))
        {
            return false;
        }
        str++;
    }
    return true;
}

int main(int argc, char *argv[])
{
    if(argc != 2 || !isPositiveInteger(argv[1]) || atoi(argv[1]) < 1)
    {
        cerr << "ERROR! Please provide a positive integer as input." << endl;
        return 1;
    }

    // Add your program's functionality here

    return 0;
}
