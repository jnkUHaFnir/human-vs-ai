#include<stdio.h>
#include<stdlib.h>

typedef struct instruction {
    int op; //opcode
    int l; // L
    int m; // M
} instr;

FILE *ifp;  //input file pointer
FILE *ofp;  //output file pointer
instruction code[501];

void read_file(instruction code[]);
char *lookup_OP(int OP);
void print_program(instruction code[]);
void print_input_list(instruction code[]);

int main() {
    read_file(code);
    print_input_list(code);  //used for debugging
    print_program(code);
}

void read_file(instruction code[]) {
    int i = 0;

    ifp = fopen("input.txt", "r");

    while (!feof(ifp)) {
        fscanf(ifp, "%d%d%d", &code[i].op, &code[i].l, &code[i].m);
        i++;
    }
    code[i].op = -1;  //identifies the end of the code in the array
    fclose(ifp);
}
