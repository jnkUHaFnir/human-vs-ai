#include <iostream>
#include <cstring>

using namespace std;

void backword(const char* input, char* output[])
{
    int i = 0;
    int c = 0;
    
    while(input[i] != '\0')
    {
        if(input[i] == ' ')
        {
            output[c] = new char[i + 1];
            strncpy(output[c], input, i);
            output[c][i] = '\0';
            c++;
            input += i + 1;
            i = 0;
        }
        else
        {
            i++;
        }
    }
    
    // Handle the last word
    if(i > 0)
    {
        output[c] = new char[i + 1];
        strncpy(output[c], input, i);
        output[c][i] = '\0';
    }
}

int main()
{
    const char* input = "dfs sdfsdfsd dsffsdf";
    char* output[30] = { nullptr }; // Initialize to nullptr
    
    backword(input, output);
    
    // Output the words
    for(int i = 0; output[i] != nullptr; i++)
    {
        cout << output[i] << endl;
        delete[] output[i]; // Free the memory allocated for each word
    }
    
    return 0;
}
