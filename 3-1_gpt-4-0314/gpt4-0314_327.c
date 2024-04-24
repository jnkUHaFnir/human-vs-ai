#include <stdio.h>

int main(){
    int numOfDef;

    while (1) {
        char input[100];
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &numOfDef) == 1 && numOfDef > 0)
            break;

        printf("Not a positive number, try again: ");
    }

    return 0;
}
