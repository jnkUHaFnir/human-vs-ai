char* getString()
{
    char buffer;
    int size = 0;
    int capacity = 1;

    char* inputString = (char*)malloc(capacity*sizeof(char));

    while(1)
    {
        buffer = getchar();
        if(buffer == '\n')
            break;
        if(size >= capacity-1)
        {
            capacity *= 2;
            inputString = (char*)realloc(inputString, capacity*sizeof(char));
        }
        inputString[size] = buffer;
        size++;
    }
    inputString[size] = '\0';
    return inputString;
}
