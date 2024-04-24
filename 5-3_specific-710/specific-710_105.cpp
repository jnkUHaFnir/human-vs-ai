#include <iostream>
#include <cstring>

using namespace std;

void backword(const char* input, char** output) {
    int current_array = 0;
    int current_index = 0;

    for (int i = 0; i <= strlen(input); i++) {
        if (input[i] == ' ' || input[i] == '\0') {
            output[current_array][current_index] = '\0'; // Null-terminate the string in the current array
            current_array++;
            current_index = 0;
        }
        else {
            output[current_array][current_index] = input[i];
            current_index++;
        }
    }
}

int main() {
    const char* input = "dfs sdfsdfsd dsffsdf";
    char** output = new char*[30];
    for (int i = 0; i < 30; i++) {
        output[i] = new char[30]; // Allocate memory for each char array
    }

    backword(input, output);

    cout << output[0] << endl; // Output the first word
    cout << output[1] << endl; // Output the second word

    // Free memory
    for (int i = 0; i < 30; i++) {
        delete[] output[i];
    }
    delete[] output;

    return 0;
}
