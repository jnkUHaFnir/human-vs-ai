// Initialization of num and counters
num = 1; // set to a non-zero value to enter the loop
even_count = 0;
odd_count = 0;
while (num != 0) {
    printf("Enter a number:\n");
    scanf("%d", &num);
    
    if (num == 0) break;

    if (num % 2 == 0) {
        printf("even\n");
        even_count++;
        add_even(num);  // Increment the even sum
    } else {
        printf("odd\n");
        odd_count++;
        add_odd(num);   // Increment the odd sum
    }
}

// Print summary here, outside the loop (after `break;`)
