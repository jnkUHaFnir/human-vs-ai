for (i = 3; i < 6; i++) {
    student_t[i].name = malloc(sizeof(char) * 100);
    student_t[i].surname = malloc(sizeof(char) * 100);
    student_t[i].UUN = malloc(sizeof(char) * 100);
    
    printf("Enter your name: ");
    scanf(" %99s", student_t[i].name);
    printf("Enter your surname: ");
    scanf(" %99s", student_t[i].surname);
    printf("Enter your UUN: ");
    scanf(" %99s", student_t[i].UUN);
    printf("Enter your department: ");
    scanf(" %s", student_t[i].department);
    printf("Enter your gender: ");
    scanf(" %c", &student_t[i].gender);
    printf("Enter your age: ");
    scanf(" %d", &student_t[i].age);
}
for (i = 3; i < 6; i++) {
    free(student_t[i].name);
    free(student_t[i].surname);
    free(student_t[i].UUN);
}
