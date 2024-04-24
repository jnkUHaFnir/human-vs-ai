printf("What is your name (max characters 5)?\n");
fgets(name, 5, stdin);
name[strcspn(name, "\n")] = 0; // Remove the newline character
int fav_nums[5]; // An array of integers

printf("Enter your 5 favorite numbers!\n");
for (int i = 0; i < 5; i++) {
    scanf("%d", &fav_nums[i]); // Use & to get the address of fav_nums[i]
}
printf("Cool, I love");
for (int i = 0; i < 5; i++) {
    printf(" %d", fav_nums[i]); // Correct the variable name to fav_nums
}
printf("\n");
