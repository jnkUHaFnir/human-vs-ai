#include <stdio.h>

struct student {
    char name[50];   // declare name using an array
    int age;
    int grade;
};

int main()
{
    struct student info[3];   //declare 3 students
    int i;

    for(i=0;i<3;i++) {    // this is for looping, student 0 (1), student 1 (2), student 2 (3)
        printf("Enter name for student %d: ", i+1);
        fgets(info[i].name, 50, stdin);   // read the whole line including spaces
        info[i].name[strcspn(info[i].name, "\n")] = 0; // remove the newline at the end
        printf("Enter age for student %d: ", i+1);
        scanf("%d", &info[i].age);
        while(getchar() != '\n');    // clear the input buffer
        printf("Enter grade for student %d: ", i+1);
        scanf("%d", &info[i].grade);
        while(getchar() != '\n');    // clear the input buffer
    }
    return 0;
}
