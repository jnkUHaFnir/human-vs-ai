#include <iostream>
#include <cctype> // Needed for isdigit()
using namespace std;

bool isPositiveInteger(string str)
{
    // Iterating over each character in the string
    for(char const &c: str)
    {
        // If the character is not a digit
        if(!isdigit(c))
            return false;
    }

    // If all characters were digits, atoi() will be safe to use
    return atoi(str.c_str()) > 0;
}

int main(int argc, char *argv[])
{
    if(argc < 2 || !isPositiveInteger(argv[1]))
    {
        cerr << "ERROR!"<< endl;
        return 1;
    } 
    return 0;
}
