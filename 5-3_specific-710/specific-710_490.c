#include <stdio.h>
#include <stdlib.h>

int new_strlen(char *tab)
{
    int i;
    for (i = 0; tab[i] != '\0'; ++i);
    return i;
}

int copyText(char from[], char to[], int max)
{
    int i;
    if (new_strlen(from) < max) // change to < instead of <=
    {
        for (i = 0; from[i] != '\0' && i < max; i++) // fixed loop condition
        {
            to[i] = from[i];
        }
        to[i] = '\0'; // add null terminator after copying
    }
    return 0;
}

int main(int argc, char *argv[])
{
    char sentence[] = "C is \n a \n programming \t language";
    char sentence2[1000];

    copyText(sentence, sentence2, sizeof(sentence));
    printf("Show my array: %s \n", sentence2);

    return 0;
}
