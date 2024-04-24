hypo_table[0][0] = fopen("00.txt", "w");
if (hypo_table[0][0] == NULL) {
    printf("Failed to open file 00.txt\n");
    return -1; // or handle the error appropriately
}
// Repeat the above check for all file pointers

// Rest of the code
