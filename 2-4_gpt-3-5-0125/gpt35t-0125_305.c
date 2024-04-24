#include <stdio.h>
#include <ctype.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isdigit(num)) {
        printf("%d is a number.\n", num);
    } else {
        printf("%d is not a number.\n", num);
    }

    return 0;
}
