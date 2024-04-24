#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char name[100];
    int i;
    int check;

    do{
        check = 0;
        scanf("%s", name);
        for(i = 0; i < strlen(name); i++){
            if(isalpha(name[i]) == 0){
                printf("Invalid character. Please enter a valid name.\n");
                check = 1;
                break;
            }
        }
    }while(check == 1);

    // Convert all letters to lowercase except the first letter
    for(i = 1; i < strlen(name); i++){
        name[i] = tolower(name[i]);
    }
  
    // Convert the first letter to uppercase
    name[0] = toupper(name[0]);

    printf("Valid name: %s\n", name);
    return 0;
}
