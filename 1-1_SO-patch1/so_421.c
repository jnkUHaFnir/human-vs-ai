	#include <stdio.h>
	#include <string.h>
	#define SIZE 5
	struct books {
		char name[100], author[100];
		int year, copies;
	};
	static void sort(struct books *books, int n);
	int main()
	{
		int i;
		char c;
		struct books books[SIZE];
		for (i = 0; i < SIZE; i++) {
			fgets(books[i].name, sizeof books[i].name, stdin);
			fgets(books[i].author, sizeof books[i].author, stdin);
			scanf("%d%d", &books[i].year, &books[i].copies);
			while ((c = getchar()) != '\n' && c != EOF);
		}
		sort(books, SIZE);
		for (i = 0; i < SIZE; i++) {
			printf("##########################################################################\n");
			printf("Book: %s\nAuthor: %s\nYear of Publication: %d\nNo of Copies: %d\n", books[i].name, books[i].author, books[i].year, books[i].copies);
			printf("##########################################################################\n");
		}
	}
	static void dup(struct books *dst, const struct books *src)
	{
		strcpy(dst->name, src->name);
		strcpy(dst->author, src->author);
		dst->year = src->year;
		dst->copies = src->copies;
	}
	static void swap(struct books *a, struct books *b)
	{
		struct books tmp;
		dup(&tmp, a);
		dup(a, b);
		dup(b, &tmp);
	}
	static void sort(struct books *books, int n)
	{
		int i, j;
		for (i = n - 1; i >= 0; i--) {
			for (j = 0; j < i; j++) {
				if (strcmp(books[j].name, books[j + 1].name) > 0) {
					swap(&books[j], &books[j + 1]);
				}
			}
		}
	}