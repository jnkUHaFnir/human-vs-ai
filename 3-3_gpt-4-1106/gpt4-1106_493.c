#include <stdio.h>
#include <stdlib.h>

// The rest of your code ...

// Function prototype updated to take a pointer to an array of instr (instruction)
void read_file(instr code[]); // just declare the function without a return type or parameters

int main() {
    read_file(code); // call the function with the array, which will modify the array directly
    print_input_list(code); // used for debugging
    print_program(code);
}

void read_file(instr code[]) {
    int i = 0;

    ifp = fopen("input.txt", "r");
    if (ifp == NULL) {
        // Handle the error if the file cannot be opened.
        fprintf(stderr, "Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(ifp, "%d %d %d", &code[i].op, &code[i].l, &code[i].m) == 3) {
        i++;
        // Make sure we don't go past the end of the array
        if (i >= 501) {
            // Handle the error if there are too many instructions.
            fprintf(stderr, "Too many instructions.\n");
            fclose(ifp);
            exit(EXIT_FAILURE);
        }
    }

    // This marks the end of the code in the array
    if (i < 501) {
        code[i].op = -1;
    }

    fclose(ifp);
    // No need to return anything
}

// The rest of your code ...
