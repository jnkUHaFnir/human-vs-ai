#include <stdio.h>

struct student {
    char name[50];   // declare name using array
    int age;
    int grade;
};

// Function to clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    struct student info[3];   // declare 3 students
    int i;

    for (i = 0; i < 3; i++) {    // Corrected the loop to use 0-based indexing
        printf("Enter name for student %d: ", i + 1);
        fgets(info[i].name, 50, stdin);  // Use fgets to allow spaces in names
        info[i].name[strcspn(info[i].name, "\n")] = 0; // Remove the trailing newline character

        printf("Enter age for student %d: ", i + 1);
        scanf("%d", &info[i].age);
        clearInputBuffer();  // Clear input buffer to consume the newline

        printf("Enter grade for student %d: ", i + 1);
        scanf("%d", &info[i].grade);
        clearInputBuffer();  // Clear input buffer again for the next loop iteration
    }

    return 0;
}
