#include <stdio.h>

int are_overlapping(const char *a, const char *b) {
    return (a < b && b < a + strlen(a)) || (b < a && a < b + strlen(b));
}

int main() {
    const char a[] = "string";
    const char b[] = "another string";

    printf("%d\n", are_overlapping(a, b)); // should return 0
    printf("%d\n", are_overlapping(a, a + 3)); // should return 1

    return 0;
}
