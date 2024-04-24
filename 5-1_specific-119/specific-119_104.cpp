#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void backword(const char* input, vector<string>& output)
{
    int c = 0;
    output.push_back(""); // Add an empty string to start with
  
    for(int i = 0; i < strlen(input); i++)
    {
        if(input[i] == ' ')
        {
            c++;
            output.push_back(""); // Add a new empty string when encountering a space
        }
        else
        {
            output[c].push_back(input[i]); // Append the character to the current string
        }
    }
}

int main()
{
    vector<string> output;
    backword("dfs sdfsdfsd dsffsdf", output);

    cout << output[1] << endl; // Output the second word
    return 0;
}
