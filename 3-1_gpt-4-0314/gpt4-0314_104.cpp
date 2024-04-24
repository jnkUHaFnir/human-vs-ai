#include <iostream>
#include <cstring>

using namespace std;

void backword(char* input, char* output[])
{
    for(int i = 0, c = 0, pos = 0; strlen(input)>i; i++)
    {
        if(input[i] == ' ')
        {
            output[c][pos] = '\0'; // Add null termination to the current string
            c++;
            pos = 0;
            continue;
        }
        output[c][pos++] = input[i];
    }
    output[c][pos] = '\0'; // Add null termination to the last string
    cout << output[1] << endl;  //debug
}

int main()
{
    char** output = new char*[30];
    for (int i = 0; i < 30; i++)
        output[i] = new char[100];  // Allocate memory for each string, assuming a max length of 100 characters

    backword("dfs sdfsdfsd dsffsdf", output);
    cout << output[1] << endl; //dubug
    // Don't forget to free the dynamically allocated memory
    for (int i = 0; i < 30; i++)
        delete[] output[i];
    delete[] output;
    return 0;
}
sdfsdfsd
sdfsdfsd
