#include <stdio.h>
#include <stdlib.h>

typedef struct instruction {
    int op; //opcode
    int l; // L
    int m; // M
} instruction;

instruction* read_file(instruction code[]);
char* lookup_OP(int OP);
void print_program(instruction code[]);
void print_input_list(instruction code[]);

int main() {
    instruction code[501];
    read_file(code);
    print_input_list(code); // used for debugging
    print_program(code);
    return 0;
}

instruction* read_file(instruction code[]) {
    FILE *ifp = fopen("input.txt", "r");
    if (ifp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    
    int i = 0;
    while (fscanf(ifp,"%d %d %d", &code[i].op, &code[i].l, &code[i].m) == 3) {
        i++;
    }
    code[i].op = -1; // Identifies the end of the code in the array
    fclose(ifp);
    return code;
}
