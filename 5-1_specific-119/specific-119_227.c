#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[100];
    char test[100];
    char er[100];
    char tr[100];

    printf("target: ");
    scanf("%s", name);
    printf("target: ");
    scanf("%s", test);
    printf("target: ");
    scanf("%s", er);
    printf("target: ");
    scanf("%s", tr);

    char command[200];
    snprintf(command, sizeof(command), "ping %s.%s.%s.%s", name, test, er, tr);

    printf("Running command: %s\n", command);

    system(command);

    return 0;
}
