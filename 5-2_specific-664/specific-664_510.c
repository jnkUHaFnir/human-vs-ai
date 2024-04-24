buffer[length] = '\0';
length -= 1;
while (length >= 0)
{
    printf("%c", buffer[length]);
    length--;
}
printf("\n");

free(buffer);
``` 

By making this change, your code should no longer encounter a double free error.
