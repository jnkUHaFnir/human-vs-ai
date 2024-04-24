instruction[] read_file(instruction[]);
instruction[] read_file(instruction code[]){
    int i = 0;

    ifp = fopen("input.txt", "r");

    while(!feof(ifp)){
        fscanf(ifp, "%d%d%d", &code[i].op, &code[i].l, &code[i].m);
        i++;
    }
    code[i].op = -1; //identifies the end of the code in the array
    fclose(ifp);
    return code;
}
