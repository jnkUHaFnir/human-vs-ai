#include <stdio.h>

int my_strcmp(char s1[], char s2[])
{   
    int i = 0;
    while (s1[i] != '\0')
    {
        if (s2[i] == '\0') {
            return 1;
        }
        else if (s1[i] < s2[i]) {
            return -1;
        }
        else if (s1[i] > s2[i]) {
            return 1;
        }
        i++;
    }

    // If we reach this point, it means all characters are equal up to the length of s1
    if (s2[i] != '\0') {
        return -1; // s2 is longer than s1
    }

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: %s string1 string2\n", argv[0]);
        return 1;
    }

    int result = my_strcmp(argv[1], argv[2]);

    printf("Value: %d\n", result);

    return 0;
}
