#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 10; // number of strings
    int len = 50; // length of each string

    // create array of strings
    char **str = (char **)malloc(n * sizeof(char*));

    // allocate memory for each string
    for(int i = 0; i < n; i++) {
        str[i] = (char *)malloc(len * sizeof(char));
    }

    // don't forget to free memory after usage
    for(int i = 0; i < n; i++) {
        free(str[i]);
    }
    free(str);

    return 0;
}
