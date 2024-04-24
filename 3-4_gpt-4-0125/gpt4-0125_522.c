#include <stdio.h>
#include <string.h>

void getInput(char *variable, int size) {
    if (fgets(variable, size, stdin) != NULL) {
        size_t len = strlen(variable);
        if (len > 0 && variable[len - 1] == '\n') {
            variable[len - 1] = '\0'; // Remove the newline character
        }
    }
}

int main(void) {
    char variable1[50], variable2[50];

    printf("Put equipo: ");
    getInput(variable1, sizeof(variable1));

    if (Exists(variable1)) { // Assuming Exists is a function you have defined elsewhere
        printf("Put Piloto ");
        getInput(variable2, sizeof(variable2));
        printf("You said %s and %s\n", variable1, variable2);
    }

    return 0;
}
