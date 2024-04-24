#include <stdio.h>
#include <string.h>

void formPlural(char *plural)
{
    int len = strlen(plural);

    // Rule 1: If noun ends in "y", remove the "y" and add "ies"
    if (plural[len-1] == 'y')
    {
        plural[len-1] = '\0';
        strcat(plural, "ies");
    }
    // Rule 2: If noun ends in "s", "ch", or "sh", add "es"
    else if (plural[len-1] == 's' || (plural[len-1] == 'h' && (plural[len-2] == 'c' || plural[len-2] == 's')))
    {
        strcat(plural, "es");
    }
    // Rule 3: In all other cases, just add "s"
    else
    {
        strcat(plural, "s");
    }
}

int main(void)
{
    char nouns[][20] = { "chair", "dairy", "boss", "circus", "fly", "dog", "church", "clue", "dish" };
    int numNouns = sizeof(nouns) / sizeof(nouns[0]);

    for (int i = 0; i < numNouns; i++)
    {
        char plural[20];
        strcpy(plural, nouns[i]);
        formPlural(plural);
        printf("%s --> %s\n", nouns[i], plural);
    }

    return 0;
}
