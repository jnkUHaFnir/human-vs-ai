#include <stdio.h>

int main() {
    char name[6]; // Increase array size to store a null terminator '\0'
    
    char fav_nums[5];
    
    printf("What is your name (max characters 5)?\n");
    scanf("%5s", name); // Read up to 5 characters
    
    printf("Hi, %s\n", name);

    printf("Enter your 5 favorite numbers!\n");
    int i = 0;
    while (i < 5) {
        scanf("%d", &fav_nums[i]); // Note the & to get the address of fav_nums[i]
        i++;
    }
    
    printf("Cool, I love");
    i = 0;
    while (i < 5) {
        printf(" %d", fav_nums[i]); // Correct variable name fav_nums
        i++;
    }
    printf("\n");

    return 0;
}
