free(buffer);

splitString = strtok(buffer, delim);
while(splitString != NULL)
{
    jj++;
    splitString = strtok(NULL, delim);
}
free(splitString); // Free the splitString after the while loop
