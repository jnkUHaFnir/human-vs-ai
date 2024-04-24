#include <iostream>
#include <cstring>

using namespace std;

void backword(const char* input, char* output[])
{
    int c = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == ' ')
        {
            c++;
        }
        else
        {
            if (output[c] == nullptr) {
                output[c] = new char[strlen(input) + 1]; // +1 to include null terminator
                strcpy(output[c], ""); // initialize the string
            }
            char temp[2] = {input[i], '\0'};
            strcat(output[c], temp);
        }
    }
    cout << output[1]; // debug
}

int main()
{
    char** output = new char*[30];
    backword("dfs sdfsdfsd dsffsdf", output);
    cout << output[1]; // debug
    // Don't forget to free memory
    for (int i = 0; i < 30; i++) {
        delete[] output[i];
    }
    delete[] output;
    return 0;
}
