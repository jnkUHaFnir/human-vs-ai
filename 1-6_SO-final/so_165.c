    tab1 = (float**)malloc(m * sizeof(float*));
    for (int i = 0; i < m; i++)
    {
        tab1[i] = (float*)malloc(n * sizeof(float));
    }