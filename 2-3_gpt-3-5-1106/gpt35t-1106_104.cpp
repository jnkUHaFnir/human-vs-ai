#include <iostream>
#include <cstring>

using namespace std;

void backword(const char* input, char* output[])
{
    char* token = strtok(input, " ");
    int i = 0;
    while (token != NULL)
    {
        output[i] = new char[strlen(token) + 1];
        strcpy(output[i], token);
        token = strtok(NULL, " ");
        i++;
    }
}

int main()
{
    char* output[30];
    backword("dfs sdfsdfsd dsffsdf", output);
    cout << output[1]; //debug
    return 0;
}
