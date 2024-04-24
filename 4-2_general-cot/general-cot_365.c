#include <stdio.h>

int main() {
    char name[6]; // Increased size by 1 to account for null terminator
    char fav_nums[5];
    
    printf("What is your name (max characters 5)?\n");
    scanf("%5s", name); // Specified maximum input length to prevent buffer overflow
    
    printf("Hi, %s\n", name);

    printf("Enter your 5 favorite numbers!\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &fav_nums[i]); // Used address of operator '&' to store input in array elements
    }

    printf("Cool, I love");
    for (int i = 0; i < 5; i++) {
        printf(" %d", fav_nums[i]);
    }
    printf("\n");

    return 0;
}
