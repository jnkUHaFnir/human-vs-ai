username[i] = calloc(SIZE, sizeof(char)); 
for(i = 0; i < 100; i++)
{
    username[i] = calloc(SIZE, sizeof(char)); 
    if(fgets(username[i], SIZE, stdin) == NULL)
    {
        break;
    }
}
