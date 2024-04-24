// Sorting the strings lexicographically
for (i = 0; i < 10; ++i)
{
    for (j = i + 1; j < 10; ++j)
    {
        if (strcmp(arr[st7[i]], arr[st7[j]]) > 0)
        {
            strcpy(temp, arr[st7[i]]);
            strcpy(arr[st7[i]], arr[st7[j]]);
            strcpy(arr[st7[j]], temp);
        }
    }
}
for(i = 0; i < 10; i++) {
    printf("%s\n", arr[st7[i]]);
}
