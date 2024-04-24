instruction* read_file(instruction*, int);
instruction* read_file(instruction* code, int size){
    // code implementation
}
code = read_file(code, sizeof(code) / sizeof(code[0]) - 1);
instr code[501];
#include<stdio.h>
#include<stdlib.h>

typedef struct instruction{
    int op; //opcode
    int  l; // L
    int  m; // M
} instr;

instruction* read_file(instruction*, int);
void print_program(instruction*);
void print_input_list(instruction*);

int main(){

    instr code[501];
    code = read_file(code, sizeof(code) / sizeof(code[0]) - 1);
    print_input_list(code);
    print_program(code);
    return 0;
}

instruction* read_file(instruction* code, int size){
    int i = 0;
    FILE* ifp = fopen("input.txt", "r");

    while(!feof(ifp) && i < size){
        fscanf(ifp,"%d%d%d",&code[i].op, &code[i].l, &code[i].m);
        i++;
    }
    code[i].op = -1; //identifies the end of the code in the array
    fclose(ifp);
    return code;
}

void print_program(instruction* code){
    // code implementation
}

void print_input_list(instruction* code){
    // code implementation
}
