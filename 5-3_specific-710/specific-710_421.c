#include <stdio.h>
#include <string.h>

#define SIZE 5

struct books {
    char name[100], author[100];
    int year, copies;
};

void sort(struct books *, int);

int main() {
    int i;
    char c;

    struct books book1[SIZE];

    for (i = 0; i < SIZE; i++) {
        fgets(book1[i].name, sizeof(book1[i].name), stdin);  // Use fgets instead of gets
        strtok(book1[i].name, "\n"); // Remove newline character
        fgets(book1[i].author, sizeof(book1[i].author), stdin);
        strtok(book1[i].author, "\n"); // Remove newline character
        scanf("%d%d", &book1[i].year, &book1[i].copies);
        while ((c = getchar()) != '\n' && c != EOF);
    }

    sort(book1, SIZE);

    for (i = 0; i < SIZE; i++) {
        printf("##########################################################################\n");
        printf("Book: %s\nAuthor: %s\nYear of Publication: %d\nNo of Copies: %d\n",
               book1[i].name, book1[i].author, book1[i].year, book1[i].copies);
        printf("##########################################################################\n");
    }

    return 0;
}

void sort(struct books *pointer, int n) {
    int i, j, sorted = 0;
    struct books temp;

    for (i = 0; i < n - 1 && sorted == 0; i++) {
        sorted = 1;
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(pointer[j].name, pointer[j + 1].name) > 0) {
                temp = pointer[j];
                pointer[j] = pointer[j + 1];
                pointer[j + 1] = temp;
                sorted = 0;
            }
        }
    }
}
