char* SequenceTokenAnalizer::NextToken(char delim)
{
    int i = currentindex, i2 = currentindex, cnt = 0, j = 0;
    char *token = NULL;

    // Calculate the length of the token
    while (Sequence[i2] == delim && Sequence[i2] != '\0')
    {
        i2++;
    }
    while (Sequence[i2] != delim && Sequence[i2] != '\0')
    {
        cnt++;
        i2++;
    }

    token = new char[cnt + 1]; // Allocate memory for the token string and null terminator

    if (Sequence[i] == delim)
    {
        while (Sequence[i] == delim)
        {
            i++;
        }
        while (Sequence[i] != delim && Sequence[i] != '\0')
        {
            token[j] = Sequence[i];
            i++;
            j++;
        }
        token[j] = '\0';
        currentindex = i;
        return token;
    }
    else
    {
        while (Sequence[i2] != delim)
        {
            cnt++;
            i2++;
        }

        delete[] token; // Free the insufficiently allocated memory
        token = new char[cnt + 1]; // Reallocate memory for the token string and null terminator

        if (Sequence[i] == delim)
        {
            while (Sequence[i] == delim)
            {
                i++;
            }
            while (Sequence[i] != delim && Sequence[i] != '\0')
            {
                token[j] = Sequence[i];
                i++;
                j++;
            }
            token[j] = '\0';
            currentindex = i;
            return token;
        }
        else
        {
            while (Sequence[i] != delim)
            {
                token[j] = Sequence[i];
                i++;
                j++;
            }
            token[j] = '\0';
            currentindex = i;
            return token;
        }
    }
}
