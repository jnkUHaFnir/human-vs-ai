typedef struct {
    char name[50];
    char surname[50];
    char UUN[50];
    char department[50];
    char gender;
    int age;
} student_t;
for (i = 3; i < 6; i++) {
    printf("Enter your name: ");
    scanf(" %49s", student_t[i].name);
    printf("Enter your surname: ");
    scanf(" %49s", student_t[i].surname);
    printf("Enter your UUN: ");
    scanf(" %49s", student_t[i].UUN);
    printf("Enter your department: ");
    scanf(" %49s", student_t[i].department);
    printf("Enter your gender: ");
    scanf(" %c", &student_t[i].gender);
    printf("Enter your age: ");
    scanf(" %d", &student_t[i].age);
}
