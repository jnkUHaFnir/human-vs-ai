#include <stdio.h>

struct book {
    char name[20];
};

int main() {
    struct book buk[10];
    int i;
    for(i = 0; i < 3; i++) {
        printf("Enter name of book %d: ", i + 1);
        scanf("%[^\n]%*c", buk[i].name); // Notice we removed 's' from the format and added '%*c'
    }
    for(i = 0; i < 3; i++) {
        printf("Book %d: %s\n", i + 1, buk[i].name);
    }
    return 0;
}
#include <stdio.h>

struct book {
    char name[20];
};

int main() {
    struct book buk[10];
    int i;
    for(i = 0; i < 3; i++) {
        printf("Enter name of book %d: ", i + 1);
        fgets(buk[i].name, sizeof(buk[i].name), stdin); // reads a line, including the newline
        // Remove the possible newline at the end
        buk[i].name[strcspn(buk[i].name, "\n")] = 0; // This line removes the newline, if any
    }
    for(i = 0; i < 3; i++) {
        printf("Book %d: %s\n", i + 1, buk[i].name);
    }
    return 0;
}
