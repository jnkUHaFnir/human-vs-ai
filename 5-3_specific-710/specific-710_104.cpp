#include <iostream>
#include <cstring>

using namespace std;

void backword(const char* input, char* output[])
{
    int c = 0;
    output[c] = new char[strlen(input) + 1]; // allocate memory for the first word
    int output_index = 0;

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ')
        {
            output[c][output_index] = '\0'; // null-terminate the current word
            c++;
            output[c] = new char[strlen(input) + 1]; // allocate memory for the next word
            output_index = 0;
        }
        else
        {
            output[c][output_index] = input[i];
            output_index++;
        }
    }
    output[c][output_index] = '\0'; // null-terminate the last word
}

int main()
{
    char** output = new char*[30];
    backword("dfs sdfsdfsd dsffsdf", output);

    cout << output[0] << endl; // output the first word
    cout << output[1] << endl; // output the second word

    // Free dynamically allocated memory
    for (int i = 0; output[i] != nullptr; i++)
    {
        delete[] output[i];
    }
    delete[] output;

    return 0;
}
