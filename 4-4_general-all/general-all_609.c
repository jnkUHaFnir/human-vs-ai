while(fgets(singleLineContent, 150, fPointer))
{
    char *token = strtok(singleLineContent, ",\n");
    if(token == NULL)
    {
        printf("Error: No tokens found in line\n");
        continue; // Skip processing this line and move to the next one
    }

    fprintf(fPointerForWriting, "%d", atoi(token));
    token = strtok(NULL, ",\n");

    if(token == NULL)
    {
        printf("Error: Incomplete data in line\n");
        continue; // Skip processing this line and move to the next one
    }

    fprintf(fPointerForWriting, ",%d     %d\n", atoi(token), i);
    
    i++;
}
