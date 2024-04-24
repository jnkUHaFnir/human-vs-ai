char source[1000000] = {0}; // Initialize all elements to 0
char symbol;
size_t idx = 0;

if(fp != NULL)
{
    while((symbol = getc(fp)) != EOF)
    {
        if(idx < sizeof(source) - 1)  // Ensure we don't overflow
        {
            source[idx++] = symbol;
        }
        else
        {
            // Handle buffer full situation
            break;
        }
    }
    source[idx] = '\0'; // Null-terminate the string
    fclose(fp);
}
for(int x = 0; source[x] != '\0'; x++)
{
    // Process characters
    char c = source[x];
}
