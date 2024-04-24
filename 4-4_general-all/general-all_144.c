void read_file(int *sk, sask **mas) {
    FILE *data = fopen("data.txt", "r");

    if (data != NULL) {
        fscanf(data, "%d", sk);
        printf("%d\n", *sk);

        *mas = (sask*)realloc(*mas, *sk * sizeof(sask));
        if (*mas == NULL) {
            // Handle allocation failure
            fprintf(stderr, "Memory allocation failed.\n");
            fclose(data);
            return;
        }

        for(int i = 0; i < *sk; i++) {
            fscanf(data, "%s %s %d %lf %s", (*mas)[i].vard, (*mas)[i].pav, &(*mas)[i].num, &(*mas)[i].suma, (*mas)[i].val);
        }
    }

    fclose(data);
}
int sk;
sask* mas = NULL;
read_file(&sk, &mas);
