printf("Enter a number: ");
if(scanf("%d", &number) != 1)
{
    // clear input buffer
    while((c = getchar()) != '\n' && c != EOF);
}
else
{
    sum += number;
}
