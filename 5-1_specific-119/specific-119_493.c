#include <stdio.h>
#include <stdlib.h>

typedef struct instruction {
    int op; // opcode
    int l; // L
    int m; // M
} instruction;

instruction* read_file(instruction* code, int size);
const char* lookup_OP(int OP);
void print_program(instruction* code);
void print_input_list(instruction* code, int size);

int main() {
    instruction code[501];
    int size = sizeof(code) / sizeof(code[0]);

    read_file(code, size);
    print_input_list(code, size); // used for debugging
    print_program(code);
    return 0;
}

instruction* read_file(instruction* code, int size) {
    int i = 0;
    FILE* ifp = fopen("input.txt", "r");

    if (ifp == NULL) {
        perror("Error opening file");  // You may want to handle this error in a specific way
        return NULL;
    }

    while (fscanf(ifp, "%d %d %d", &code[i].op, &code[i].l, &code[i].m) == 3 && i < size) {
        i++;
    }
    code[i].op = -1; // identifies the end of the code in the array
    fclose(ifp);

    return code;
}
