#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[1000];
    int char_seen[256] = {0}; // Assuming ASCII characters

    printf("Enter a string: ");
    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++)
    {
        if (char_seen[str[i]]) // Check if the character has been seen before
        {
            printf("First repeated character: %c\n", str[i]);
            break; // Exit the loop once the first repeated character is found
        }
        else
        {
            char_seen[str[i]] = 1; // Mark the character as seen
        }
    }

    return 0;
}
