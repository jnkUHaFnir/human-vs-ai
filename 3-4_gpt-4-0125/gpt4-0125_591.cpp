token = new char[cnt + 1];  // Allocate one more for the null terminator
char* SequenceTokenAnalizer::NextToken(char delim) {
    int j = 0;
    // Skip leading delimiters
    while (Sequence[currentindex] == delim && Sequence[currentindex] != '\0') {
        currentindex++;
    }

    int startIndex = currentindex; // Start of token
    // Count the length of the token
    while (Sequence[currentindex] != delim && Sequence[currentindex] != '\0') {
        currentindex++;
    }

    int tokenLength = currentindex - startIndex;
    char* token = new char[tokenLength + 1]; // +1 for the null terminator

    // Copy the token
    for (int i = 0; i < tokenLength; i++) {
        token[i] = Sequence[startIndex + i];
    }
    token[tokenLength] = '\0'; // Set the null terminator

    return token;
}
