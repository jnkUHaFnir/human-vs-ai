#include <stdio.h>

int main() {
    char name[6]; // 5 characters + null terminator
    char fav_nums[5];

    printf("What is your name (max characters 5)?\n");
    scanf("%5s", name);

    printf("Hi, %s\n", name);

    printf("Enter your 5 favorite numbers!\n");
    int i = 0;
    while (i < 5) {
        scanf("%d", &fav_nums[i]);
        i++;
    }

    fav_nums[4] = '\0'; // Adding null terminator at the end

    printf("Cool, I love");
    i = 0;
    while (i < 5) {
        printf(" %d", fav_nums[i]); // Corrected variable name
        i++;
    }
    printf("\n");

    return 0;
}
