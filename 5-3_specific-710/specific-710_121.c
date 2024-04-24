#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    int any_integer;
    char any_string[30];
    float any_float;

    while(1) {
        printf("Please enter an integer, one word string, and a float in one line: ");
        
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, "%d %29s %f", &any_integer, any_string, &any_float) == 3) {
                // Input parsed successfully
                if (any_integer >= 0 && any_integer <= 50) {
                    printf("Integer: %d\n", any_integer);
                } else {
                    printf("*** Invalid integer. Please enter a value between 0 and 50.\n");
                    continue;
                }

                if (any_float >= 0) {
                    printf("Float: %f\n", any_float);
                } else {
                    printf("*** Invalid float. Please enter a positive value.\n");
                    continue;
                }

                // Filtering out non-alphabetic characters from any_string
                for (int i = 0; any_string[i]; i++) {
                    if (isalpha(any_string[i])) {
                        printf("%c", any_string[i]);
                    }
                }

            } else if (strcmp(input, "999\n") == 0) {
                // Exit the program
                break;
            } else {
                printf("*** Invalid input format. Please enter an integer, one word string, and a float in one line.\n");
            }
        }
    }

    return 0;
}
