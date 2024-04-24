#include <stdio.h>
#include <stdlib.h>

typedef struct instruction {
    int op; // opcode
    int l; // L
    int m; // M
} instruction;

instruction* read_file(instruction[]);
char* lookup_OP(int OP);
void print_program(instruction[]);
void print_input_list(instruction[]);

instruction* read_file(instruction code[]) {
    int i = 0;
    FILE* ifp = fopen("input.txt", "r");

    if (ifp == NULL) {
        fprintf(stderr, "Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(ifp, "%d %d %d", &code[i].op, &code[i].l, &code[i].m) == 3) {
        i++;
    }

    code[i].op = -1; // Identifies the end of the code in the array
    fclose(ifp);
    
    return code;
}

void print_input_list(instruction code[]) {
    int i = 0;
    while (code[i].op != -1) {
        printf("%d %d %d\n", code[i].op, code[i].l, code[i].m);
        i++;
    }
}

void print_program(instruction code[]) {
    // Implement the logic to print the program as needed
}

int main() {
    instruction code[501];
    read_file(code);
    print_input_list(code); // Used for debugging
    print_program(code);
    
    return 0;
}
