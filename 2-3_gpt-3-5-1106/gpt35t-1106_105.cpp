void backword(const char* input, char* output[])
{
    int c = 0;
    output[c] = new char[strlen(input)+1]; //allocate memory for the first word
    for(int i = 0; i<strlen(input); i++)
    {
        if(input[i] == ' ')
        {
            output[c][i] = '\0'; //add null terminator to the end of the word
            c++;
            output[c] = new char[strlen(input)-i]; //allocate memory for the next word
        }
        else
        {
            output[c][i] = input[i]; //add character to the current word
        }
    }
    output[c][strlen(input)] = '\0'; //add null terminator to the end of the last word
}

int main()
{
    const char* input = "dfs sdfsdfsd dsffsdf";
    char* output[3]; //allocate memory for 3 words
    backword(input, output);
    cout << output[1]; //print the second word
    return 0;
}
