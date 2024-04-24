#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 80;

class SequenceTokenAnalizer {
    char Sequence[SIZE];
    char delimiter;
    int currentindex;

public:
    SequenceTokenAnalizer(char str[]);
    SequenceTokenAnalizer(char str[], char delim);
    int LengthSequence();
    int CountAllTokens();
    void ResetTokens();
    int CountTokens();
    bool HasMoreTokens();
    bool HasMoreTokens(char delim);
    char* NextToken();
    char* NextToken(char delim);
    bool Equals(SequenceTokenAnalizer other);
    bool NotEquals(SequenceTokenAnalizer other);
    bool isCommonToken(SequenceTokenAnalizer other);
    void PrintCommonTokens(SequenceTokenAnalizer other);
};

SequenceTokenAnalizer::SequenceTokenAnalizer(char str[]) {
    strncpy(Sequence, str, SIZE);
    currentindex = 0;
}

SequenceTokenAnalizer::SequenceTokenAnalizer(char str[], char delim) {
    strncpy(Sequence, str, SIZE);
    currentindex = 0;
    delimiter = delim;
}

int SequenceTokenAnalizer::LengthSequence() {
    return strlen(Sequence);
}

int SequenceTokenAnalizer::CountAllTokens() {
    int count = 0;
    int len = LengthSequence();
    for (int i = 0; i < len; i++) {
        if (Sequence[i] != delimiter) {
            count++;
            while (i < len && Sequence[i] != delimiter) {
                i++;
            }
        }
    }
    return count;
}

void SequenceTokenAnalizer::ResetTokens() {
    currentindex = 0;
}

int SequenceTokenAnalizer::CountTokens() {
    int count = 0;
    int len = LengthSequence();
    int index = currentindex;
    while (index < len) {
        if (Sequence[index] != delimiter) {
            count++;
            while (index < len && Sequence[index] != delimiter) {
                index++;
            }
        }
        index++;
    }
    return count;
}

bool SequenceTokenAnalizer::HasMoreTokens() {
    int len = LengthSequence();
    if (currentindex >= len) {
        return false;
    }
    return true;
}

bool SequenceTokenAnalizer::HasMoreTokens(char delim) {
    int len = LengthSequence();
    int index = currentindex;
    while (index < len) {
        if (Sequence[index] != delim) {
            return true;
        }
        index++;
    }
    return false;
}

char* SequenceTokenAnalizer::NextToken() {
    int len = LengthSequence();
    int start = currentindex;
    int end = start;
    while (end < len && Sequence[end] != delimiter) {
        end++;
    }
    int tokenLen = end - start;
    char* token = new char[tokenLen + 1];
    strncpy(token, Sequence + start, tokenLen);
    token[tokenLen] = '\0';
    currentindex = end + 1;
    return token;
}

char* SequenceTokenAnalizer::NextToken(char delim) {
    int len = LengthSequence();
    int start = currentindex;
    int end = start;
    while (end < len && Sequence[end] != delim) {
        end++;
    }
    int tokenLen = end - start;
    char* token = new char[tokenLen + 1];
    strncpy(token, Sequence + start, tokenLen);
    token[tokenLen] = '\0';
    currentindex = end + 1;
    return token;
}

bool SequenceTokenAnalizer::Equals(SequenceTokenAnalizer other) {
    return strcmp(Sequence, other.Sequence) == 0;
}

bool SequenceTokenAnalizer::NotEquals(SequenceTokenAnalizer other) {
    return strcmp(Sequence, other.Sequence) != 0;
}

bool SequenceTokenAnalizer::isCommonToken(SequenceTokenAnalizer other) {
    int len = LengthSequence();
    if (len != other.LengthSequence()) {
        return false;
    }
    for (int i = 0; i < len; i++) {
        if (Sequence[i] != other.Sequence[i]) {
            return false;
        }
    }
    return true;
}

void SequenceTokenAnalizer::PrintCommonTokens(SequenceTokenAnalizer other) {
    int len = LengthSequence();
    if (len != other.LengthSequence()) {
        cout << "Sequences are not of equal length." << endl;
        return;
    }
    for (int i = 0; i < len; i++) {
        if (Sequence[i] == other.Sequence[i]) {
            cout << NextToken() << endl;
        }
    }
}

int main() {
    SequenceTokenAnalizer st1("This is a test");
    char* helpSequence;
    helpSequence = st1.NextToken();
    cout << helpSequence << endl;
    delete[]  helpSequence;

    return 0;
}
