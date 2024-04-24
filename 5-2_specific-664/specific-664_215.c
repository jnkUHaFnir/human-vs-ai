do{
   if(scanf("%s", &name) == 1)
       break;
   else printf("Please enter a valid name.\n");
}while(1);
do{
   check = 0;
   scanf("%s", &name);
   for(i=0; i<strlen(name); i++){
      if(isalpha(name[i]) == 0){
         printf("Invalid character. Please enter a valid name.\n");
         check = 1;
         break;
      }
   }
}while(check == 1);
#include <stdio.h>
#include <ctype.h>

int main() {
    char name[50]; // adjust the size as needed
    int i, isValid = 0;

    do {
        printf("Enter a name: ");
        fgets(name, sizeof(name), stdin);
        
        for (i = 0; name[i] != '\0'; i++) {
            if (name[i] == '\n') {
                name[i] = '\0'; // remove the newline character
                break; // exit the loop
            }
            if (!isalpha(name[i])) {
                printf("Invalid character. Please enter a valid name.\n");
                isValid = 0;
                break; // exit the loop
            }
            isValid = 1;
        }
    } while (!isValid);

    // Capitalize the first letter and convert others to lowercase
    for (i = 0; name[i] != '\0'; i++) {
        if (i == 0 || name[i - 1] == ' ') {
            name[i] = toupper(name[i]);
        } else {
            name[i] = tolower(name[i]);
        }
    }

    printf("Name: %s\n", name);

    return 0;
}
