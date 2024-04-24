#include <stdio.h>
int main()
{
     char name[100];
     printf("Your name: \n");
     fgets(name, sizeof(name), stdin);
     printf("Name: %s  \n", name);

    return 0;
}
name[strcspn(name, "\n")] = '\0';
