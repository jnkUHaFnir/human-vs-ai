#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> backword(const char* input) {
    istringstream iss(input);
    vector<string> words;
    string word;

    while (iss >> word) {
        words.push_back(word);
    }

    return words;
}

int main() {
    auto words = backword("dfs sdfsdfsd dsffsdf");

    for (const auto& word : words) {
        cout << word << endl; // debug: print out each word
    }

    return 0;
}
int main() {
    char** output = new char*[30];
    for (int i = 0; i < 30; ++i) {
        output[i] = new char[256]; // assuming a max word length of 255 chars + null terminator
        output[i][0] = '\0'; // initialize empty string
    }

    // ... rest of code ...

    for (int i = 0; i < 30; ++i) {
        delete[] output[i]; // deallocate word memory
    }
    delete[] output; // deallocate array of pointers
    return 0;
}
