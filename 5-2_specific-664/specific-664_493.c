#include <stdio.h>
#include <stdlib.h>

typedef struct instruction {
    int op; // opcode
    int l; // L
    int m; // M
} instruction;

FILE *ifp; // input file pointer
FILE *ofp; // output file pointer
instruction code[501];

instruction* read_file(instruction code[]);
char* lookup_OP(int OP);
void print_program(instruction code[]);
void print_input_list(instruction code[]);

int main() {
    read_file(code);
    print_input_list(code); // used for debugging
    print_program(code);
}

instruction* read_file(instruction code[]) {
    int i = 0;

    ifp = fopen("input.txt", "r");

    while (fscanf(ifp, "%d %d %d", &code[i].op, &code[i].l, &code[i].m) == 3) {
        i++;
    }
    code[i].op = -1; // identifies the end of the code in the array
    fclose(ifp);
    return code;
}
