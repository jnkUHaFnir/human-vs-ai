#include <iostream>
#include <cstring>

using namespace std;

void backword(const char* input, char** output)
{
    int c = 0;
    char* token = strtok(const_cast<char*>(input), " ");
    
    // Tokenize the input string
    while (token != nullptr) {
        output[c] = new char[strlen(token) + 1]; // Allocate memory for each word
        strcpy(output[c], token); // Copy the tokenized word to the output array
        token = strtok(nullptr, " ");
        c++;
    }
}

int main()
{
    char* input = "dfs sdfsdfsd dsffsdf";
    char** output = new char*[30];
    
    backword(input, output);
    
    // Print the tokenized words
    for (int i = 0; output[i] != nullptr; i++) {
        cout << output[i] << " ";
    }
    
    // Free the memory allocated for each word
    for (int i = 0; output[i] != nullptr; i++) {
        delete[] output[i];
    }
    
    // Free the memory allocated for the output array
    delete[] output;
    
    return 0;
}
