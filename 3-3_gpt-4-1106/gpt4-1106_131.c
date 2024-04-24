    char check = 'a';
    for(int i=0; check != EOF; ++i){
        check = scanf("%s", input); // This line is improper
        printf("%s\n",input);
    }
#include <stdio.h>
#include <stdlib.h>

char* createList();

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    char input[50];
    int check; // Use int here, not char
    while((check = scanf("%49s", input)) != EOF){ // Changed the loop condition
        printf("%s\n", input);
        // In case you want to exit the loop when incorrect input is provided, add this:
        if (check == 0) { // scanf returns the number of input items successfully matched
            break; // Exit loop if no item is matched
        }
    }

    char* myAnswer = createList();
    printf("%s\n", myAnswer);

    free(myAnswer); // Don't forget to free dynamically allocated memory

    return 0;
}

// ... createList definition ...
