#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[100];
    int i;

    do {
        printf("Enter your name: ");
        if(scanf("%99s", name) == 1) { // Limit input size to prevent buffer overflow
            int valid = 1;
            for(i = 0; i < strlen(name); i++) {
                if(!isalpha(name[i])) {
                    valid = 0;
                    printf("Invalid character. Please enter a valid name.\n");
                    break;
                }
            }
            if(valid) {
                // Convert to lowercase
                for(i = 0; name[i]; i++) {
                    name[i] = tolower(name[i]);
                }

                // Capitalize first letter of each word
                int capitalizeNext = 1;
                for(i = 0; name[i]; i++) {
                    if (isalpha(name[i])) {
                        if (capitalizeNext) {
                            name[i] = toupper(name[i]);
                            capitalizeNext = 0;
                        } else {
                            name[i] = tolower(name[i]);
                        }
                    } else {
                        capitalizeNext = 1; // Next character should be capitalized
                    }
                }

                printf("Processed name: %s\n", name);
                break;
            }
        } else {
            printf("Please enter a valid name.\n");
            // Clear input buffer
            while(getchar() != '\n');
        }
    } while(1);

    return 0;
}
