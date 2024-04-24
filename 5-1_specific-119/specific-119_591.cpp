char* SequenceTokenAnalizer::NextToken(char delim)
{
    int i = currentindex, i2 = currentindex, cnt = 0, j = 0;
    char* token = nullptr;

    if (Sequence[i2] == delim)
    {
        // Skip delimiter characters
        while (Sequence[i2] == delim && Sequence[i2] != '\0')
        {
            i2++;
        }

        // Count the characters until the next delimiter
        while (Sequence[i2] != delim && Sequence[i2] != '\0')
        {
            cnt++;
            i2++;
        }

        // Allocate memory for the token
        token = new char[cnt + 1]; // Include space for null-terminator

        if (Sequence[i] == delim)
        {
            // Skip delimiter characters
            while (Sequence[i] == delim)
            {
                i++;
            }

            // Copy characters until the next delimiter
            while (Sequence[i] != delim && Sequence[i] != '\0')
            {
                token[j] = Sequence[i];
                i++;
                j++;
            }

            token[j] = '\0'; // Null-terminate the token
            currentindex = i;
        }
    }
    else
    {
        // Count the characters until the next delimiter
        while (Sequence[i2] != delim)
        {
            cnt++;
            i2++;
        }

        // Allocate memory for the token
        token = new char[cnt + 1]; // Include space for null-terminator

        if (Sequence[i] == delim)
        {
            // Skip delimiter characters
            while (Sequence[i] == delim)
            {
                i++;
            }

            // Copy characters until the next delimiter
            while (Sequence[i] != delim && Sequence[i] != '\0')
            {
                token[j] = Sequence[i];
                i++;
                j++;
            }

            token[j] = '\0'; // Null-terminate the token
            currentindex = i;
        }
        else
        {
            // Copy characters until the next delimiter
            while (Sequence[i] != delim && Sequence[i] != '\0')
            {
                token[j] = Sequence[i];
                i++;
                j++;
            }

            token[j] = '\0'; // Null-terminate the token
            currentindex = i;
        }
    }
    return token;
}
