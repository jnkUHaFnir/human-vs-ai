#include<stdio.h>
#include<stdlib.h>

typedef struct instruction {
    int op; //opcode
    int l;  // L
    int m;  // M
} instr;

#define MAX_CODE_LENGTH 501

instr code[MAX_CODE_LENGTH];

void read_file(instr code[]);
char* lookup_OP(int OP);
void print_program(const instr code[]);
void print_input_list(const instr code[]);


int main() {
    read_file(code); // no need to assign, as code is altered directly
    print_input_list(code); //used for debugging
    print_program(code);
}

void read_file(instr code[]) {
    int i = 0;

    FILE *ifp = fopen("input.txt", "r");

    if (ifp == NULL) {
        fprintf(stderr, "Error opening file.\n");
        exit(1);
    }

    while(fscanf(ifp,"%d %d %d",&code[i].op, &code[i].l, &code[i].m) == 3 && i < MAX_CODE_LENGTH - 1) {
        i++;
    }
    code[i].op = -1; // identifies the end of the code in the array

    fclose(ifp);
}

void print_input_list(const instr code[]) {
    // Your implementation
}

void print_program(const instr code[]) {
    // Your implementation
}

char* lookup_OP(int OP) {
   // Your implementation
   return NULL;
}
