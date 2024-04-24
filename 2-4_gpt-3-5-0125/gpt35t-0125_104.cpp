void backword(char* input, char* output[])
{
    int c = 0;
    for(int i = 0; i < strlen(input); i++)
    {
        if(input[i] == ' ')
        {
            c++;
        }
        else
        {
            output[c] = new char[strlen(output[c]) + 2];
            output[c][strlen(output[c])] = input[i];
            output[c][strlen(output[c]) + 1] = '\0';
        }
        
    }

    cout << output[1]; //debug
}
