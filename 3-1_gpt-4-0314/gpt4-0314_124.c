typedef struct {
  char name[256];
  char surname[256];
  char UUN[256];
  char department[256];
  char gender;
  int age;
} student_t;
for (i = 3; i < 6; i++) {
    printf("Enter your name: ");
    scanf(" %255s", student_t[i].name);
    printf("Enter your surname: ");
    scanf(" %255s", student_t[i].surname);
    printf("Enter your UUN: ");
    scanf(" %255s", student_t[i].UUN);
    printf("Enter your department: ");
    scanf(" %255s", student_t[i].department);
    printf("Enter your gender: ");
    scanf(" %c", &student_t[i].gender);
    printf("Enter your age: ");
    scanf(" %d", &student_t[i].age);
}
