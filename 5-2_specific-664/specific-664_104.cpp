void backword(const char* input, char* output[])
{
    int wordIndex = 0;
    int charIndex = 0;

    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == ' ')
        {
            output[wordIndex][charIndex] = '\0'; // Null-terminate the current word
            wordIndex++;
            charIndex = 0;
        }
        else
        {
            output[wordIndex][charIndex] = input[i];
            charIndex++;
        }
    }
    output[wordIndex][charIndex] = '\0'; // Null-terminate the last word
    output[wordIndex + 1] = nullptr; // Null-terminate the array of strings
}
int main()
{
    const char* input = "dfs sdfsdfsd dsffsdf";
    char** output = new char*[30];
    
    for (int i = 0; i < 30; i++)
    {
        output[i] = new char[strlen(input) + 1]; // Allocate memory for each string
    }

    backword(input, output);

    for (int i = 0; output[i] != nullptr; i++)
    {
        cout << output[i] << endl;
    }

    // Free allocated memory
    for (int i = 0; i < 30; i++)
    {
        delete[] output[i];
    }
    delete[] output;

    return 0;
}
