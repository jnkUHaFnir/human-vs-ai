#include <iostream>
#include <cstring>

const int SIZE = 80;

class SequenceTokenAnalizer {
private:
    char Sequence[SIZE];
    int currentindex;

public:
    SequenceTokenAnalizer(const char str[]) {
        strcpy(Sequence, str);
        currentindex = 0;
    }

    char* NextToken(char delim = ' ') {
        int i = currentindex, i2 = currentindex, cnt = 0, j = 0;
        char *token = nullptr;

        while (Sequence[i2] == delim && Sequence[i2] != '\0') {
            i2++;
        }

        while (Sequence[i2] != delim && Sequence[i2] != '\0') {
            cnt++;
            i2++;
        }

        if (cnt > 0) {
            token = new char[cnt + 1]; // Allocate extra byte for the null terminator
            j = 0;

            while (Sequence[i] != delim && Sequence[i] != '\0') {
                token[j] = Sequence[i];
                i++;
                j++;
            }
            token[j] = '\0';
            currentindex = i;
        }

        return token;
    }
};

int main() {
    SequenceTokenAnalizer st1("This is a test");
    char* helpSequence;
    
    helpSequence = st1.NextToken(); // Assuming default delimiter is space
    std::cout << helpSequence << std::endl;

    delete[] helpSequence;
    
    return 0;
}
