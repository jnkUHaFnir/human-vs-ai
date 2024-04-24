#include <stdio.h>
#include <stdlib.h>

typedef struct instruction {
    int op; //opcode
    int l; // L
    int m; // M
} instruction;

instruction* read_file(instruction[]);
char *lookup_OP(int OP);
void print_program(instruction[]);
void print_input_list(instruction[]);

int main() {
    instruction code[501];
    instruction *result_code;
    
    result_code = read_file(code);
    print_input_list(result_code); //used for debugging
    print_program(result_code);
    
    return 0;
}

instruction* read_file(instruction code[]) {
    int i = 0;
    FILE *ifp = fopen("input.txt", "r");
    
    if (ifp == NULL) {
        fprintf(stderr, "Error opening file.\n");
        exit(1);
    }
    
    while (fscanf(ifp, "%d %d %d", &code[i].op, &code[i].l, &code[i].m) == 3) {
        i++;
    }
    code[i].op = -1; //identifies the end of the code in the array
    fclose(ifp);
    
    instruction *result_code = malloc((i + 1) * sizeof(instruction));
    if (result_code == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    
    for (int j = 0; j <= i; j++) {
        result_code[j] = code[j];
    }
    
    return result_code;
}
