char* SequenceTokenAnalizer::NextToken(char delim)
{
    int i = currentindex, i2 = currentindex, cnt = 0, j = 0;
    char* token = NULL;

    if (Sequence[i2] == delim)
    {
        while (Sequence[i2] == delim && Sequence[i2] != '\0')
        {
            i2++;
        }

        while (Sequence[i2] != delim && Sequence[i2] != '\0')
        {
            cnt++;
            i2++;
        }

        token = new char[cnt + 1]; // Allocate memory for token and include space for null terminator

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
    }
    else
    {
        while (Sequence[i2] != delim && Sequence[i2] != '\0')
        {
            cnt++;
            i2++;
        }

        token = new char[cnt + 1]; // Allocate memory for token and include space for null terminator

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
    }

    // If execution reaches here, it means token was not created or not returned, so clean up and return NULL
    delete[] token; // Deallocate memory
    return NULL;
}
