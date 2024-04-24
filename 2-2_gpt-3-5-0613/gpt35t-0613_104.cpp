#include <iostream>
#include <cstring>

using namespace std;

void backword(char* input, char* output[])
{
    int numberOfWords = 1;
    for(int i = 0, c = 0; strlen(input)>i; i++)
    {
        if(input[i] == ' ')
        {
            output[c][numberOfWords] = '\0';
            c++;
            numberOfWords = 0;
            i++;
        }
        output[c][numberOfWords] = input[i];
        numberOfWords++;
    }
    output[numberOfWords][numberOfWords] = '\0';
    cout << output[1]; //debug
}

int main()
{
    char** output = new char*[30];
    for(int i = 0; i < 30; i++)
    {
        output[i] = new char[30];
    }
    backword("dfs sdfsdfsd dsffsdf", output);
    cout << output[1]; //debug

    // deallocate memory
    for(int i = 0; i < 30; i++)
    {
        delete [] output[i];
    }
    delete [] output;

    return 0;
}
