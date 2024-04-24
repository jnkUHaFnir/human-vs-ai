#include <iostream>
#include <vector>
#include <string>

void backword(const std::string& input, std::vector<std::string>& output)
{
    std::string currentWord;
    for (char i : input)
    {
        if (i == ' ')
        {
            output.push_back(currentWord);
            currentWord.clear();
        }
        else
        {
            currentWord.push_back(i);
        }
    }
    if (!currentWord.empty())
    {
        output.push_back(currentWord);
    }
}

int main()
{
    std::vector<std::string> output;
    backword("dfs sdfsdfsd dsffsdf", output);
    std::cout << output[1]; // debug
    return 0;
}
