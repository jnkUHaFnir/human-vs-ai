    sask *read_file(const char *file, int *sk)
    {
        FILE *data = fopen(file, "r");
        *sk = 0;
    
        if (data == NULL)
            return 0;
    
        if (fscanf(data, "%d", sk) != 1)
        {
            fclose(data);
            return 0;
        }
    
        printf("file %s: records = %d\n", file, *sk);
    
        sask *mas = malloc(*sk * sizeof(*mas));
    
        for (int i = 0; i < *sk; i++)
        {
            if (fscanf(data, "%s%s%d%lf%s", mas[i].vard, mas[i].pav,
                       &mas[i].num, &mas[i].suma, mas[i].val) != 5)
            {
                *sk = 1;
                break;
            }
            printf("%d: %s %s %d %f %s\n", i, mas[i].vard, mas[i].pav,
                   &mas[i].num, &mas[i].suma, mas[i].val);
        }
        fclose(data);
        return mas;
    }