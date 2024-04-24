#include <iostream>
#include <vector>
#include <string>

using namespace std;

void backword(const string& input, vector<string>& output)
{
    string current;
    for(char c : input)
    {
        if(c == ' ')
        {
            output.push_back(current);
            current.clear();
        }
        else
        {
            current += c;
        }
    }
    output.push_back(current); // Add the last word
}

int main()
{
    vector<string> output;
    backword("dfs sdfsdfsd dsffsdf", output);

    // Print the words
    for(const string& word : output)
    {
        cout << word << endl;
    }

    return 0;
}
