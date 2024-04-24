#include <iostream>
#include <cstring>

char* SequenceTokenAnalizer::NextToken(char delim)
{
    int i = currentindex, i2 = currentindex, cnt = 0, j = 0;
    char *token = nullptr;

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

        token = new char[cnt + 1]; // Add 1 for null terminator
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
        token = new char[cnt + 1]; // Add 1 for null terminator

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

    delete[] token; // Free the memory in case of any failure
    return nullptr;
}
