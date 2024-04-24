instruction* read_file(instruction* code);
void print_program(instruction* code);
void print_input_list(instruction* code);
instruction* read_file(instruction* code){
    int i = 0;

    ifp = fopen("input.txt", "r");

    while(fscanf(ifp, "%d %d %d", &code[i].op, &code[i].l, &code[i].m) != EOF){
        i++;
    }
    code[i].op = -1; //identifies the end of the code in the array
    fclose(ifp);
    return code;
}
