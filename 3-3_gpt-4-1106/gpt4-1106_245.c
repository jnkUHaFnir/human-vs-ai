s = realloc(s, sizeof(students) * (scount + 1));
students *temp = realloc(s, sizeof(students) * (scount + 1));
if (temp == NULL) {
    // Handle the error, e.g. by printing an error message and returning.
    printf("Error reallocating memory!\n");
    return;
} else {
    s = temp; // Only update the s pointer if realloc was successful.
}
void addNewStudent()
{
    // If this is the first student, allocate memory for one student.
    if (scount == 0) {
        s = malloc(sizeof(students));
        if (s == NULL) {
            printf("Error allocating memory!\n");
            return;
        }
    } else {
        // Otherwise, reallocate memory to fit one more student.
        students *temp = realloc(s, sizeof(students) * (scount + 1));
        if (temp == NULL) {
            printf("Error reallocating memory!\n");
            return;
        } else {
            s = temp;
        }
    }

    printf("Geben Sie Bitte den Namen ein:\n");
    // Make sure to use fgets to read from stdin.
    if (fgets(s[scount].name, sizeof(s[scount].name), stdin) == NULL) {
        printf("Error reading name.\n");
        return;
    }

    // Replace the newline character at the end of the name with a null terminator.
    s[scount].name[strcspn(s[scount].name, "\n")] = '\0';

    // Increase the student count.
    scount++;
}
while ((ch = getchar()) != '\n' && ch != EOF);
