#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    printf("Your name: \n");
    fgets(name, sizeof(name), stdin);

    // Remove the newline character if it exists
    name[strcspn(name, "\n")] = 0;

    printf("Name: %s  \n", name);

    return 0;
}
