#include <iostream>
#include <cstring>

using namespace std;

void backword(const char* input, char* output[])
{
    int c = 0;
    char* str = strtok(const_cast<char*>(input), " ");
    while(str != NULL)
    {
        output[c] = new char[strlen(str) + 1];
        strcpy(output[c], str);
        c++;
        str = strtok(NULL, " ");
    }
}

int main()
{
    char* output[30]; // Array to store individual words
    backword("dfs sdfsdfsd dsffsdf", output);

    cout << output[1] << endl; // Output the second word

    // Cleanup allocated memory
    for(int i = 0; i < 30; i++)
    {
        delete[] output[i];
    }

    return 0;
}
