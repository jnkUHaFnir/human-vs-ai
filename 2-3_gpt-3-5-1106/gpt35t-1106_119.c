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
        printf("Enter name for student %d : ", i+1);
        scanf("%s", info[i].name);
        printf("Enter age for sudent %d : ", i+1);
        scanf("%d", &info[i].age);
        printf("Enter grade for student %d : ", i+1);
        scanf("%d", &info[i].grade);
    }
    return 0;
}
