#include <iostream>
#include <cstring>

using namespace std;

void backword(char* input, char* output[])
{
    for(int i = 0, c = 0; strlen(input) > i; i++)
    {
        if(input[i] == ' ')
        {
            c++;
        }
        else
        {
            if(output[c] == nullptr)
            {
                output[c] = new char[strlen(input) + 1];
                strcpy(output[c], "");
            }
            size_t len = strlen(output[c]);
            output[c][len] = input[i];
            output[c][len + 1] = '\0';
        }
    }
    cout << output[1]; //debug
}

int main()
{
    char* output[30] = { nullptr };
    backword("dfs sdfsdfsd dsffsdf", output);
    cout << output[1]; //debug

    for(int i = 0; i < 30; i++)
    {
        if(output[i] != nullptr)
        {
            delete[] output[i];
        }
    }

    return 0;
}
