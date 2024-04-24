for (i = 3; i < 6; i++) {
    /* Allocate memory for fields */
    student_t[i].name = (char*) malloc(50 * sizeof(char));
    student_t[i].surname = (char*) malloc(50 * sizeof(char));
    student_t[i].UUN = (char*) malloc(50 * sizeof(char));
    student_t[i].department = (char*) malloc(50 * sizeof(char));

    printf("Enter your name: ");
    scanf(" %s", student_t[i].name);
    printf("Enter your surname: ");
    scanf(" %s", student_t[i].surname);
    // ... and so on
}
typedef struct {
    char name[50];
    char surname[50];
    char UUN[50];
    char department[50];
    char gender;
    int age;
} student_t;
