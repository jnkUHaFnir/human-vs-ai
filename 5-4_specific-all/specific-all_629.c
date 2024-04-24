#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char name[100];
    int i;
    int valid = 1;

    do {
        valid = 1;
        if(scanf("%99s", name) != 1) {
            printf("Invalid input. Please enter a valid name.\n");
            // Clear the input buffer
            while (fgetc(stdin) != '\n');
            continue;
        }

        for(i = 0; i < strlen(name); i++) {
            if(!isalpha(name[i])) {
                valid = 0;
                printf("Invalid character. Please enter a valid name.\n");
                break;
            }
        }
    } while (!valid);

    // Convert to lowercase
    for(i = 0; name[i]; i++){
        name[i] = tolower(name[i]);
    }

    // Capitalize the first letter
    if(name[0]){
        name[0] = toupper(name[0]);
    }

    // Capitalize first letter after each space
    for(i = 1; name[i]; i++){
        if(name[i-1] == ' '){
            name[i] = toupper(name[i]);
        }
    }

    printf("Processed name: %s\n", name);

    return 0;
}
