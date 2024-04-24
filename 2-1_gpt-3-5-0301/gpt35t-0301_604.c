#include <string.h>
#include <stdlib.h>

// helper function to convert a substring to a null-terminated string
char* substring_to_string(const char* str, size_t start, size_t end)
{
    char* sub = malloc(end - start + 1);
    if (sub)
    {
        memcpy(sub, str + start, end - start);
        sub[end - start] = '\0';
    }
    return sub;
}

// function to replace all occurrences of a substring with a new string
char* replace_substring(const char* str, const char* sub, const char* new_sub)
{
    size_t sub_len = strlen(sub);
    size_t new_sub_len = strlen(new_sub);
    size_t count = 0;

    // count the number of occurrences of the substring
    const char* pos = str;
    while ((pos = strstr(pos, sub)))
    {
        count++;
        pos += sub_len;
    }

    // allocate memory for the new string
    size_t len = strlen(str) + count * (new_sub_len - sub_len) + 1;
    char* new_str = malloc(len);
    if (!new_str)
        return NULL;

    // replace all occurrences of the substring
    pos = str;
    char* dest = new_str;
    while (1)
    {
        const char* next = strstr(pos, sub);
        if (!next)
        {
            strcpy(dest, pos);
            break;
        }

        size_t diff = next - pos;
        strncpy(dest, pos, diff);
        dest += diff;

        strncpy(dest, new_sub, new_sub_len);
        dest += new_sub_len;

        pos = next + sub_len;
    }

    return new_str;
}
char* str = "Hello world, hello";
char* sub = "hello";
char* new_sub = "hi";

char* new_str = replace_substring(str, sub, new_sub);
if (new_str)
{
    printf("%s\n", new_str);
    free(new_str);
}
Hello world, hi
