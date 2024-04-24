for (int i = 0; i < numLen; i++)
{
    reverse[i] = input[numLen - 1 - i];
}

reverse[numLen] = '\0'; // Add null terminator after reversing the string
