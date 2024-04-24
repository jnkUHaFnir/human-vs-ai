void read_file(int *sk, sask mas[]){
    FILE *data = fopen("data.txt", "r");

    if (data != NULL){
        fscanf(data, "%d", sk);
        printf("%d", *sk);

        // Allocate memory for the mas array
        mas = malloc(*sk * sizeof(sask));

        for(int i = 0; i < *sk; i++){
            fscanf(data, "%s%s%d%lf%s", mas[i].vard, mas[i].pav, &mas[i].num, &mas[i].suma, mas[i].val);
        }
    }
    fclose(data);
}
int sk;
sask *mas = NULL;
read_file(&sk, mas);
