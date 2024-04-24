#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_TEAMS 32
#define TEAM_NAME_LENGTH 30

int main(void) {
    double teamScore[MAX_TEAMS] = {0};
    char teamName[MAX_TEAMS][TEAM_NAME_LENGTH] = {0};
    int n = 0;
    FILE *filein_ptr;

    filein_ptr = fopen("data.csv", "r");
    if (filein_ptr == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fscanf(filein_ptr, "%29[^,],%lf\n", teamName[n], &teamScore[n]) == 2) {
        // Make sure we don't read more teams than we can store
        if (n < MAX_TEAMS - 1) {
            n++;
        }
    }

    fclose(filein_ptr);

    // For demonstration, let's print the names and scores to verify they are read correctly.
    for (int i = 0; i < n; i++) {
        printf("%s - %.0lf\n", teamName[i], teamScore[i]);
    }

    return 0;
}
