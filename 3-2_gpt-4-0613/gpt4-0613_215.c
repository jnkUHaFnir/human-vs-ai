#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

void UpperCaseFirstLetter(char* str){
    int len = strlen(str);
    for (int i=0; i<len; i++){
        if(i == 0 || str[i-1] == ' '){
            // Make the first character of each word capital.
            str[i] = toupper(str[i]);
        }
        else{
            // Make the rest characters in word lower.
            str[i] = tolower(str[i]);
        }
    }
}

int main(void) {
    char name[MAX_NAME_LENGTH];
    int invalidInput;
    
    do{
        invalidInput = 0;
        printf("Enter your name: ");
        scanf("%s", name);

        for(int i=0; i<strlen(name); i++){
            if(!isalpha(name[i])){
                printf("Invalid character. Please enter a valid name.\n");
                invalidInput = 1;
                break;
            }
        }
    }while(invalidInput);

    UpperCaseFirstLetter(name);
    printf("Your name is: %s\n", name);

    return 0;
}
