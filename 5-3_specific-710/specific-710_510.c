buffer[length] = '\0';
length -= 1;
while (length >= 0)
{
    printf("%c", buffer[length]);
    length--;
}
printf("\n");

free(buffer);
// free(temporary); // no need to free temporary here

return 0;
``` 

By making this adjustment, you avoid the double free error by only freeing the memory that was originally allocated with `malloc` which is pointed to by `buffer`.
