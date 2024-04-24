#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct info
{
    int age;
    char name[30];
};

int main()
{
    struct info *Ptr;
    int i = 0; // 'i' will be the current index where data is entered 
    char input[20]; 

    // Start by allocating space for 1 structure
    Ptr = (struct info*)malloc(sizeof(struct info));

    do {
        printf("Enter name and age:\n");
        scanf("%s %d", (Ptr+i)->name, &(Ptr+i)->age);
        
        printf("Do you want to add another person? (Y/N):\n");
        scanf("%s", input);
        
        i++;
        if (strcmp(input,"Y") == 0 || strcmp(input,"y") == 0) {
            Ptr = (struct info*)realloc(Ptr, (i + 1) * sizeof(struct info));
        }
    } while (strcmp(input,"Y") == 0 || strcmp(input,"y") == 0);

    for(int j = 0; j < i ; ++j) {
        printf("Name = %s, Age = %d\n", (Ptr+j)->name, (Ptr+j)->age);
    }

    free(Ptr);

    return 0;
}
