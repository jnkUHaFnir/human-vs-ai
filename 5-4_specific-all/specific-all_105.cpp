#include <iostream>
#include <cstring>

using namespace std;

void backword(const char* input, char* output[])
{
    int c = 0;
    for (int i = 0, j = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ')
        {
            output[c][j] = '\0'; // Terminate the current string
            c++; // Move to the next string in output array
            j = 0; // Reset the index for the new string
        }
        else
        {
            output[c][j] = input[i]; // Copy the character
            j++; // Move to the next position in the current string
        }
    }
    output[c][j] = '\0'; // Terminate the last string
}

int main()
{
    char* output[30];
    for (int i = 0; i < 30; i++)
    {
        output[i] = new char[100]; // Assuming max string length is 100
    }

    backword("dfs sdfsdfsd dsffsdf", output);

    cout << output[1] << endl;

    // Don't forget to free the allocated memory
    for (int i = 0; i < 30; i++)
    {
        delete[] output[i];
    }

    return 0;
}
