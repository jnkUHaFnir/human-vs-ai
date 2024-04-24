#include <stdio.h>

struct student {
    char name[50];
    int age;
    int grade;
};

int main() {
    struct student info[3];
    int i;

    for (i = 0; i < 3; i++) {
        printf("Enter name for student %d: ", i+1);
        fgets(info[i].name, sizeof(info[i].name), stdin);  // fgets for reading the name
        printf("Enter age for student %d: ", i+1);
        scanf("%d", &info[i].age);
        printf("Enter grade for student %d: ", i+1);
        scanf("%d", &info[i].grade);
        while(getchar() != '\n'); // clear input buffer
    }

    // Displaying the entered information
    for (i = 0; i < 3; i++) {
        printf("\nStudent %d\n", i+1);
        printf("Name: %s", info[i].name);
        printf("Age: %d\n", info[i].age);
        printf("Grade: %d\n", info[i].grade);
        printf("\n");
    }

    return 0;
}
