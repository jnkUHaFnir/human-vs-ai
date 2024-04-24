for (int i = 0; i < numLen; i++)
{
    reverse[i] = input[numLen - 1 - i];

    if (i == numLen - 1)
    {
        reverse[i + 1] = '\0'; // Null-terminate the reverse string
    }
}
