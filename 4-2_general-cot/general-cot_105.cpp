#include <iostream>
#include <cstring>

using namespace std;

void backword(const char* input, char* output[])
{
    int wordIndex = 0;
    int charIndex = 0;
    output[wordIndex] = new char[strlen(input) + 1]; // Allocate memory for the first word
    for (int i = 0; i <= strlen(input); i++)
    {
        if (input[i] == ' ' || input[i] == '\0')
        {
            output[wordIndex][charIndex] = '\0'; // Null-terminate the current word
            wordIndex++;
            charIndex = 0;
            output[wordIndex] = new char[strlen(input) + 1]; // Allocate memory for the next word
        }
        else
        {
            output[wordIndex][charIndex] = input[i];
            charIndex++;
        }
    }
}

int main()
{
    char* output[30];
    backword("dfs sdfsdfsd dsffsdf", output);

    // Output the second word (index 1)
    cout << output[1] << endl;

    // Free memory allocated for words
    for (int i = 0; i < 30; i++)
    {
        delete[] output[i];
    }

    return 0;
}
