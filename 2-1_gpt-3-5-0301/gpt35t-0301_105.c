for(int i = 0; i < 30; i++) {
    output[i] = new char[100]; // allocate memory for each element
}
int len = strlen(input);
for(int i = 0, c = 0; i < len; i++)
if(input[i] == ' ') {
    c++;
    continue;
}
for(int i = 0; i < 30; i++) {
    cout << output[i] << endl;
}
#include <iostream>
#include <cstring>

using namespace std;

void backword(char* input, char* output[])
{
    for(int i = 0, c = 0, len = strlen(input); i < len; i++)
    {
        if(input[i] == ' ') {
            c++;
            continue;
        }
        output[c] += input[i];
    }
}

int main()
{
    char** output = new char*[30];
    for(int i = 0; i < 30; i++) {
        output[i] = new char[100];
    }
    backword("dfs sdfsdfsd dsffsdf", output);
    for(int i = 0; i < 30; i++) {
        cout << output[i] << endl;
    }
    return 0;
}
