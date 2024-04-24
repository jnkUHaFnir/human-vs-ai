char *singleLineContent = NULL;
size_t len = 0;
ssize_t read;

while ((read = getline(&singleLineContent, &len, fPointer)) != -1)
{
    /* data handling */
}

// Don't forget to free the allocated memory after its use
free(singleLineContent);
