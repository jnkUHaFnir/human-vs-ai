#include <iostream>
#include <cstring>

using namespace std;

// Allocate and split the sentence into words.
void backward(const char* input, char**& output, int& wordCount)
{
    int length = strlen(input);
    wordCount = 0; // To count the number of words
    
    // Allocate temporary space for a word. In the worst case, a word could be as long as the input string.
    char* tempWord = new char[length + 1];
    
    for(int i = 0, j = 0; i <= length; i++)
    {
        if(input[i] == ' ' || input[i] == '\0') // End of a word or the input string
        {
            tempWord[j] = '\0'; // Null-terminate the current word
            // Allocate exact space for the word and copy it from tempWord
            output[wordCount] = new char[j + 1];
            strcpy(output[wordCount], tempWord);
            
            wordCount++; // Increase word count
            j = 0; // Reset index for the next word
        }
        else
        {
            tempWord[j++] = input[i]; // Copy character to tempWord
        }
    }
    
    delete[] tempWord; // Clean up temporary word space
}

int main()
{
    char** output = new char*[30]; // Allocate space for pointers to words

    int wordCount = 0; // To store the actual number of words
    backward("dfs sdfsdfsd dsffsdf", output, wordCount);

    for(int i = 0; i < wordCount; i++) // Print each word
    {
        cout << output[i] << endl;
        delete[] output[i]; // Clean up each word's allocated space
    }

    delete[] output; // Clean up the array of pointers

    return 0;
}
