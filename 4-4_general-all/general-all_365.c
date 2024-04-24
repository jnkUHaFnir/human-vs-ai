#include <stdio.h>

int main() {

    char name[6]; // Increasing the size by 1 to account for the null terminator
    char fav_nums[5];
    
    printf("What is your name (max characters 5)?\n");
    scanf("%5s", name); // Limiting the input to 5 characters + null terminator
    
    printf("Hi, %s\n", name);

    printf("Enter your 5 favorite numbers!\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &fav_nums[i]); // Using & to correctly pass the address of fav_nums[i]
    }

    printf("Cool, I love");
    for (int i = 0; i < 5; i++) {
        printf(" %d", fav_nums[i]);
    }
    printf("\n");

    return 0;
}
