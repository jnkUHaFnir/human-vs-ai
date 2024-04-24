#include <iostream>
#include <cstring>

using namespace std;

void backword(const char* input, char* output[], int size)
{
    char* token = strtok(const_cast<char*>(input), " ");
    int i = 0;

    while (token != nullptr && i < size) {
        output[i] = token;
        token = strtok(nullptr, " ");
        i++;
    }
}

int main()
{
    const int size = 30;
    char* output[size] = {nullptr}; // Initialize all elements to nullptr

    backword("dfs sdfsdfsd dsffsdf", output, size);

    for (int i = 0; i < size; i++) {
        if (output[i] != nullptr) {
            cout << output[i] << " ";
        }
    }

    return 0;
}
