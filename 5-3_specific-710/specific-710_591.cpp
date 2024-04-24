// Make sure to include necessary headers
#include <iostream>
#include <cstring>
#include <cstdlib>

class SequenceTokenAnalizer {
    const static int MAX_TOKEN_SIZE = 100; // Define a maximum token size to prevent buffer overflow
    char Sequence[SIZE];
    char delimiter;
    int currentindex;

public:
    SequenceTokenAnalizer(char str[]) {
        strncpy(Sequence, str, sizeof(Sequence)); // Copy input string to Sequence
        currentindex = 0;
    }

    char* NextToken(char delim = ' ') {
        int i = currentindex;
        int cnt = 0;

        // Find the length of the token
        while (Sequence[i] != delim && Sequence[i] != '\0') {
            cnt++;
            i++;
        }

        // Allocate memory for the token (including space for the null terminator)
        char* token = new char[cnt + 1];
        if (token == NULL) {
            // Handle memory allocation failure
            return NULL;
        }

        // Populate the token
        for (int j = 0; j < cnt; j++) {
            token[j] = Sequence[currentindex + j];
        }
        token[cnt] = '\0'; // Null terminate the token

        // Update currentindex for the next call
        currentindex += cnt;
        if (Sequence[currentindex] == delim) {
            currentindex++; // Skip the delimiter
        }

        return token;
    }

    // Other member functions...
};

int main() {
    SequenceTokenAnalizer st1("This is a test");
    char* helpSequence = st1.NextToken();
    if (helpSequence != NULL) {
        std::cout << helpSequence << std::endl;
        delete[] helpSequence;
    } else {
        std::cerr << "Failed to allocate memory for the token." << std::endl;
    }

    return 0;
}
