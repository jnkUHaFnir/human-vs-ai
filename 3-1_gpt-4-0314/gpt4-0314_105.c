#include <iostream>
#include <cstring>

using namespace std;

void backword(char* input, char* output[])
{
    int c = 0;
    int index = 0;
    for(int i = 0; i < strlen(input); i++)
    {
        if(input[i] == ' ')
        {
            output[c][index] = '\0'; // add null terminator
            c++;
            index = 0; // reset index for the next word
            continue;
        }
        output[c][index] = input[i];
        index++;
    }
    output[c][index] = '\0'; // add a null terminator for the last word
    cout << output[1] << endl; // debug
}

int main()
{
    const int MAX_WORDS = 30;
    const int MAX_LENGTH = 100;
    char** output = new char*[MAX_WORDS];
    for(int i = 0; i < MAX_WORDS; ++i)
    {
        output[i] = new char[MAX_LENGTH]; // allocate memory for each char*
    }

    backword("dfs sdfsdfsd dsffsdf", output);
    cout << output[1] << endl; // debug
    cout << output[0] << endl; // debug
    cout << output[2] << endl; // debug

    for(int i = 0; i < MAX_WORDS; ++i)
    {
        delete[] output[i]; // delete each char*
    }
    delete[] output; // delete the main array

    return 0;
}
sdfsdfsd
sdfsdfsd
dfs
dsffsdf
