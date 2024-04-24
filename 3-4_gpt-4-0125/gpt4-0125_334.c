#include <stdio.h>

int main() {
    FILE* spTemp;

    // Adjust the path according to your setup
    spTemp = fopen("/home/chronos/user/Downloads/grades.txt", "r");
    
    // Always check if the file was successfully opened
    if (spTemp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Example of reading from the file
    char buffer[1000];
    while (fgets(buffer, 1000, spTemp) != NULL) {
        printf("%s", buffer); // Print each line of the file
    }

    // Don't forget to close the file when you're done
    fclose(spTemp);

    return 0;
}
