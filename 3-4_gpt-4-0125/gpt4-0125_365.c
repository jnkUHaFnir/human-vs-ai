#include <stdio.h>

int main() {
    char name[6]; // Allows space for 5 characters plus a null terminator

    int fav_nums[5]; // Correctly declared as an int array

    printf("What is your name (max characters 5)?\n");
    scanf("%4s", name); // Ensures the input doesn't overflow the buffer, leaving space for the null terminator
    
    printf("Hi, %s\n", name);

    printf("Enter your 5 favorite numbers!\n");
    for(int i = 0; i < 5; i++) {
        scanf("%d", &fav_nums[i]); // Correct usage for integer input
    }

    printf("Cool, I love");
    for(int i = 0; i < 5; i++) {
        printf(" %d", fav_nums[i]);
    }
    printf("\n");

    return 0;
}
