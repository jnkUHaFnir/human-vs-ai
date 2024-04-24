char* SequenceTokenAnalizer::NextToken(char delim)
{
    int i = currentindex, i2 = currentindex, cnt = 0, j = 0;
    char *token = nullptr;

    if (Sequence[i2] == delim) { // Handle delimiter at the current index
        while (Sequence[i2] == delim && Sequence[i2] != '\0') {
            i2++;
        }

        while (Sequence[i2] != delim && Sequence[i2] != '\0') {
            cnt++;
            i2++;
        }

        token = new char[cnt + 1]; // Include space for the null terminator
        j = 0;

        while (Sequence[i] != delim && Sequence[i] != '\0') {
            token[j++] = Sequence[i++];
        }
        token[j] = '\0';
        currentindex = i;
    } else if (Sequence[i] != '\0') { // Handle non-delimiter token
        while (Sequence[i] != delim && Sequence[i] != '\0') {
            cnt++;
            i++;
        }

        token = new char[cnt + 1]; // Include space for the null terminator
        j = 0;

        while (Sequence[currentindex] != delim && Sequence[currentindex] != '\0') {
            token[j++] = Sequence[currentindex++];
        }
        token[j] = '\0';
    }

    return token;
}
