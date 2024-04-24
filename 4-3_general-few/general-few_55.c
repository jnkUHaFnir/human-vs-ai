int count = 0;
for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
        if (scanf("%d", &arr[i][j]) != 1) {
            printf("Insufficient datapoints\n");
            // Handle the error or break out of the loop as needed
            break;
        }
        count++;
    }
}

// Check if the total number of integers read matches the expected size of the array
if (count != r * c) {
    printf("Insufficient datapoints\n");
}
