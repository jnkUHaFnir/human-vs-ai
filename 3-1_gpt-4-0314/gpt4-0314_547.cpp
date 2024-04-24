...
do
{
    ++j;
    if(scanf("%d", &i) == 1) {
        printf("\n\n%d %d\n\n", i, j);
    } else {
        printf("Invalid input\n");
        while(getchar() != '\n');  // Clear the input buffer
    }
}
...
...
do
{
    ++j;
    if (cin >> i) {
        cout << i << " " << j << "\n";
    } else {
        cout << "Invalid input\n";
        cin.clear();                     // Reset the fail state
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
    }
}
...
