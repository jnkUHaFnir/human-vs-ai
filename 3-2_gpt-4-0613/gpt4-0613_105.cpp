#include <iostream>
#include <cstring>

using namespace std;

void backword(char* input, char** output)
{
    int word = 0;
    int letter = 0;

    for (int i = 0; i < strlen(input); i++)
    {
        if(input[i] == ' ')
        {
            output[word][letter] = '\0';    // NULL terminate the word
            word++;
            letter = 0;
        }
        else
        {
            output[word][letter] = input[i];
            letter++;
        }
    }

    output[word][letter] = '\0';    // NULL terminate the last word
}

int main()
{
    char** output = new char*[30];    // Allocation for words

    for(int i=0; i<30; i++) {
        output[i] = new char[50];     // Allocation for each word
    }
    
    backword((char*)"dfs sdfsdfsd dsffsdf", output);
    cout << output[1] << "\n"; //debug

    // Deallocate the memory
    for(int i=0; i<30; i++) {
        delete[] output[i];
    }
    delete[] output;

    return 0;
}

