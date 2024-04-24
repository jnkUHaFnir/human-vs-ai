#include<stdio.h>
#include <stdlib.h>

typedef struct instruction{
    int op; //opcode
    int  l; // L
    int  m; // M
} instr;

FILE * ifp; //input file pointer
FILE * ofp; //output file pointer
instr code[501];

instr* read_file(instr code[]);
char* lookup_OP(int OP);
void print_program(instr code[]);
void print_input_list(instr code[]);


int main(){

    instr* p = read_file(code);
    print_input_list(p);//used for debugging
    print_program(p);
}

instr* read_file(instr code[]){
    int i = 0;

    ifp = fopen("input.txt", "r");

    while(!feof(ifp)){
        fscanf(ifp,"%d%d%d",&code[i].op, &code[i].l, &code[i].m);
        i++;
    }
    code[i].op = -1; //identifies the end of the code in the array
    fclose(ifp);
    return code;
}
