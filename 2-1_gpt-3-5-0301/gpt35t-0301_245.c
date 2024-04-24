typedef struct students {
    char name[50];
} students;

int main() {
    students *s = NULL;
    int scount = 0;
    ...
}
s = realloc(s, sizeof(students) * (scount + 1));
int index = strlen(s[scount].name) - 1;
s[scount].name[index] = '\0';
s = realloc(s, sizeof(students) * (scount + 1));
if (scount == 0) {
    s = malloc(sizeof(students));
    if (!s) {
        fprintf(stderr, "Error: Failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
} else {
    students *temp = realloc(s, sizeof(students) * (scount + 1));
    if (!temp) {
        fprintf(stderr, "Error: Failed to reallocate memory.\n");
        exit(EXIT_FAILURE);
    }
    s = temp;
}
switch(in) {
    case '1':
        addNewStudent(s, &scount);
        break;
    case '9':
        loop = 0;
        break;
    default:
        printf("Error: Invalid input.\n");
        break;
}
void addNewStudent(students **s, int *scount) {
    ...
}
