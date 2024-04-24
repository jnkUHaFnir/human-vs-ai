char *buffer, *splitString;
const char delim[]=" \n\r";

buffer = malloc(5000*sizeof(char));
if(buffer)
{
    // your existing code

    free(buffer); // Free only the buffer allocated with malloc
}

// No need to free splitString here
