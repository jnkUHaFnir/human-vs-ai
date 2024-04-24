char* SequenceTokenAnalizer::NextToken(char delim)
{
    int i = currentindex, i2 = currentindex, cnt = 0, j = 0;
    char *token = NULL;

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

        token = new char[cnt + 1]; // Allocate memory for the token and 1 extra byte for null terminator
        j = 0;

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

        token[j] = '\0'; // Null-terminate the token
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

        token = new char[cnt + 1]; // Allocate memory for the token and 1 extra byte for null terminator
        j = 0;

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

        token[j] = '\0'; // Null-terminate the token
        currentindex = i;
        return token;
    }
}
