#include <iostream>
#include <cstring>

using namespace std;

void backword(const char* input, char* output[], int size)
{
    for(int i = 0, c = 0; input[i] != '\0'; i++)
    {
        if(input[i] == ' ')
        {
            c++;
        }
        else
        {
            if(output[c] == nullptr)
            {
                output[c] = new char[size]; // Allocate memory for the string
                output[c][0] = '\0'; // Initialize with null terminator
            }
            int len = strlen(output[c]);
            output[c][len] = input[i];
            output[c][len + 1] = '\0'; // Null-terminate the string
        }
    }

    cout << output[1]; // debug
}

int main()
{
    const int SIZE = 30;
    char* output[SIZE] = { nullptr };
    backword("dfs sdfsdfsd dsffsdf", output, SIZE);

    cout << output[1]; // debug

    // Clean up allocated memory
    for(int i = 0; i < SIZE; i++) {
        delete[] output[i];
    }

    return 0;
}
