char *s1, *st7;
int i, j;
char arr[10][10], temp[50];

// Populate arr with some strings
strcpy(arr[0], "world");
strcpy(arr[1], "hello");
strcpy(arr[2], "programming");
strcpy(arr[3], "language");

s1 = strtok(str1, ";");
do
{
    st7 = strstr(s1, "s__");
    if (st7 != NULL)
    {
        for (i = 0; i < 10; ++i)
        {
            for (j = i + 1; st7[i + j] != '\0'; ++j)
            {
                if (strcmp(arr[st7[i]], arr[st7[j]]) > 0)
                {
                    strcpy(temp, arr[st7[i]]);
                    strcpy(arr[st7[i]], arr[st7[j]]);
                    strcpy(arr[st7[j]], temp);
                }
            }
        }
        for (i = 0; i < 10; ++i)
        {
            if (strstr(s1, arr[i]) != NULL)
            {
                printf("%s\n", arr[i]);
                break;
            }
        } 
    }           
} while (s1 = strtok(NULL, ";"));
