char *s1, *st1, *st7;
int i, j;
char arr[10][10], temp[10];

s1 = strtok(str1, ";");
do
{
    st7 = strstr(s1, "s__");
    if (st7 != NULL)
    {
        for (i = 0; i < 10; ++i)
        {
            for (j = i + 1; j < 10; ++j)
            {
                if (strcmp(arr[i], arr[j]) > 0)
                {
                    strcpy(temp, arr[i]);
                    strcpy(arr[i], arr[j]);
                    strcpy(arr[j], temp);
                }
            }
        }
        for (i = 0; i < 10; i++)
        {
            printf("%s\n", arr[i]);
        }
    }
} while (s1 = strtok(NULL, ";"));
