#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Please enter a line: ");
    read = getline(&line, &len, stdin);

    if (read != -1) {
        printf("Input: %s\n", line);
    }

    free(line);

    return 0;
}
