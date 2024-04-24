#include <stdio.h>
#include <string.h>

int main()
{
     char name[100];
     printf("Your name: \n");
     fgets(name, 100, stdin);
     name[strcspn(name, "\n")] = 0; // remove the newline character
     printf("Name: %s  \n", name);

    return 0;
}
