#include <iostream>
#include <cstring>

using namespace std;

void backword(const char* input, char* output[])
{
    int length = strlen(input);

    for (int i = 0, c = 0; i < length; i++)
    {
        if (input[i] == ' ')
        {
            c++;
            i++;
        }

        if (output[c] == nullptr) // Check if memory is already allocated
        {
            output[c] = new char[length]; // Allocate memory for the element
        }

        output[c] += input[i];
    }
    cout << output[1]; // Debug
}

int main()
{
    char* output[30] = {}; // Initialize all elements of output to nullptr

    backword("dfs sdfsdfsd dsffsdf", output);
    
    cout << output[1]; // Debug

    // Free memory
    for (int i = 0; i < 30; i++)
    {
        delete[] output[i];
    }

    return 0;
}
