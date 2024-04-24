#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char name[100]; // Allocate more space to avoid overflow
    int check;
    do {
       printf("Enter the name: "); 
       fgets(name, sizeof(name), stdin); // Safer than scanf for strings
       name[strcspn(name, "\n")] = 0; // Removing the newline character
       check = 0;
       for(int i = 0; i < strlen(name); i++){
          if(isalpha(name[i]) == 0){
             printf("Invalid character. Please enter a valid name.\n");
             check = 1;
             break;
          }
       }
    } while(check == 1);

    // Further processing...
    return 0;
}
name[0] = toupper(name[0]); // Ensure the first letter is uppercase
for(int i = 1; name[i] != '\0'; i++){ 
    if(name[i-1] == ' ') {
        name[i] = toupper(name[i]);
    } else {
        name[i] = tolower(name[i]);
    }
}
