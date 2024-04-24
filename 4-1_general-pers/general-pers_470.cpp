char* SequenceTokenAnalizer::NextToken(char delim)
{
    int i = currentindex, i2 = currentindex, cnt = 0, j = 0;
    char *token = nullptr;

    // Find the start of the next token
    while (Sequence[i2] == delim && Sequence[i2] != '\0') {
        i2++;
    }

    // Calculate the length of the next token
    while (Sequence[i2] != delim && Sequence[i2] != '\0') {
        cnt++;
        i2++;
    }

    // Allocate memory for the token and copy the token if found
    if (cnt > 0) {
        token = new char[cnt + 1];  // +1 for null terminator

        for (int k = 0; k < cnt; k++) {
            token[k] = Sequence[i];
            i++;
        }
        token[cnt] = '\0'; // Null-terminate the token
        currentindex = i; // Update the current index
    }

    return token;
}
