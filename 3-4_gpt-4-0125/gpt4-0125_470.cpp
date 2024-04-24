token = new char[cnt];
token[j] = '\0';
token = new char[cnt + 1];
char* SequenceTokenAnalizer::NextToken(char delim) {
    int cnt = 0;
    // Skip leading delimiters to find the start of the next token.
    while (Sequence[currentindex] == delim && Sequence[currentindex] != '\0') {
        currentindex++;
    }
    
    int start = currentindex; // Remember where the token starts.

    // Count characters until the next delimiter or end of string.
    while (Sequence[currentindex] != delim && Sequence[currentindex] != '\0') {
        cnt++;
        currentindex++;
    }

    // Allocate sufficient memory (+1 for the null terminator).
    char* token = new char[cnt + 1];

    // Copy the token into the newly allocated space.
    for (int j = 0; j < cnt; j++) {
        token[j] = Sequence[start + j];
    }
    token[cnt] = '\0'; // Null-terminate the token.

    return token;
}
