#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 100

int main() {
    char line[MAX_LINE_SIZE];
    int nums[MAX_LINE_SIZE], num_count;
    char *tok, *rest;

    while(fgets(line, MAX_LINE_SIZE, stdin)) {
        // Remove the newline character from the end of the line
        line[strcspn(line, "\n")] = 0;

        // Parse the first integer before the colon
        tok = strtok(line, ":");
        int first_num = atoi(tok);

        // Parse the comma-separated list of integers
        rest = strtok(NULL, "");
        tok = strtok(rest, ",");
        num_count = 0;
        while(tok != NULL) {
            nums[num_count] = atoi(tok);
            num_count++;
            tok = strtok(NULL, ",");
        }

        // Do something with the numbers from the current line
        printf("First num=%d, nums={", first_num);
        for(int i = 0; i < num_count; i++) {
            printf("%d", nums[i]);
            if(i < num_count - 1)
                printf(", ");
        }
        printf("}\n");
    }

    return 0;
}
