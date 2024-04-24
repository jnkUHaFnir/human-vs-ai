char* SequenceTokenAnalizer::NextToken(char delim) {
    int i = currentindex, i2 = currentindex, cnt = 0, j = 0;
    char *token = NULL;

    // Handle case when reaching end of Sequence
    if (Sequence[currentindex] == '\0') {
        return NULL;
    }

    while (Sequence[i2] == delim && Sequence[i2] != '\0') {
        i2++;
    }

    while (Sequence[i2] != delim && Sequence[i2] != '\0') {
        cnt++;
        i2++;
    }

    token = new char[cnt + 1]; // Allocate memory for token including space for null terminator

    // Copy token characters
    for (int k = 0; k < cnt; k++) {
        token[k] = Sequence[i];
        i++;
    }
    token[cnt] = '\0'; // Add null terminator to the end of the token

    currentindex = i; // Update currentindex for next call
    return token;
}
