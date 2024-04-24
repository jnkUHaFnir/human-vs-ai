#include <iostream>
#include <cstring>

using namespace std;

void backword(const char* input, char* output[])
{
    int length = strlen(input);
    int wordCount = 0;
    output[wordCount] = new char[length + 1]; // Allocate memory for the first word
    int currentWordLength = 0;

    for (int i = 0; i < length; i++)
    {
        if (input[i] == ' ')
        {
            output[wordCount][currentWordLength] = '\0'; // Null-terminate the word
            wordCount++;
            output[wordCount] = new char[length + 1]; // Allocate memory for the next word
            currentWordLength = 0;
        }
        else
        {
            output[wordCount][currentWordLength] = input[i];
            currentWordLength++;
        }
    }

    output[wordCount][currentWordLength] = '\0'; // Null-terminate the last word
}

void freeMemory(char* output[], int wordCount)
{
    for (int i = 0; i <= wordCount; i++)
    {
        delete[] output[i]; // Free memory for each word
    }
    delete[] output; // Free memory for the array of words
}

int main()
{
    const char* input = "dfs sdfsdfsd dsffsdf";
    char** output = new char*[30];
    
    backword(input, output);

    cout << output[0] << endl; // Print the first word
    cout << output[1] << endl; // Print the second word

    freeMemory(output, 2); // Assuming there are 3 words in the input

    return 0;
}
