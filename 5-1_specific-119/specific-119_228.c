#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[16]; // assuming IPv4 address, so max 15 characters plus null terminator
    char test[16];
    char er[16];
    char tr[16];

    printf("Enter the target IP address:\n");
    scanf("%15s.%15s.%15s.%15s", name, test, er, tr);

    char command[64]; // assuming max size of command
    snprintf(command, sizeof(command), "ping %s.%s.%s.%s", name, test, er, tr);

    printf("Executing command: %s\n", command);
    system(command);

    return 0;
}
