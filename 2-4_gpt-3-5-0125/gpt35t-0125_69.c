while ((scanf("%f", &sales) != 1) || (sales < -1))
{
    while (getchar() != '\n'); // clear the input buffer

    puts("Input error, please try again");
    printf("Enter sales in dollars (-1 to end): ");
}
