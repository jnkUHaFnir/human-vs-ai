char* SequenceTokenAnalizer::NextToken(char delim)
{
    int i = currentindex, i2 = currentindex, cnt = 0, j = 0;
    char *token = nullptr;

    // Code to calculate cnt and allocate memory for token

    token = new char[cnt + 1];  // Allocate memory including space for null terminator

    // Code to copy characters into token with appropriate bounds checking

    // Make sure to null-terminate the token
    token[j] = '\0';

    currentindex = i;
    return token;
}
