#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char *password = (char*)malloc(sizeof(char));
    int index = 0;
    int x = 0;
    int y = 0;
    int z = 0;

    printf("Enter Password: "); //Mike$4
    scanf("%s", password);

    do {
        if(index == strlen(password) && x>0 && y>0 && z>0){
            printf("Good password!");
            break;
        }
        if(index == strlen(password) && (x==0 || y==0 || z==0)){
            printf("BAD PASSWORD");
            break;
        }

        if(isupper(password[index]) ||  isdigit(password[index]) || password[index] == '$'){

            if(isupper(password[index])){
                x++;
            } 
            if(isdigit(password[index])){
                y++;
            } 
            if(password[index] == '$'){
                z++;
            }
            index++;
        } else{
            index++;
        }
    } while(index <= strlen(password));

    free(password); // Free the dynamically allocated memory

    return 0;
}
