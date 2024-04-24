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
    struct books book1[SIZE];

    for (i = 0; i < SIZE; i++) {
        fgets(book1[i].name, 100, stdin);
        fgets(book1[i].author, 100, stdin);
        scanf("%d%d", &book1[i].year, &book1[i].copies);
        while (getchar() != '\n');
    }

    sort(book1, SIZE);

    for (i = 0; i < SIZE; i++) {
        printf("##########################################################################\n");
        printf("Book: %sAuthor: %sYear of Publication: %dNo of Copies: %d\n", book1[i].name, book1[i].author, book1[i].year, book1[i].copies);
        printf("##########################################################################\n");
    }

    return 0;
}

void sort(struct books *books_arr, int n) {
    int i, j;
    struct books temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(books_arr[j].name, books_arr[j + 1].name) > 0) {
                temp = books_arr[j];
                books_arr[j] = books_arr[j + 1];
                books_arr[j + 1] = temp;
            }
        }
    }
}
