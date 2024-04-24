#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

int main() {
    char name[MAX_NAME_LENGTH];
    int i;
    int check;

    do {
        check = 0;
        scanf("%s", name);  // no & needed
        for(i = 0; i < strlen(name); i++) {
            if(!isalpha(name[i])) {
                printf("Invalid character. Please enter a valid name.\n");
                check = 1;
                break;
            }
        }
    } while(check == 1);

    //all to lower except the first letter
    for(i = 1; i < strlen(name); i++) {
        name[i] = tolower(name[i]);
    }

    //first letter to upper
    name[0] = toupper(name[0]);

    i = 1;
    while(name[i] != '\0') {
        //if the letter before is a white space, even the first letter, it should place the first letter of a name upper
        if(name[i - 1] == ' ') {
            name[i] = toupper(name[i]);
        }
        i++;
    }

    printf("Transformed name: %s\n", name);
    return 0;
}
