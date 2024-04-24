#include <stdio.h>

struct student {
    int r;
    char a[50];
    int c1, c2, c3;
    float total, per;
} s[100];

int main() {
    int i, n;
    printf("Enter total number of students\n");
    scanf("%d", &n);
    getchar(); // consume the newline character

    for (i = 0; i < n; i++) {
        printf("Enter details of student\nRollNo Name c1 c1 c3 marks\n");
        scanf("%d %[^\n] %d %d %d", &s[i].r, s[i].a, &s[i].c1, &s[i].c2, &s[i].c3);
    }
    
    for (i = 0; i < n; i++) {
        printf("%d %s %d %d %d\n", s[i].r, s[i].a, s[i].c1, s[i].c2, s[i].c3);
    }

    return 0;
}
