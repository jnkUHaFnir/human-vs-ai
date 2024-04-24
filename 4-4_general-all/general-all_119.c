#include <stdio.h>

struct student {
    char name[50];
    int age;
    int grade;
};

int main()
{
    struct student info[3];
    int i;

    for (i = 0; i < 3; i++) {
        printf("Enter name for student %d: ", i + 1);
        fgets(info[i].name, sizeof(info[i].name), stdin); // Read name with spaces
        printf("Enter age for student %d: ", i + 1);
        scanf("%d", &info[i].age);
        printf("Enter grade for student %d: ", i + 1);
        scanf("%d", &info[i].grade);

        // Consume the newline character left in the input buffer
        getchar();
    }

    return 0;
}
