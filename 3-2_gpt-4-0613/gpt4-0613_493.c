#include<stdio.h>
#include <stdlib.h>

typedef struct instruction{
    int op; //opcode
    int  l; // L
    int  m; // M
} instr;

FILE * ifp; //input file pointer
FILE * ofp; //output file pointer
instr code[501]; // Define the array with the correct "instr" type

// Function prototype changes: No need to return the array, pass the size of the array as an argument
void read_file(instr code[], int size);
char* lookup_OP(int OP);
void print_program(instr code[], int size);
void print_input_list(instr code[], int size);

int main(){
    // Assume the size of the array is 501 (length of code[])
    read_file(code, 501);
    print_input_list(code, 501); //used for debugging
    print_program(code, 501);
    return 0; // Don't forget to return a value from main()
}

void read_file(instr code[], int size){
    int i = 0;

    ifp = fopen("input.txt", "r");

    if(ifp == NULL) {
        printf("Failed to open the file\n");
        return;
    }

    while(i < size && fscanf(ifp,"%d%d%d",&code[i].op, &code[i].l, &code[i].m) == 3 ) {

        i++;
    }
    if(i < size) {
        code[i].op = -1; //identifies the end of the code in the array
    }
    fclose(ifp);
}
