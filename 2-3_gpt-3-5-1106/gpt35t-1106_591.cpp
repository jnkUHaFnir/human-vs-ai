char* SequenceTokenAnalizer::NextToken(char delim)
{
    int i = currentindex, cnt = 0, j = 0;
    char* token = nullptr;

    while (Sequence[i] == delim && Sequence[i] != '\0')
    {
        i++;
    }

    while (Sequence[i] != delim && Sequence[i] != '\0')
    {
        cnt++;
        i++;
    }

    if (cnt > 0)
    {
        token = new char[cnt + 1];  // Allocate memory for token (don't forget space for null terminator)

        for (int k = 0; k < cnt; k++)
        {
            token[k] = Sequence[currentindex + k];
        }
        token[cnt] = '\0';  // Add null terminator

        currentindex += cnt;  // Update currentindex

        return token;
    }
    else
    {
        return nullptr;  // No token found, return nullptr
    }
}
