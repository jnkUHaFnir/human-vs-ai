...
// Allocate memory for the token plus the null terminator
token = new char[cnt + 1];
...
// Do not forget to add the null terminator before returning the token
token[j] = '\0';
...
char* SequenceTokenAnalizer::NextToken(char delim) {
    int i = currentindex, cnt = 0;
    char *token = NULL;

    // Skip initial delimiters
    while (Sequence[i] == delim && Sequence[i] != '\0') {
        i++;
    }

    // Count characters up to the next delimiter or end of string
    int start = i;
    while (Sequence[i] != delim && Sequence[i] != '\0') {
        cnt++;
        i++;
    }

    // Allocate memory with space for null terminator
    token = new char[cnt + 1];

    // Copy the characters to the token
    for (int j = 0; j < cnt; j++) {
        token[j] = Sequence[start + j];
    }
    token[cnt] = '\0'; // Null terminator

    // Update the current index to the new position
    currentindex = i;

    return token;
}
