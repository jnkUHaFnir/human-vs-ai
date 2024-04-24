#include <stdio.h>

#define MAX_CODES 501

typedef struct {
    int op; // Opcode
    int l;  // L
    int m;  // M
} instruction;

instruction code[MAX_CODES];

instruction* read_file(instruction code[]);
const char* lookup_OP(int OP);
void print_program(instruction code[]);
void print_input_list(instruction code[]);

int main() {
    read_file(code);
    print_input_list(code);  // Used for debugging
    print_program(code);
}

instruction* read_file(instruction code[]) {
    int i = 0;

    FILE* ifp = fopen("input.txt", "r");
    if (ifp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    while (fscanf(ifp, "%d %d %d", &code[i].op, &code[i].l, &code[i].m) == 3) {
        i++;
        if (i >= MAX_CODES) {
            fprintf(stderr, "Exceeded maximum number of instructions\n");
            break;
        }
    }

    code[i].op = -1; // Identifies the end of the code in the array
    fclose(ifp);
    return code;
}
