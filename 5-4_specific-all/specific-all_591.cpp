char* SequenceTokenAnalizer::NextToken(char delim)
{
    int i = currentindex;
    int cnt = 0;
    int j = 0;
    char* token = nullptr;

    // Find the start of the next token
    while (Sequence[i] == delim && Sequence[i] != '\0')
    {
        i++;
    }

    // Calculate the length of the token
    while (Sequence[i + cnt] != delim && Sequence[i + cnt] != '\0')
    {
        cnt++;
    }

    if (cnt > 0)
    {
        token = new char[cnt + 1]; // Allocate memory for the token and the null terminator

        // Copy the token characters
        for (int k = 0; k < cnt; k++)
        {
            token[k] = Sequence[i + k];
        }
        token[cnt] = '\0'; // Add null terminator

        currentindex = i + cnt; // Update the current index

        return token;
    }

    return nullptr; // Return nullptr if no token found
}
